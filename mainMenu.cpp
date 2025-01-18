#include<iostream>

using namespace std;

//Prototypes for all functions
void mainMenu();
void returnToOverworld();
void enterBattle();
void manageInventory();
void enterShop();
void chat();
int quitGame();

int main() {
    mainMenu();
}

//Definitions of prototyped functions
void mainMenu() {
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
        mainMenu;
        break;
    }
}

void returnToOverworld() {
    cout << "Return to overworld\n";
    mainMenu();
}

void enterBattle() {
    cout << "You have entered battle.\n";
    mainMenu();
}

void manageInventory() {
    cout << "You are managing your inventory.\n";
    mainMenu();
}

void enterShop() {
    cout << "You entered the shop\n";
    mainMenu();
}

void chat() {
    cout << "You're chatting\n";
    mainMenu();
}

int quitGame() {
    cout << "You're quitting the game\n";
    return 0;
}