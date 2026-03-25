#define _CRT_SECURE_NO_WARNINGS
#include <pqxx/pqxx>
#include <pqxx/params.hxx>
#include <nlohmann/json.hpp>

#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <cmath>
#include <atomic>
#include <limits>

#include "lander_math.h"

using json = nlohmann::json;
using namespace std;

static string get_conn_string() {
    return "postgresql://postgres.xqyehunribvhmrzfykku:FalconWessel1369!@aws-0-us-west-2.pooler.supabase.com:5432/postgres";
}

struct Job {
    int id = -1;
    string task_name;
    json payload;
};

//db queue helpers
static bool claim_next_job(pqxx::connection& c, const string& worker_id, Job& out_job) {
    pqxx::work tx(c);

    pqxx::result r = tx.exec(
        "SELECT id, task_name, payload "
        "FROM public.control_queue "
        "WHERE status = 'pending' "
        "ORDER BY priority ASC, created_at ASC, id ASC "
        "FOR UPDATE SKIP LOCKED "
        "LIMIT 1;"
    );

    if (r.empty()) {
        tx.commit();
        return false;
    }

    out_job.id = r[0]["id"].as<int>();
    out_job.task_name = r[0]["task_name"].c_str();

    if (r[0]["payload"].is_null()) out_job.payload = json::object();
    else out_job.payload = json::parse(r[0]["payload"].c_str());

    tx.exec(
        "UPDATE public.control_queue "
        "SET status='running', locked_at=now(), locked_by=$1, attempts=attempts+1 "
        "WHERE id=$2;",
        pqxx::params{ worker_id, out_job.id }
    );

    tx.commit();
    return true;
}

static void complete_job(pqxx::connection& c, int job_id) {
    pqxx::work tx(c);
    tx.exec(
        "UPDATE public.control_queue "
        "SET status='complete', error=NULL "
        "WHERE id=$1;",
        pqxx::params{ job_id }
    );
    tx.commit();
}

static void fail_job(pqxx::connection& c, int job_id, const string& err) {
    pqxx::work tx(c);
    tx.exec(
        "UPDATE public.control_queue "
        "SET status='failed', error=$2 "
        "WHERE id=$1;",
        pqxx::params{ job_id, err }
    );
    tx.commit();
}

static void touch_knowledge_source(pqxx::connection& c, const string& ks_name) {
    pqxx::work tx(c);
    tx.exec(
        "UPDATE public.knowledge_sources "
        "SET last_run = now() "
        "WHERE name = $1;",
        pqxx::params{ ks_name }
    );
    tx.commit();
}

static void enqueue_job(pqxx::connection& c, const string& task_name, int priority, const json& payload) {
    pqxx::work tx(c);
    tx.exec(
        "INSERT INTO public.control_queue (task_name, priority, status, payload) "
        "VALUES ($1, $2, 'pending', $3::jsonb);",
        pqxx::params{ task_name, priority, payload.dump() }
    );
    tx.commit();
}

static string read_blackboard_state_raw(pqxx::connection& c, const string& state_key) {
    pqxx::work tx(c);
    pqxx::result r = tx.exec(
        "SELECT state_value::text "
        "FROM public.blackboard_state "
        "WHERE state_key = $1 "
        "LIMIT 1;",
        pqxx::params{ state_key }
    );
    tx.commit();

    if (r.empty()) throw runtime_error("No row found for state_key='" + state_key + "'");
    return r[0][0].c_str();
}

static json read_blackboard_state(pqxx::connection& c, const string& state_key) {
    return json::parse(read_blackboard_state_raw(c, state_key));
}

static void write_blackboard_state(pqxx::connection& c, const string& state_key, const json& j) {
    pqxx::work tx(c);
    tx.exec(
        "UPDATE public.blackboard_state "
        "SET state_value = $1::jsonb, last_updated = now() "
        "WHERE state_key = $2;",
        pqxx::params{ j.dump(), state_key }
    );
    tx.commit();
}

//Velcoity helpers

static double signed_velocity_from_state(double vel_mag, const std::string& dir) {
    if (dir == "up") return -std::abs(vel_mag);
    return std::abs(vel_mag);
}

static std::string dir_from_signed_velocity(double v_signed) {
    return (v_signed < 0) ? "up" : "down";
}

