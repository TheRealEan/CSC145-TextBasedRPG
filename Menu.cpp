// Filename: "Menu.cpp"
#include "Menu.h"
using namespace std;

void Menu::mainMenu() {
    cout << "1. Return to Game" << endl
        << "2. Enter Battle" << endl
        << "3. Manage Inventory" << endl
        << "4. Enter Shop" << endl
        << "5. Talk to Someone" << endl
        << "6. Quit Game" << endl;
    int choice;
    cin >> choice;
    switch (choice) {
    case 1:
        returnToOverworld();
        break;

    case 2:
        enterBattle();
        break;

    case 3:
        manageInventory();
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
        mainMenu();
        break;
    }
}

void Menu::returnToOverworld() {
    cout << "Return to overworld." << endl;
    mainMenu();
}

void Menu::enterBattle() {
    cout << "You have entered battle." << endl;
    mainMenu();
}

void Menu::manageInventory() {
    cout << "You are managing your inventory." << endl;
    mainMenu();
}

void Menu::enterShop() {
    cout << "You entered the shop." << endl;
    mainMenu();
}

void Menu::chat() {
    cout << "You're chatting." << endl;
    mainMenu();
}

int Menu::quitGame() {
    cout << "You're quitting the game." << endl;
    return 0;
}