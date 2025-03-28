// Filename: "Menu.cpp"
#include <iostream>
#include <cstdlib>
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "Menu.h"
#include "Extra.h"
#include <Windows.h>
#include <mmsystem.h>
#include <thread>
#pragma comment(lib, "winmm.lib")

using namespace std;

atomic<bool> running(true);
bool battle = false;
bool inven = false;

void Menu::clear() {
#ifdef _WIN32
    system("cls");
#endif
}

void backgroundPlay() {
    if (battle == true) {
        PlaySound(TEXT("battle.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    }
    else if (inven == true) {
        PlaySound(TEXT("inventory.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    }
    else {
        PlaySound(TEXT("theme.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    }
}
/*
void selectPlay() {
    PlaySound(TEXT("select.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

void selectCheck() {
    while (running) {
        for (int key = 8; key <= 256; key++) {
            if (GetAsyncKeyState(key) & 0x8000) { 
                selectPlay();
                Sleep(100);  
                backgroundPlay();
            }
        }
        Sleep(10); 
    }
}



*/

MainMenu::MainMenu(Player& player) {
    //thread selectChecker(selectCheck);
    thread backgroundChecker(backgroundPlay);
    //selectChecker.detach();
    backgroundChecker.detach();
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
        battle = true;
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
    battle = false;
}

void MainMenu::manageInventory(Player& player) {
    PlaySound(TEXT("item2.wav"), NULL, SND_FILENAME | SND_ASYNC);
    Sleep(1500);
    inven = true;
    backgroundPlay();
    int choice;
    string itemName;

    do {
        string tempS;
        int tempN;
        cout << "\n\033[1;33m=== Inventory Menu ===\033[1;33m\n";
        cout << "Gold: " << player.getGold() << endl;
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
            PlaySound(TEXT("textPopUp.wav"), NULL, SND_FILENAME | SND_ASYNC);
            Sleep(1500);
            backgroundPlay();
            break;
        case 2:
            cout << "Enter an item you want to remove: ";
            getline(std::cin, itemName);
            player.removeItemFromInventory(itemName);
            PlaySound(TEXT("unequip.wav"), NULL, SND_FILENAME | SND_ASYNC);
            Sleep(1500);
            backgroundPlay();
            break;
        case 3:
            cout << "Exiting inventory.\n";
            break;
        case 5:
            cout << "Enter an item to add.\n";
            getline(cin, tempS);
            cout << "Enter how many you want to add.\n";
            cin >> tempN;
            player.addItemToInventory(new Item(tempS, tempN, 50), true); // 50 gold placeholder
            cout << "Added " << tempS << " " << tempN << "x";
            PlaySound(TEXT("coinGain.wav"), NULL, SND_FILENAME | SND_ASYNC);
            Sleep(1500);
            backgroundPlay();
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
    exit(0);
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

void checkForItems(Player& player) {
    if (player.findItem("Sword") != nullptr) {  //ONLY checks if is in inventory
        player.setStrength(player.getStrength() + 10);
    }
    if (player.findItem("Boots") != nullptr) {  //ONLY checks if is in inventory
        player.setArmor(player.getArmor() + 10);
    }
}

void startBattle(Player& player) {
    backgroundPlay();
    bool endBattle = false;
    Character* enemy = generateRandomEnemy();
    checkForItems(player); // runs once at the beginning of the battle sequence
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
            player.pickBattleDialogue(1);
            Sleep(70);
            PlaySound(TEXT("attack1.wav"), NULL, SND_FILENAME | SND_ASYNC);
            Sleep(1000);
            backgroundPlay();
            break;
        case 2:
            player.defend();
            player.pickBattleDialogue(2);
            Sleep(70);
            PlaySound(TEXT("defeat.wav"), NULL, SND_FILENAME | SND_ASYNC);
            Sleep(1000);
            backgroundPlay();
            break;
        case 3:
            player.run();
            player.pickBattleDialogue(3);
            Sleep(70);
            PlaySound(TEXT("run.wav"), NULL, SND_FILENAME | SND_ASYNC);
            Sleep(1000);
            backgroundPlay();
            endBattle = true;
            break;
        }
        // enemy turn
        cout << endl;
        srand(static_cast<unsigned int>(time(0))); // Seeds using the current time.
        unsigned int roll = (1 + rand() % 3); // Generates a number from 1 to 3.

        // Determines which options is chosen.
        switch (roll) {
        case 1:
            enemy->attack(&player);
            enemy->pickBattleDialogue(1);
            PlaySound(TEXT("hurt4.wav"), NULL, SND_FILENAME | SND_ASYNC);
            Sleep(1000);
            backgroundPlay();
            break;
        case 2:
            enemy->defend();
            enemy->pickBattleDialogue(2);
            PlaySound(TEXT("troll.wav"), NULL, SND_FILENAME | SND_ASYNC);
            Sleep(1000);
            backgroundPlay();
            break;
        case 3:
            enemy->run();
            enemy->pickBattleDialogue(3);
            PlaySound(TEXT("run.wav"), NULL, SND_FILENAME | SND_ASYNC);
            Sleep(1000);
            backgroundPlay();
            endBattle = true;
            break;
        }
        cout << "\n------------------------------------------\n";
        if (enemy->getHealth() <= 0) {
            cout << enemy->getName() << " has been defeated!!" << endl;
            cout << "\033[0;32m";
            if (enemy->getName() == "Chinese Spy Pigeon") {
                int random = 1 + rand() % 100;
                if (random > 66) {
                    int random2 = rand() % 5 + 1;
                    player.addItemToInventory(new Item("Camera", random2, 80), true);
                    cout << enemy->getName() << " dropped " << random2 << "x Cameras!\n";
                }
                else if (random > 33) {
                    int random2 = rand() % 30 + 1;
                    player.addItemToInventory(new Item("Feather", random2, 5), true);
                    cout << enemy->getName() << " dropped " << random2 << "x Feathers!\n";
                }

            }
            
            if (enemy->getName() == "Danny Devito") {
                cout << "\033[0;32m";
                int random = rand() % 100 + 1;
                if (random > 90) {
                    int random2 = rand() % 1 + 1;
                    player.addItemToInventory(new Item("Space Jam DvD", random2, 999), true);
                    cout << enemy->getName() << " dropped " << random2 << "x Space Jam DvDs!\n";
                }
                random = rand() % 100 + 1;
                if (random > 90) {
                    int random2 = rand() % 1 + 1;
                    player.addItemToInventory(new Item("The Lorax DvD", random2, 999), true);
                    cout << enemy->getName() << " dropped " << random2 << "x Lorax Dvds!\n";
                }
                random = rand() % 100 + 1;
                if (random > 90) {
                    int random2 = rand() % 1 + 1;
                    player.addItemToInventory(new Item("Batman Returns DvD", random2, 999), true);
                    cout << enemy->getName() << " dropped " << random2 << "x Batman Returns Dvds!\n";
                }
            }
            if (enemy->getName() == "Roomba") {
                cout << "\033[0;32m";
                cout << "yass\n";
            }
            cout << enemy->getName() << " dropped " << enemy->getGold() << " gold" << endl;
            player.collect(enemy->getGold());
            cout << "\033[1;33m";
            PlaySound(TEXT("victory.wav"), NULL, SND_FILENAME | SND_ASYNC);
            cout << "Press any key to continue..." << endl;
            endBattle = true;
            cin.ignore();
            cin.get();
        }
        if (player.getHealth() <= 0) {
            cout << "You died.";
            PlaySound(TEXT("loss.wav"), NULL, SND_FILENAME | SND_ASYNC);
            Sleep(1500);

            endBattle = true;
        }
    }
    delete enemy;
}





