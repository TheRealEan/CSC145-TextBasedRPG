// Filename: "Menu.cpp"
#include <iostream>
#include <cstdlib>
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "Menu.h"
#include "Extra.h"
#include "TalkingNPC.h"
#include "DialogueNode.h"
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
    // ----------- NPC #1 ----------- //
    talkingNPC* npc = new talkingNPC("Hermit", 8); //eight node of dialogue, first the inital 0 and then 1, 2, and 3, then three for one (4,5,6) and two for 2 (7,8)
    vector<int> next = { 1, 2, 3 };
    npc->setDialogue(0, new DialogueNode("Hello traveler. I see you are new here. I've lived alongside this road for many years and know much about its' inhabitants.", //this is dialogue 0
        "1: Tell me about the enemies I will encounter.\n2: Where can I buy equipment? \n3: I'm busy, go away.",
        next));

    vector<int> next1 = { 4,5,6 };
    npc->setDialogue(1, new DialogueNode("There are three monsters you will have to fight: the Roomba, the Chinese Spy Pigeon, and Danny Devito.", //this is dialgoue 1
        "1: Tell me about the Roomba.\n2: Tell me about the Chinese Spy Pigeon. \n3: Tell me about Danny Devito",
        next1));

    vector<int> next2 = { 7,8 };
    npc->setDialogue(2, new DialogueNode("What are you looking for, armor or weapons?", //this is dialgoue 2
        "1: Armor\n2: Weapons.",
        next2));

    vector<int> next3 = {};
    npc->setDialogue(3, new DialogueNode("Have a blessed day traveller", //this is dialgoue 3
        "Press any key to continue...",
        next3));
    vector<int> next4 = {};
    npc->setDialogue(4, new DialogueNode("The Roomba can be easily trampled underfoot.", //this is dialgoue 4
        "Press any key to continue...",
        next4));
    vector<int> next5 = {};
    npc->setDialogue(5, new DialogueNode("The Chinese Spy Pigeon can be defeated if you sever its radio connection.", //this is dialgoue 5
        "Press any key to continue...",
        next5));
    vector<int> next6 = {};
    npc->setDialogue(6, new DialogueNode("Danny Devito prefers to attack rather than defend.", //this is dialgoue 6
        "Press any key to continue...",
        next6));
    vector<int> next7 = {};
    npc->setDialogue(7, new DialogueNode("Go to town.There you will find an armor shop.Good luck in your travels!", //this is dialgoue 7
        "Press any key to continue...",
        next7));
    vector<int> next8 = {};
    npc->setDialogue(8, new DialogueNode("Go to town. There you will find a weapons shop. Good luck in your travels!", //this is dialgoue 8
        "Press any key to continue...",
        next8));

    npc->printDialogue(0);
    system("pause");

    clear();
    // ----------- NPC #2 ----------- //
    talkingNPC* npc2 = new talkingNPC("Wandering salesman", 8); //eight node of dialogue, first the inital 0 and then 1, 2, and 3, then three for one (4,5,6) and two for 2 (7,8)
    vector<int> next9 = { 1, 2, 3 };
    npc2->setDialogue(0, new DialogueNode("Hello traveler! Would you be interested in joining a pyramid scheme?", //this is dialogue 0
        "1: Tell me more.\n2: Isn't that illegal? \n3: STRANGER DANGER",
        next9));

    vector<int> next10 = { 4,5,6 };
    npc2->setDialogue(1, new DialogueNode("Well I will give you this very nice set of knives, and if you sell it to your family and friends, I will pay you a portion of the profit.", //this is dialgoue 1
        "1: That sounds great! Count me in! \n2: I don't know about this... \n3: This sounds like a scam, goodbye.",
        next10));

    vector<int> next11 = { 7,8 };
    npc2->setDialogue(2, new DialogueNode("Nooooooooo of course not...", //this is dialgoue 2
        "1: Walk away in disdain.\n2: Steal the knives.",
        next11));

    vector<int> next12 = {};
    npc2->setDialogue(3, new DialogueNode("Fine! Be that way.", //this is dialgoue 3
        "Press any key to continue...",
        next12));
    vector<int> next13 = {};
    npc2->setDialogue(4, new DialogueNode("Great! Sign right here!", //this is dialgoue 4
        "You are now involved in a pyramid scheme...\nPress any key to continue...",
        next13));
    vector<int> next14 = {};
    npc2->setDialogue(5, new DialogueNode("Oh come on! This is a completely foolproof business strategy!", //this is dialgoue 5
        "You walk away from the trap...\nPress any key to continue...",
        next14));
    vector<int> next15 = {};
    npc2->setDialogue(6, new DialogueNode("But you can save up for college!!", //this is dialgoue 6
        "You ignore the crazy salesman and walk away...\nPress any key to continue...",
        next15));
    vector<int> next16 = {};
    npc2->setDialogue(7, new DialogueNode("Hey don't leave! I promise you'll make money!", //this is dialgoue 7
        "You back away slowly...\nPress any key to continue...",
        next16));
    vector<int> next17 = {};
    npc2->setDialogue(8, new DialogueNode("HEY! Those are mine!!", //this is dialgoue 8
        "You are now on the run...\nPress any key to continue...",
        next17));

    npc2->printDialogue(0);
    system("pause");

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





