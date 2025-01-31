#include "vector"

// Import Primary Classes
#include "BattleSequence.h"
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "Menu.h"
// Import Enemy Classes
#include "enemies/ChineseSpyPigeon.h"
#include "enemies/ChineseWeatherBalloon.h"
#include "enemies/DannyDevito.h"
#include "enemies/Drake.h"
#include "enemies/Goblin.h"
#include "enemies/Harpy.h"
#include "enemies/Hippie.h"
#include "enemies/Merfolk.h"
#include "enemies/Nickelback.h"
#include "enemies/Ninja.h"
#include "enemies/NotSoPeacefulProtestor.h"
#include "enemies/Orc.h"
#include "enemies/Pirate.h"
#include "enemies/Roomba.h"
#include "enemies/Samurai.h"
#include "enemies/Swiftie.h"
#include "enemies/TeaKettle.h"
#include "enemies/TrashCan.h"

using namespace std;

Enemy* generateRandomEnemy() {
    int num = rand() % 3 + 1;  // pseudorandomly pick number between 1 and 3
    switch (num) {
    case 1:
        return new Roomba();
    case 2:
        return new Swiftie();
    case 3:
        return new Ninja();
    }
    return nullptr;
}


void startBattle(Player player) {
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