/*
eta for ticks
if falling eta = (alt /(vel*dt)) with some safeguards*/
static int estimate_eta_ticks(double altitude, double vel_mag, const std::string& vel_dir, int dt) {
    if (altitude <= 0) return 0;
    if (dt <= 0) dt = 1;

    if (vel_dir != "down") return -1;               // going up: unknown (will arc)
    if (vel_mag < 1e-6) return -1;                  // too small: unknown

    double ticks = altitude / (vel_mag * dt);
    if (ticks < 0) return -1;

    int eta = (int)std::ceil(ticks);
    if (eta < 1) eta = 1;
    if (eta > 999999) eta = 999999;
    return eta;
}


/*
Runs simulate_tick from knowledge source, which:
computes and stores new altitude, velocity, fuel, burn time, and status based on physics and current state.
*/
static void run_simulate_tick(pqxx::connection& c, const json& payload) {
    const int LANDER_DRY_MASS = 1500;
    const int FUEL_BURN_PER_TICK = 1;

    string state_key = payload.value("state_key", string("lunar_state"));

    //One transaction for the whole tick: read -> compute -> write -> enqueue
    pqxx::work tx(c);

    pqxx::result r = tx.exec(
        "SELECT state_value::text "
        "FROM public.blackboard_state "
        "WHERE state_key = $1 "
        "FOR UPDATE;",
        pqxx::params{ state_key }
    );

    if (r.empty()) {
        tx.commit();
        return;
    }

    json j = json::parse(r[0][0].c_str());

    int dt = j.value("dt", 1);
    double altitude_val = j.value("altitude", 0.0);

    double velocity_mag = j.value("velocity", 0.0);
    string velocity_dir = j.value("velocity_dir", string("down"));
    double velocity_signed = signed_velocity_from_state(velocity_mag, velocity_dir);

    int fuel_remaining = j.value("fuel_remaining", 0);
    int thrust_up = j.value("thrust", 0);
    int burn_left = j.value("burn_ticks_remaining", 0);

    string status = j.value("status", string("idle"));
    bool running = j.value("running", false);

    if (status == "landed" || status == "crashed" || status == "complete") {
        tx.commit();
        return;
    }

    if (!running || status == "idle") {
        tx.commit();
        return;
    }

    int effective_thrust_up = (burn_left > 0 && fuel_remaining > 0) ? thrust_up : 0;

    double g_raw = moonAcceleration((int)altitude_val);
    double g_mag = std::abs(g_raw);

    int total_mass = LANDER_DRY_MASS + fuel_remaining;

    int fuel_burned = (fuel_remaining > 0 && effective_thrust_up > 0) ? (FUEL_BURN_PER_TICK * dt) : 0;
    if (fuel_burned > fuel_remaining) fuel_burned = fuel_remaining;

    double a = 0.0;
    if (effective_thrust_up <= 0) {
        a = g_mag;
    }
    else {
        a = netAcceleration(effective_thrust_up, g_raw, total_mass, fuel_burned);
    }

    double new_velocity_signed = velocity(velocity_signed, a, dt);
    double new_altitude = altitude((int)altitude_val, velocity_signed, a, dt);
    if (new_altitude < 0) new_altitude = 0;

    int new_fuel = fuelRemaining(fuel_remaining, fuel_burned);

    int new_burn_left = burn_left;
    if (burn_left > 0 && fuel_remaining > 0) new_burn_left = burn_left - 1;
    if (new_burn_left < 0) new_burn_left = 0;

    int new_thrust_up = thrust_up;
    if (new_burn_left == 0 || new_fuel <= 0) new_thrust_up = 0;

    string new_status = status;

    if (new_fuel <= 0 && new_altitude > 0) {
        new_status = "crashing";
        new_burn_left = 0;
        new_thrust_up = 0;
    }
    else if (new_burn_left == 0 && new_altitude > 0) {
        new_status = "landing";
    }
    else if (new_altitude > 0) {
        new_status = "flying";
    }

    double new_velocity_mag = std::abs(new_velocity_signed);
    string new_velocity_dir = dir_from_signed_velocity(new_velocity_signed);

    int eta = estimate_eta_ticks(new_altitude, new_velocity_mag, new_velocity_dir, dt);

    //Write back to JSON
    j["dt"] = dt;
    j["altitude"] = new_altitude;
    j["velocity"] = new_velocity_mag;
    j["velocity_dir"] = new_velocity_dir;
    j["fuel_remaining"] = new_fuel;
    j["thrust"] = new_thrust_up;
    j["burn_ticks_remaining"] = new_burn_left;
    j["status"] = new_status;
    j["running"] = running;
    j["eta_ticks"] = eta;

    //Update in same transaction
    tx.exec(
        "UPDATE public.blackboard_state "
        "SET state_value = $1::jsonb, last_updated = now() "
        "WHERE state_key = $2;",
        pqxx::params{ j.dump(), state_key }
    );

    //Enqueue check_terminal in same transaction
    tx.exec(
        "INSERT INTO public.control_queue (task_name, priority, status, payload) "
        "VALUES ('check_terminal', 1, 'pending', $1::jsonb);",
        pqxx::params{ payload.dump() }
    );

    tx.commit();

    cout << "[simulate_tick] alt=" << new_altitude
        << " vel=" << new_velocity_mag << "(" << new_velocity_dir << ")"
        << " fuel=" << new_fuel
        << " burn_left=" << new_burn_left
        << " eta_ticks=" << eta
        << " status=" << new_status
        << "\n";
}

