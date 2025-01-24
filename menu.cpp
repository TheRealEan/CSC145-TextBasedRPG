#include"menu.h"

using namespace std;

//Definitions of prototyped functions
void menu::mainMenu() {
    cout << "1.Return to Game \n2.Enter Battle \n3.Manage Inventory";
    cout << "\n4.Enter Shop \n5.Talk to Someone \n6.Quit Game\n";
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
        cout << "That's not a valid option";
        mainMenu();
        break;
    }
}

void menu::returnToOverworld() {
    cout << "Return to overworld\n";
    mainMenu();
}

void menu::enterBattle() {
    cout << "You have entered battle.\n";
    mainMenu();
}

void menu::manageInventory() {
    cout << "You are managing your inventory.\n";
    mainMenu();
}

void menu::enterShop() {
    cout << "You entered the shop\n";
    mainMenu();
}

void menu::chat() {
    cout << "You're chatting\n";
    mainMenu();
}

int menu::quitGame() {
    cout << "You're quitting the game\n";
    return 0;
}