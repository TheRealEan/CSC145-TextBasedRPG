// Filename: "Menu.cpp"
#include <iostream>
#include <cstdlib>
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "Menu.h"
#include "Extra.h"
using namespace std;

void Menu::clear() {
#ifdef _WIN32
    system("cls");
#endif
}

MainMenu::MainMenu(Player& player) {
    cout << "\033[1;33m1. Return to Game (it's very late at night plz don't touch :(  \033[1;33m)" << endl
        << "2. Enter Battle" << endl
        << "3. Manage Inventory" << endl
        << "4. Enter Shop (it's very late at night plz don't touch :(  )" << endl
        << "5. Talk to Someone (it's very late at night plz don't touch :(  )" << endl
        << "6. Quit Game (it's very late at night plz don't touch :(  )" << endl;
    int choice;
    cin >> choice;
    switch (choice) {
    case 1:
        returnToOverworld();
        break;

    case 2:
        enterBattle(player);
        break;

    case 3:
        manageInventory(player);
        break;

    case 4:
        enterShop();
        break;

    case 5:
        chat();
        break;

    case 6:
        quitGame();
        break;

    default:
        cout << "That's not a valid option. Please type one of the options listed." << endl;
        break;
    }
}

void MainMenu::returnToOverworld() {
    clear();
    cout << "Returning to overworld." << endl;
}

void MainMenu::enterBattle(Player& player) {
    clear();
    cout << "You have entered battle." << endl;
    startBattle(player); 
}

void MainMenu::manageInventory(Player& player) {
    clear();
    int choice;
    string itemName;

    do {
        string tempS;
        int tempN;
        cout << "\n\033[1;33m=== Inventory Menu ===\033[1;33m\n";
        cout << "1. View Inventory\n";
        cout << "2. Remove Item\n";
        cout << "3. Exit\n";
        cout << "5. Add Item(debugging only)\n";
        cout << "==================\n";
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            player.displayInventory();
            break;
        case 2:
            cout << "Enter an item you want to remove: ";
            getline(std::cin, itemName);
            player.removeItemFromInventory(itemName);
            break;
        case 3:
            cout << "Exiting inventory.\n";
            break;
        case 5:
            cout << "Enter an item to add.\n";
            getline(cin, tempS);
            cout << "Enter how many you want to add.\n";
            cin >> tempN;
            player.addItemToInventory(new Item(tempS, tempN));
            cout << "Added " << tempS << " " << tempN << "x";
            break;
        default:
            cout << "Try again. >:(\n";
        }
    } while (choice != 3);
}


void MainMenu::enterShop() {
    clear();
    cout << "You entered the shop." << endl;
}

void MainMenu::chat() {
    clear();
    cout << "You're chatting." << endl;
}

int MainMenu::quitGame() {
    clear();
    cout << "You're quitting the game." << endl;
    return 0;
}

BattleMenu::BattleMenu() {
    clear();
    cout << "1. Attack" << endl
        << "2. Magic" << endl
        << "3. Actions" << endl
        << "4. Inventory" << endl
        << "5. Chat" << endl
        << "6. Flee" << endl;
    int choice;
    cin >> choice;
    switch (choice) {
    case 1:
        attack();
        break;

    case 2:
        magic();
        break;

    case 3:
        actions();
        break;

    case 4:
        inventory();
        break;

    case 5:
        chat();
        break;

    case 6:
        flee();
        break;

    default:
        cout << "That's not a valid option. Please type one of the options listed." << endl;
        BattleMenu();
        break;
    }
}

void BattleMenu::attack() {
    cout << "You attack." << endl;
    BattleMenu();
}

void BattleMenu::magic() {
    cout << "You magic." << endl;
    BattleMenu();
}

void BattleMenu::actions() {
    cout << "You actions." << endl;
    BattleMenu();
}

void BattleMenu::inventory() {
    cout << "You inventory." << endl;
    BattleMenu();
}

void BattleMenu::chat() {
    cout << "You chat." << endl;
    BattleMenu();
}

void BattleMenu::flee() {
    cout << "You flee." << endl;
    BattleMenu();
}

void startBattle(Player& player) {
    bool endBattle = false;
    Character* enemy = generateRandomEnemy();
    while (endBattle == false) {
        // player turn
        int choice = 0;
        cout << "\nHealth: " << player.getHealth();
        cout << "\nStamina: " << player.getStamina();
        cout << "\nMana: " << player.getMana();

        cout << "\n\nEnemy Health: " << enemy->getHealth();

        cout << "\n\nChoose your next move: ";
        cout << "\n1. Attack";
        cout << "\n2. Defend";
        cout << "\n3. Run\n";
        cin >> choice;
        switch (choice) {  // will need to add error handling here for invalid choices
        case 1:
            player.attack(enemy);
            cout << "You attacked!";
            break;
        case 2:
            player.defend();
            cout << "You defended!";
            break;
        case 3:
            player.run();
            cout << "You ran away.";
            endBattle = true;
            break;
        }
        // enemy turn
        srand(static_cast<unsigned int>(time(0))); // Seeds using the current time.
        unsigned int roll = (1 + rand() % 3); // Generates a number from 1 to 3.

        // Determines which options is chosen.
        switch (roll) {
        case 1:
            enemy->attack(&player);
            cout << enemy->getName() << " Attacks!";
            break;
        case 2:
            enemy->defend();
            cout << enemy->getName() << " Defends!";
            break;
        case 3:
            enemy->run();
            cout << enemy->getName() << " has been defeated!!";
            endBattle = true;
            break;
        }
        cout << "\n------------------------------------------\n";
        if (enemy->getHealth() <= 0) {
            cout << enemy->getName() << " has been defeated!!";
            endBattle = true;
        }
        if (player.getHealth() <= 0) {
            cout << "You died.";
            endBattle = true;
        }
    }
    delete enemy;
}