/*
check_terminal from Knowledge Source: which checks if we have landed/crashed, updates status, and if still flying, queues another simulate_tick.
*/
static void run_check_terminal(pqxx::connection& c, const json& payload) {
    string state_key = payload.value("state_key", string("lunar_state"));
    json j = read_blackboard_state(c, state_key);

    double alt = j.value("altitude", 0.0);
    double vel = j.value("velocity", 0.0);
    string vel_dir = j.value("velocity_dir", string("down"));

    int fuel = j.value("fuel_remaining", 0);
    string status = j.value("status", string("idle"));
    bool running = j.value("running", false);

    //If already landed in some capcity, stop and don't queue more ticks
    if (status == "landed" || status == "crashed" || status == "complete") {
        j["running"] = false;
        write_blackboard_state(c, state_key, j);
        return;
    }

    if (alt <= 0.0) {
        if (status == "crashing" || fuel <= 0 || vel > 5.0) {
            j["status"] = "crashed";
        }
        else {
            j["status"] = "landed";
        }
        j["running"] = false;
        j["thrust"] = 0;
        j["burn_ticks_remaining"] = 0;
        j["eta_ticks"] = 0;

        write_blackboard_state(c, state_key, j);

        cout << "[flight] Finished: " << string(j["status"]) << "\n";
        cout << "Type: start | reset | quit\n";
        return;
    }

    if (fuel <= 0 && status != "crashing") {
        j["status"] = "crashing";
        j["thrust"] = 0;
        j["burn_ticks_remaining"] = 0;
        status = "crashing";
    }

    if (running) {
        enqueue_job(c, "simulate_tick", 1, payload);
    }

    // Save any adjustments
    write_blackboard_state(c, state_key, j);
}

/*
Commands for user input: start {n ticks}, reset, quit)
*/
static void print_commands() {
    cout << "Type: start | reset | quit\n";
}

static void command_loop(
    std::atomic<bool>& alive,
    std::atomic<bool>& startReq,
    std::atomic<int>& startBurnTicks,
    std::atomic<bool>& resetReq
) {
    print_commands();

    while (alive.load()) {
        string cmd;
        if (!getline(cin, cmd)) break;

        if (cmd == "quit" || cmd == "exit") {
            alive.store(false);
            break;
        }
        else if (cmd == "reset") {
            resetReq.store(true);
        }
        else if (cmd == "start") {
            cout << "How many ticks to fire thrusters? ";
            string nstr;
            if (!getline(cin, nstr)) {
                alive.store(false);
                break;
            }

            int n = 0;
            try { n = stoi(nstr); }
            catch (...) {
                cout << "Invalid number.\n";
                continue;
            }

            if (n < 0) n = 0;
            startBurnTicks.store(n);
            startReq.store(true);
        }
        else {
            cout << "Unknown command.\n";
            print_commands();
        }
    }
}

static constexpr double STARTING_ALTITUDE = 0.1;  // just above ground (m)

