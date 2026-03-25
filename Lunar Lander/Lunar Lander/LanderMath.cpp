// Lunar Landing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Lander_Math.h"
using namespace std;

/*
* t = time (seconds)
* a = total spacecraft acceleration
* v = spacecraft velocity
* h = height/altitude above moon surface
* f = fuel remaining
* m = mass
* w = weight
*
*
* universal gravitational constant (G) = 6.67430 x 10^-11 m^3 kg^-1 s^-2
* mass of moon (mMoon) = 7.34767309 x 10^22 kg
* radius of moon (rMoon) = 1740000 m
*
* thrust (T) =
* intial velocity (v0) =
* initial altitude (h0) =
* initial mass (m0) =
* initial weight (w0) =
* initial fuel (f0) =
* fuel consumption rate (r) =
*
* a = (T / m) - g = A - g
* v = v0 + at
* h = h0 + v0t + 0.5at^2
* w = mg
* f = f0 - rt
*
* gravitational acceleration on spacecraft due to moon (g) = (G * mMoon) / (rMoon + h)^2
*
* fuel remaining (f) = initial fuel (f0) - fuel consumption rate (r) * time (t)
*
* weight (w) = mass (m) * gravity (g)
* mass (m) = weight (w) / gravity (g)
*
* acceleration (a) = (thrust (T) / mass (m)) - gravity (g) = acceleration due to engines (A) - gravity (g)
*
* altitude (h) = initial altitude (h0) + initial velocity (v0) * time (t) + 0.5 * acceleration (a) * time^2 (t^2)
*
* velocity (v) = initial velocity (v0) + acceleration (a) * time (t)
*/

/*
* fuel remaining in spacecraft (kg)
* initial fuel - fuel consumption rate * time
* f = f0 - rt
* CHANGE TO NOT USE FUEL CONSUMPTION RATE
* DISCUSS THRUST VS NO THRUST SCENARIOS
*/
int fuelRemaining(int initialFuel, int fuelConsumed) {
	return initialFuel - fuelConsumed;
}

/*
* total mass of spacecraft and fuel (kg)
* mass of spacecraft + mass of remaining fuel
* m = m0 - (f0 - rt) = m0 - f
* ok to replace with fuel remaining function? is initial mass a parameter or a constant?
*/
int totalMass(int landerMass, int fuelRemainingMass) {
	return landerMass + fuelRemainingMass;
}

/*
* gravitational acceleration of spacecraft due to moon relative to altitude of spacecraft (m/s^2)
* (universal gravtiational constant * mass of moon) / (radius of moon + altitude of spacecraft)^2
* g = (G * mMoon) / (rMoon + h)^2
*/
double moonAcceleration(int landerHeight) {
	return (6.67430e-11 * 7.34767309e22) / pow((1740000 + landerHeight), 2);
}

/*
* weight of spacecraft / force of gravity on spacecraft (N)
* mass of spacecraft * gravity of moon on spacecraft
* w = mg
*/
double weight(int landerMass, double moonGravity) {
	return landerMass * moonGravity;
}

/*
* net force on spacecraft (N)
* force of thrust - weight = force of thrust - (total mass of lander and fuel * gravity of moon)
* NF = T - w = T - (mlander,t-1 * g)
* replace with weight?
*/
double netForce(int thrustForce, double moonGravity, int totalMass) {
	return thrustForce - (totalMass * moonGravity);
}

/*
* net average acceleration of spacecraft assuming a short-thrust duration (m/s^2)
* net force / total mass of spacecraft and fuel at time t = (force of thrust - weight) / mass of spacecraft and fuel at time t
* a = NF/m = (T - g * mlander,t-1)/(mlander,t-1 - (0.5)* mfuelused )
* replace with net force, weight?
*/
double netAcceleration(int thrustForce, double moonGravity, int totalMass, int fuelConsumedMass) {
	return (thrustForce - (moonGravity * totalMass)) / (totalMass - (0.5 * fuelConsumedMass));
}

/*
* current velocity of spacecraft assuming very simple average velocity model (m/s)
* (previous velocity) + (net average acceleration * change in time)
* v = v0 + at
* ok to replace with net acceleration? is time a parameter or a constant?
*/
double velocity(double previousVelocity, double acceleration, int time) {
	return previousVelocity + (acceleration * time);
}

/*
* current altitude of spacecraft (m)
* (previous altitude) - (previous velocity * change in time) - (0.5 * net average acceleration * change in time^2)
* h = h0 - v0t - 0.5at^2
*/
double altitude(int previousAltitude, double previousVelocity, double acceleration, int time) {
	return previousAltitude - (previousVelocity * time) - (0.5 * acceleration * pow(time, 2));
}

/*
int main()
{
	// known constants
	double G{ 6.67430e-11 }; // universal gravitational constant in m^3 kg^-1 s^-2
	double mMoon{ 7.34767309e22 }; // mass of moon in kg
	int rMoon{ 1740000 }; // radius of moon in m

	// initial values that are used in calculations and may be changed
	int thrust; // force of spacecraft engines in N
	int v0{ 0 }; // initial velocity of spacecraft in m/s
	int h0; // initial altitude of spacecraft in m
	int m0; // initial mass of spacecraft in kg
	int w0; // initial weight/gravitational force on spacecraft in N

	// changing values used in calculations
	int m; // mass of spacecraft at time t in kg
	int f0; // initial amount/mass of fuel of spacecraft in kg
	int r; // fuel consumption rate of spacecraft in kg (how much fuel is used per second)
	// screen display requirements
	int t{ 0 }; // time in seconds
	double w; // weight function
	int f; // fuel remaining function
	double h; // altitude in meters
	double v; // velocity function


}
*/

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file