static void apply_commands(
    pqxx::connection& c,
    std::atomic<bool>& startReq,
    std::atomic<int>& startBurnTicks,
    std::atomic<bool>& resetReq
) {
    const string KEY = "lunar_state";

    if (resetReq.exchange(false)) {
        json j;
        j["dt"] = 1;
        j["status"] = "idle";
        j["running"] = false;
        j["thrust"] = 0;
        j["burn_ticks_remaining"] = 0;
        j["eta_ticks"] = -1;

        //Reset to a known start above the ground
        j["altitude"] = STARTING_ALTITUDE;

        j["velocity"] = 0.0;
        j["velocity_dir"] = "down";

        //Default fuel for testing
        j["fuel_remaining"] = 10;

        write_blackboard_state(c, KEY, j);
        cout << "[cmd] reset done\n";
        print_commands();
    }

    if (startReq.exchange(false)) {
        int requested_burn = startBurnTicks.exchange(0);

        json j = read_blackboard_state(c, KEY);

        //If we are at ground or terminal, auto lift back to a start state so it doesn't instantly land
        string status = j.value("status", string("idle"));
        double alt = j.value("altitude", 0.1);

        if (alt <= 0.0 || status == "landed" || status == "crashed" || status == "complete") {
            j["altitude"] = STARTING_ALTITUDE;
            j["velocity"] = 0.0;
            j["velocity_dir"] = "down";
            j["status"] = "idle";
        }

        int fuel = j.value("fuel_remaining", 0);

        int burn_ticks = requested_burn;
        if (burn_ticks > fuel) burn_ticks = fuel;

        int thrust = j.value("thrust", 0);
        if (thrust <= 0) thrust = 150;

        j["thrust"] = thrust;
        j["burn_ticks_remaining"] = burn_ticks;
        j["running"] = true;
        j["status"] = "flying";
        j["eta_ticks"] = -1;

        if (!j.contains("velocity_dir")) j["velocity_dir"] = "down";
        j["velocity"] = std::abs(j.value("velocity", 0.0));

        write_blackboard_state(c, KEY, j);

        enqueue_job(c, "simulate_tick", 1, json::object({ {"state_key", KEY} }));

        if (requested_burn > burn_ticks) {
            cout << "[cmd] start -> thrust=" << thrust
                << " burn_ticks=" << burn_ticks
                << " (capped by fuel=" << fuel << ") (kickoff tick queued)\n";
        }
        else {
            cout << "[cmd] start -> thrust=" << thrust
                << " burn_ticks=" << burn_ticks
                << " (kickoff tick queued)\n";
        }
    }
}


int main() {
    try {
        pqxx::connection c(get_conn_string());
        cout << "Connected to Postgres!\n";

        std::atomic<bool> alive(true);
        std::atomic<bool> startReq(false), resetReq(false);
        std::atomic<int> startBurnTicks(0);

        std::thread cmd_thread(
            command_loop,
            std::ref(alive),
            std::ref(startReq),
            std::ref(startBurnTicks),
            std::ref(resetReq)
        );

        const int LOOP_MS = 5;
        const string worker_id = "lander_worker_1";

        while (alive.load()) {
            apply_commands(c, startReq, startBurnTicks, resetReq);

            Job job;
            bool got = claim_next_job(c, worker_id, job);

            if (!got) {
                this_thread::sleep_for(chrono::milliseconds(LOOP_MS));
                continue;
            }

            try {
                if (job.task_name == "simulate_tick") {
                    run_simulate_tick(c, job.payload);
                    touch_knowledge_source(c, "simulate_tick");
                }
                else if (job.task_name == "check_terminal") {
                    run_check_terminal(c, job.payload);
                    touch_knowledge_source(c, "check_terminal");
                }
                else {
                    throw runtime_error("Unknown task_name: " + job.task_name);
                }

                complete_job(c, job.id);
            }
            catch (const std::exception& e) {
                cerr << "[JOB FAILED] id=" << job.id << " task=" << job.task_name
                    << " err=" << e.what() << "\n";
                fail_job(c, job.id, e.what());
            }
        }

        if (cmd_thread.joinable()) cmd_thread.join();
        return 0;

    }
    catch (const exception& e) {
        cerr << "FATAL ERROR: " << e.what() << "\n";
        return 1;
    }
}