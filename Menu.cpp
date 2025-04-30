#include <conio.h> // Includes the _getch() function to retrieve keyboard input.
#include <string>
#include <tuple> // Includes std::ignore.
#include <vector>
#define NOMINMAX // Ensure that including windows does not bring over std::min, std::max
#include <windows.h> // Allows for sleep.
#include "Menu.h"
#include "./utilities/Generator.h"
#include "./utilities/KeyBindings.h" // Brings over keyboard input constants.
#include "./utilities/Music.h"
#include "DialogueNode.h"
#include "Inventory.h"
#include "Item.h"
#include "Map.h"
#include "Player.h"
#include "Shop.h"
#include "TalkingNPC.h"
#include <cstdlib>


/**********************************************
******************* Menu **********************
***********************************************/

void Menu::clear() {
	// A portable method for most Windows and Unix systems that uses
	// ANSI escape codes to clear the screen of text.
	std::cout << "\033[2J\033[H";
}

void Menu::yellow() {
	std::cout << "\033[1;33m";
}

std::string Menu::yellow(std::string text) {
	return "\033[1;33m" + text + "\033[0m";
}

Player* Menu::getPlayer() { return player; }
void Menu::setPlayer(Player* p) { player = p; }

/**********************************************
****************** Start Menu *****************
***********************************************/
StartMenu::StartMenu() {

	backgroundPlay("theme.wav");
	int choice{ KEY_UP };
	// The highlighted yellow text, when Enter key is pressed this option is selected.
	int index{ 1 };
	do {
		clear();
		std::cout << yellow("The Video Game") << "\n";
		std::vector<std::string> options = {
			"1. Start New Game",
			"2. Continue Game",
			"3. Quit Game"
		};
		options[index - 1] = yellow(options[index - 1]);
		for (int i = 0; i < options.size(); i++) {
			std::cout << options[i] << "\n";
		}

		choice = _getch(); // Take input from the keyboard

		const int INDEX_MAX = 3;
		switch (choice) {
		case KEY_UP:
			if (index != 1) index--;
			else index = INDEX_MAX;
			break;
		case KEY_DOWN:
			if (index != INDEX_MAX) index++;
			else index = 1;
			break;
		case KEY_ENTER:
			switch (index) {
			case 1: choice = KEY_ONE; break;
			case 2: choice = KEY_TWO; break;
			case 3: choice = KEY_THREE; break;
			}
		}

		switch (choice) {
		case KEY_ONE:
			newGame();
			std::ignore = _getch();
			break;
		case KEY_TWO:
			continueGame();
			std::ignore = _getch();
			break;
		case KEY_THREE:
			quitGame();
			std::ignore = _getch();
			break;
		}

	} while (choice != KEY_THREE);
}

void StartMenu::newGame() {
	PlayerSelectMenu playerMenu; // Have the user select a player.
	if (playerMenu.getSelectedPlayer()) {
		player = playerMenu.getSelectedPlayer();
	}
	else {
		return;
	}

	Map* ohio = new Map(player, this);
	try {
		ohio->getIndex()->execLocation(player);
	}
	catch (int) {
	}
}


void StartMenu::continueGame() {
	if (player) {
		if (getLastLocation()) {
			getLastLocation()->execLocation(player);
		}
		else {
			std::cout << "No location found.\n";
			std::cout << "Make sure you've started a game before you continue.\n";
			std::cout << "Press enter to continue... ";
			return;
		}
	}
	else {
		std::cout << "No player selected.\n";
		std::cout << "Make sure you've started a game before you continue.\n";
		std::cout << "Press enter to continue... ";
		return;
	}
}

void StartMenu::quitGame() {
	std::cout << std::endl;
	std::cout << "Quitting game.\n";
	std::cout << "Press enter to continue... ";
	return;
}

MapNode* StartMenu::getLastLocation() {
	return lastLocation;
}

void StartMenu::setLastLocation(MapNode* node) {
	lastLocation = node;
}

/**********************************************
************** Player Select Menu *************
***********************************************/
PlayerSelectMenu::PlayerSelectMenu() {

	backgroundPlay("theme.wav");
	std::cout << "Choose Your Player!\n";
	int choice{ KEY_UP };
	// The highlighted yellow text, when Enter key is pressed this option is selected.
	int index{ 1 };
	do {
		clear();

		std::vector<std::string> options = {
			"1. Play a Warrior",
			"2. Play a Rogue",
			"3. Play a Mage",
			"4. Return to Start Game"
		};
		options[index - 1] = yellow(options[index - 1]);
		for (int i = 0; i < options.size(); i++) {
			std::cout << options[i] << "\n";
		}

		choice = _getch(); // Take input from the keyboard.

		const int INDEX_MAX = 4;
		switch (choice) {
		case KEY_UP:
			if (index != 1) index--;
			else index = INDEX_MAX;
			break;
		case KEY_DOWN:
			if (index != INDEX_MAX) index++;
			else index = 1;
			break;
		case KEY_ENTER:
			// When the enter key is pressed we don't break out of the case.
			// Using the index we reassign the choice to the appropriate key sequence.
			switch (index) {
			case 1: choice = KEY_ONE; break;
			case 2: choice = KEY_TWO; break;
			case 3: choice = KEY_THREE; break;
			case 4: choice = KEY_FOUR; break;
			}
		}

		switch (choice) {
		case KEY_ONE:
			playWarrior();
			std::ignore = _getch(); // Wait for keypress before redrawing.
			break;
		case KEY_TWO:
			playRogue();
			std::ignore = _getch();
			break;
		case KEY_THREE:
			playMage();
			std::ignore = _getch();
			break;
		case KEY_FOUR:
			returnToStart();
			std::ignore = _getch();
			break;
		default:
			break;
		}
	} while (choice != KEY_FOUR && getSelectedPlayer() == nullptr);
}

Player* PlayerSelectMenu::getSelectedPlayer() { return selectedPlayer; }
void PlayerSelectMenu::setSelectedPlayer(Player* play) { selectedPlayer = play; }

void PlayerSelectMenu::playWarrior() {
	std::system("cls");
	std::cout << "Choosing warrior!\n";
	std::string name;
	std::cout << "What name should this warrior bear?\n";
	std::getline(std::cin, name);


	Player* warrior = new Player(name, "Warrior", 50, 30, 0, 25, 30, 20, 30, 0, 1);
	setSelectedPlayer(warrior);

	std::system("cls");
	std::cout << getSelectedPlayer()->getName() << " is now a Warrior!\n";
	soundEffect("levelUp.wav");
	std::cout << "Press enter to continue... ";
}

void PlayerSelectMenu::playRogue() {
	std::system("cls");
	std::cout << "Choosing rogue!\n";
	std::string name;
	std::cout << "What name should this rogue bear?\n";
	std::getline(std::cin, name);


	Player* rogue = new Player(name, "Rogue", 30, 60, 10, 15, 5, 5, 125, 0, 1);
	setSelectedPlayer(rogue);

	std::system("cls");
	std::cout << getSelectedPlayer()->getName() << " is now a Rogue!\n";
	soundEffect("levelUp.wav");
	std::cout << "Press enter to continue... ";
}

void PlayerSelectMenu::playMage() {
	std::system("cls");
	std::cout << "Choosing mage!\n";
	std::string name;
	std::cout << "What name should this mage bear?\n";

	std::getline(std::cin, name);

	Player* mage = new Player(name, "Mage", 25, 15, 60, 20, 15, 10, 75, 0 ,1);
	setSelectedPlayer(mage);

	std::system("cls");
	std::cout << getSelectedPlayer()->getName() << " is now a Mage!\n";
	soundEffect("levelUp.wav");
	std::cout << "Press enter to continue... ";
}

int PlayerSelectMenu::returnToStart() {
	std::cout << std::endl;
	std::cout << "Returning to Start Menu.\n";
	std::cout << "Press enter to continue... ";
	return 0;
}

/**********************************************
****************** Main Menu ******************
***********************************************/

MainMenu::MainMenu(Player* p) : Menu() {
	// Initialize the player variable.
	player = p;

	backgroundPlay("theme.wav"); 
	std::cout << yellow("The Video Game Main Menu") << "\n";
	int choice{ KEY_UP };
	// The highlighted yellow text, when Enter key is pressed this option is selected.
	int index{ 1 };
	do {
		clear();
		//if (validKeys.find(choice) == validKeys.end()) {
		//	std::cout << "That's not a valid option. Please enter one of the options listed.\n\n";
		//}

		std::vector<std::string> options = {
			"1. Return to Game",
			"2. Display Player Stats",
			"3. Enter Battle",
			"4. Manage Inventory",
			"5. Enter Shop",
			"6. Talk to Someone",
			"7. Quit Game"
		};

		options[index - 1] = yellow(options[index - 1]);
		for (int i = 0; i < options.size(); i++) {
			std::cout << options[i] << "\n";
		}

		choice = _getch(); // Take input from the keyboard.

		const int INDEX_MAX = 7;
		switch (choice) {
		case KEY_UP:
			if (index != 1) index--;
			else index = INDEX_MAX;
			break;
		case KEY_DOWN:
			if (index != INDEX_MAX) index++;
			else index = 1;
			break;
		case KEY_ENTER:
			// When the enter key is pressed we don't break out of the case.
			// Using the index we reassign the choice to the appropriate key sequence.
			switch (index) {
			case 1: choice = KEY_ONE; break;
			case 2: choice = KEY_TWO; break;
			case 3: choice = KEY_THREE; break;
			case 4: choice = KEY_FOUR; break;
			case 5: choice = KEY_FIVE; break;
			case 6: choice = KEY_SIX; break;
			case 7: choice = KEY_SEVEN; break;
			}
		}

		switch (choice) {
		case KEY_ONE:
			returnToOverworld();
			std::ignore = _getch(); // Wait for keypress before redrawing.
			break;
		case KEY_TWO:
			displayStats();
			std::ignore = _getch();
			break;
		case KEY_THREE:
			enterBattle();
			std::ignore = _getch();
			break;
		case KEY_FOUR:
			manageInventory();
			std::ignore = _getch();
			break;
		case KEY_FIVE:
			enterShop();
			std::ignore = _getch();
			break;
		case KEY_SIX:
			chat();
			std::ignore = _getch();
			break;
		case KEY_SEVEN:
			quitGame();
			std::ignore = _getch();
		default:
			break;
		}
	} while (choice != KEY_SEVEN);
}

void MainMenu::returnToOverworld() {
	std::cout << std::endl;
	std::cout << "Returning to Overworld.\n";
	std::cout << "Press enter to continue... ";
	return;
}

void MainMenu::displayStats() {
	clear();
	player->displayStats();
	std::cout << "Press enter to continue... ";
	return;
}

void MainMenu::enterBattle() {
	std::cout << std::endl;
	if (player) {
		BattleMenu menu(player);
	}
	else {
		std::cout << "No player found.\n";
	}
	return;
}

void MainMenu::manageInventory() {
	std::cout << std::endl;
	if (player) {
		InventoryMenu menu(player);
	}
	else {
		std::cout << "No player found.\n";
	}
	return;
}

void MainMenu::enterShop() {
	std::cout << std::endl;
	if (player) {
		ShopMenu menu(player);
	}
	else {
		std::cout << "No player found.\n";
	}
	return;
}

void MainMenu::chat() {
	std::cout << std::endl;
	// std::cout << "Chatting.\n";

	clear();
	// ----------- NPC #1 ----------- //
	TalkingNPC* npc = new TalkingNPC("Hermit", 8); //eight node of dialogue, first the inital 0 and then 1, 2, and 3, then three for one (4,5,6) and two for 2 (7,8)
	std::vector<int> next = { 1, 2, 3 };
	npc->setDialogue(0, new DialogueNode("Hello traveler. I see you are new here. I've lived alongside this road for many years and know much about its' inhabitants.", //this is dialogue 0
		"1: Tell me about the enemies I will encounter.\n2: Where can I buy equipment? \n3: I'm busy, go away.",
		next));

	std::vector<int> next1 = { 4,5,6 };
	npc->setDialogue(1, new DialogueNode("There are three monsters you will have to fight: the Roomba, the Chinese Spy Pigeon, and Danny Devito.", //this is dialgoue 1
		"1: Tell me about the Roomba.\n2: Tell me about the Chinese Spy Pigeon. \n3: Tell me about Danny Devito",
		next1));

	std::vector<int> next2 = { 7,8 };
	npc->setDialogue(2, new DialogueNode("What are you looking for, armor or weapons?", //this is dialgoue 2
		"1: Armor\n2: Weapons.",
		next2));

	std::vector<int> next3 = {};
	npc->setDialogue(3, new DialogueNode("Have a blessed day traveller", //this is dialgoue 3
		"Press any key to continue...",
		next3));
	std::vector<int> next4 = {};
	npc->setDialogue(4, new DialogueNode("The Roomba can be easily trampled underfoot.", //this is dialgoue 4
		"Press any key to continue...",
		next4));
	std::vector<int> next5 = {};
	npc->setDialogue(5, new DialogueNode("The Chinese Spy Pigeon can be defeated if you sever its radio connection.", //this is dialgoue 5
		"Press any key to continue...",
		next5));
	std::vector<int> next6 = {};
	npc->setDialogue(6, new DialogueNode("Danny Devito prefers to attack rather than defend.", //this is dialgoue 6
		"Press any key to continue...",
		next6));
	std::vector<int> next7 = {};
	npc->setDialogue(7, new DialogueNode("Go to town.There you will find an armor shop.Good luck in your travels!", //this is dialgoue 7
		"Press any key to continue...",
		next7));
	std::vector<int> next8 = {};
	npc->setDialogue(8, new DialogueNode("Go to town. There you will find a weapons shop. Good luck in your travels!", //this is dialgoue 8
		"Press any key to continue...",
		next8));
	npc->printDialogue(0);
	system("pause");

	clear();
	// ----------- NPC #2 ----------- //
	TalkingNPC* npc2 = new TalkingNPC("Wandering salesman", 8); //eight node of dialogue, first the inital 0 and then 1, 2, and 3, then three for one (4,5,6) and two for 2 (7,8)
	std::vector<int> next9 = { 1, 2, 3 };
	npc2->setDialogue(0, new DialogueNode("Hello traveler! Would you be interested in joining a pyramid scheme?", //this is dialogue 0
		"1: Tell me more.\n2: Isn't that illegal? \n3: STRANGER DANGER",
		next9));

	std::vector<int> next10 = { 4,5,6 };
	npc2->setDialogue(1, new DialogueNode("Well I will give you this very nice set of knives, and if you sell it to your family and friends, I will pay you a portion of the profit.", //this is dialgoue 1
		"1: That sounds great! Count me in! \n2: I don't know about this... \n3: This sounds like a scam, goodbye.",
		next10));

	std::vector<int> next11 = { 7,8 };
	npc2->setDialogue(2, new DialogueNode("Nooooooooo of course not...", //this is dialgoue 2
		"1: Walk away in disdain.\n2: Steal the knives.",
		next11));

	std::vector<int> next12 = {};
	npc2->setDialogue(3, new DialogueNode("Fine! Be that way.", //this is dialgoue 3
		"Press any key to continue...",
		next12));
	std::vector<int> next13 = {};
	npc2->setDialogue(4, new DialogueNode("Great! Sign right here!", //this is dialgoue 4
		"You are now involved in a pyramid scheme...\nPress any key to continue...",
		next13));
	std::vector<int> next14 = {};
	npc2->setDialogue(5, new DialogueNode("Oh come on! This is a completely foolproof business strategy!", //this is dialgoue 5
		"You walk away from the trap...\nPress any key to continue...",
		next14));
	std::vector<int> next15 = {};
	npc2->setDialogue(6, new DialogueNode("But you can save up for college!!", //this is dialgoue 6
		"You ignore the crazy salesman and walk away...\nPress any key to continue...",
		next15));
	std::vector<int> next16 = {};
	npc2->setDialogue(7, new DialogueNode("Hey don't leave! I promise you'll make money!", //this is dialgoue 7
		"You back away slowly...\nPress any key to continue...",
		next16));
	std::vector<int> next17 = {};
	npc2->setDialogue(8, new DialogueNode("HEY! Those are mine!!", //this is dialgoue 8
		"You are now on the run...\nPress any key to continue...",
		next17));

	npc2->printDialogue(0);
	system("pause");

	std::cout << "Press enter to continue... ";
	return;
}

int MainMenu::quitGame() {
	std::cout << std::endl;
	std::cout << "Quitting.\n";
	std::cout << "Press enter to continue... ";
	return 0;
}

BattleMenu::BattleMenu(Player* p)
	: BattleMenu(p, generateEnemy()) {
}

BattleMenu::BattleMenu(Player* p, Enemy* e) {
	player = p;
	enemy = e;
	int e_health = e->getHealth();
	int r;
	int choice;
	int index{ 1 };
	if (enemy->getName() != "Tyler Brown") {
		backgroundPlay("battle.wav");
	}
	else {
		backgroundPlay("boss.wav");
	}

	while (true) {
		clear();
		player->setTarget(e);
		enemy->setTarget(player);

		std::cout << "Battling \033[31m" << enemy->getName() << "\033[0m!\n\n";
		std::cout << "\033[32m" << player->getName() << "\033[0m"
			<< "'s Health: " << "\033[34m" << player->getHealth() << "\033[0m" << ".\n"
			<< "\033[32m" << player->getName() << "\033[0m"
			<< "'s Stamina: " << "\033[34m" << player->getStamina() << "\033[0m" << ".\n"
			<< "\033[32m" << player->getName() << "\033[0m"
			<< "'s Mana: " << "\033[34m" << player->getMana() << "\033[0m" << ".\n";
		std::cout << "\033[31m" << enemy->getName() << "\033[0m" << "'s Health: " << "\033[34m" << enemy->getHealth() << "\033[0m" << "\n\n";

		std::vector<std::string> options = {
			"1. Attack",
			"2. Magic",
			"3. Defend",
			"4. Flee"
		};
		options[index - 1] = yellow(options[index - 1]);
		for (int i = 0; i < options.size(); i++) {
			std::cout << options[i] << "\n";
		}
		std::cout << std::endl;

		choice = _getch();
		if (choice == 224) choice = _getch();

		const int INDEX_MAX = 4;
		switch (choice) {
		case KEY_UP:
			if (index != 1) index--;
			else index = INDEX_MAX;
			continue;
		case KEY_DOWN:
			if (index != INDEX_MAX) index++;
			else index = 1;
			continue;
		case KEY_ENTER:
			switch (index) {
			case 1: choice = KEY_ONE; break;
			case 2: choice = KEY_TWO; break;
			case 3: choice = KEY_THREE; break;
			case 4: choice = KEY_FOUR; break;
			default: continue;
			}
			break;
		default:
			continue;
		}

		switch (choice) {
		case KEY_ONE:
			attacks();
			break;
		case KEY_TWO:
			magic();
			break;
		case KEY_THREE:
			block();
			break;
		case KEY_FOUR:
			flee();
			std::ignore = _getch();
			backgroundPlay("theme.wav");
			return;
		default:
			break;
		}

		if (enemy->getHealth() > (.3 * e_health)) {
			r = rand() % 3 + 1;
			if (enemy->getStrength() > enemy->getMana() || enemy->getDexterity()) {
				enemy->meleeAttack();
				if(enemy->getName() != "Tyler Brown") {
					if (r == 1) backgroundPlay("attack3.wav");
					else if (r == 2) backgroundPlay("attack2.wav");
					else backgroundPlay("attack1.wav");
				}
			}
			else if (enemy->getMana() > enemy->getStrength() || enemy->getDexterity()) {
				enemy->spellAttack();
			}
			else if (enemy->getDexterity() > enemy->getMana() || enemy->getStrength()) {
				enemy->rangedAttack();
			}
			else {
				if (r == 1) enemy->meleeAttack();
				else if (r == 2) enemy->spellAttack();
				else enemy->rangedAttack();
			}
			Sleep(1000);
			if (enemy->getName() != "Tyler Brown") {
				PlaySound(NULL, NULL, 0);
			}
			std::cout << "\nPress enter to continue... \n";
			std::ignore = _getch();
			if (enemy->getName() != "Tyler Brown") {
				backgroundPlay("battle.wav");
			}

		}
		if (enemy->getHealth() <= 0) {
			std::system("cls");
			backgroundPlay("victory.wav");
			std::cout << "You've defeated " "\033[31m" << enemy->getName() << "\033[0m!!!!\n\n";
			Sleep(1500);
			PlaySound(nullptr, nullptr, SND_ASYNC);
			std::cout << "\nPress enter to continue... \n";
			std::ignore = _getch();			
			player->setGold(player->getGold() + enemy->getGold());
			player->setExperience((enemy->getGold() / 2));
			player->checkLevelUp();
			std::system("cls");
			if (enemy->getName() == "Roomba") {
				int r = rand() % 3 + 1;
				if (r == 1 || r==3) {
					player->getInventory()->addItem("Mechanical Part", 3, 15);
					cout << "\033[31m" << enemy->getName() << "\033[0m" << " just dropped \033[34m3\033[0m Mechanical parts!!\n\n";
					soundEffect("coinGain.wav");
				}
				if (r == 2) {
					player->getInventory()->addItem("Glowing eye", 1, 50);
					cout << "\033[31m" << enemy->getName() << "\033[0m" << " just dropped \033[34m1\033[0m Glowing Eye!!\n\n";
					soundEffect("coinGain.wav");

				}

			}
			if (enemy->getName() == "Chinese Spy Pigeon") {
				int r = rand() % 3 + 1;
				if (r == 1 || r == 3) {
					player->getInventory()->addItem("Mechanical Part", 3, 40);
					cout << "\033[31m" << enemy->getName() << "\033[0m" << " just dropped 3 feathers!!\n\n";
				}
				if (r == 2) {
					player->getInventory()->addItem("Camera", 1, 250);
					cout << "\033[31m" << enemy->getName() << "\033[0m" << " just dropped a Camera!!\n\n";

				}

			}
			if (enemy->getName() == "Danny Devito") {
				int r = rand() % 3 + 1;
				if (r == 1 || r == 3) {
					player->getInventory()->addItem("Mechanical Part", 2, 200);
					cout << "\033[31m" << enemy->getName() << "\033[0m" << " just dropped 3 blasters!!\n\n";
				}
				if (r == 2) {
					player->getInventory()->addItem("Glowing eye", 1, 500);
					cout << "\033[31m" << enemy->getName() << "\033[0m" << " just dropped a Penguin!!\n\n";

				}

			}
			if (enemy->getName() == "Tyler Brown") {
				player->getInventory()->addItem("3rd Extension Request", 3, 15);
				cout << enemy->getName() << " just dropped a 3rd Extesion Request!! USE IT BEFORE IT'S TOO LATE!!!!!\n\n";
				cout << "Congrats you just beat the game which means you're able to now use A THIRD EXTENSION ON WHATEVER YOU DESIRE.... or can you???\n\n";
				std::cout << "\nPress enter to finish game\n";
				std::ignore = _getch();
				std::exit(EXIT_SUCCESS);
			}
			std::cout << "\nPress enter to continue... \n\n";
			std::ignore = _getch();
			backgroundPlay("theme.wav");
			std::ignore = _getch();
			return;
		}
		else if (player->getHealth() <= 0) {
			backgroundPlay("defeat.wav");
			std::cout << "You've been defeated.....\n";
			Sleep(1000);
			backgroundPlay("theme.wav");
			std::cout << "Press enter to continue... \n";
			player->setHealth(player->getBaseHealth());
			player->setGold(player->getGold() - enemy->getGold());
			std::ignore = _getch();
			return;
		}
	}
}

void BattleMenu::attacks() {
	string choice;
	int r = rand() % 3 + 1;
	cout << "Close(1) or ranged attack?(2): ";
	getline(cin, choice);
	if (choice == "2")
	{
		if (r == 1) {
			if(enemy->getName()!="Tyler Brown") {
			backgroundPlay("attack1.wav");
			}
		}
		else if (r == 2) {
			if (enemy->getName() != "Tyler Brown") {
				backgroundPlay("attack2.wav");
			}
		}
		else {
			if (enemy->getName() != "Tyler Brown") {
				backgroundPlay("attack3.wav");
			}
		}
		Sleep(1000);
		if (enemy->getName() != "Tyler Brown") {
			PlaySound(NULL, NULL, 0);
		}
		player->rangedAttack();
		std::cout << "Press enter to continue... \n";
		std::ignore = _getch();
		int stamina = player->getStamina();
		int chance = std::min(stamina, 100);
		int roll = rand() % 100;
		if (roll < chance) {
			std::cout << "\nDouble Attack!\n";
				player->rangedAttack();
				std::cout << "Press enter to continue... \n";
				std::ignore = _getch();
		}

	}
	else {
		if (r == 1) {
			if (enemy->getName() != "Tyler Brown") {
				backgroundPlay("attack1.wav");
			}
		}
		else if (r == 2) {
			if (enemy->getName() != "Tyler Brown") {
				backgroundPlay("attack2.wav");
			}
		}
		else {
			if (enemy->getName() != "Tyler Brown") {
				backgroundPlay("attack3.wav");
			}
		}
		Sleep(1000);
		if (enemy->getName() != "Tyler Brown") {
			PlaySound(NULL, NULL, 0);
		}
		player->meleeAttack();
		std::cout << "Press enter to continue... \n\n";
		std::ignore = _getch();
		int stamina = player->getStamina();
		int chance = std::min(stamina, 100);
		int roll = rand() % 100;
		if (roll < chance) {
			std::cout << "\nDouble Attack!\n";
			player->meleeAttack();
			std::cout << "Press enter to continue... \n";
			std::ignore = _getch();
		}
	}
	if (enemy->getName() != "Tyler Brown") {
		backgroundPlay("battle.wav");
	}

	
}

void BattleMenu::magic() {
	int r = rand() % 2 + 1;
	if (r == 1) {
		if (enemy->getName() != "Tyler Brown") {
			backgroundPlay("mAttack1.wav");
		}
	}
	else {
		if (enemy->getName() != "Tyler Brown") {
			backgroundPlay("mAttack2.wav");
		}
	}
	Sleep(1000);
	if (enemy->getName() != "Tyler Brown") {
		PlaySound(NULL, NULL, 0);
	}
	player->spellAttack();
	std::cout << "Press enter to continue... \n\n";
	std::ignore = _getch();
	if (enemy->getName() != "Tyler Brown") {
		backgroundPlay("battle.wav");
	}
}

void BattleMenu::block() {
	player->setBlock(true);

}

void BattleMenu::displayStats() {
	player->displayStats();
	std::cout << "\nPress enter to continue... \n\n";
}

void BattleMenu::inventory() {
	if (player) {
		InventoryMenu menu(player);
	}
	else {
		std::cout << "No player found.\n";
	}
}

void BattleMenu::chat() {
	std::cout << "To be implemented...\n";
	std::cout << "Press enter to continue... \n";
}

void BattleMenu::flee() {
	std::cout << "Fleeing...\n";
	backgroundPlay("run.wav");
	std::cout << "\nPress enter to continue... \n";
}

InventoryMenu::InventoryMenu(Player* p) {
	backgroundPlay("inventory.wav");
	player = p;

	int choice{ KEY_UP };
	int index{ 1 };
	do {
		clear();
		std::cout << "Inventory Menu\n";

		std::vector<std::string> options = {
			"1. View Inventory",
			"2. Add Item",
			"3. Remove Item",
			"4. Exit"
		};
		options[index - 1] = yellow(options[index - 1]);
		for (int i = 0; i < options.size(); i++) {
			std::cout << options[i] << "\n";
		}

		choice = _getch();

		const int INDEX_MAX = 4;
		switch (choice) {
		case KEY_UP:
			if (index != 1) index--;
			else index = INDEX_MAX;
			break;
		case KEY_DOWN:
			if (index != INDEX_MAX) index++;
			else index = 1;
			break;
		case KEY_ENTER:
			switch (index) {
			case 1: choice = KEY_ONE;   break;
			case 2: choice = KEY_TWO;   break; 
			case 3: choice = KEY_THREE; break; 
			case 4: choice = KEY_FOUR;  break; 
			}
			break;
		default:
			break;
		}

		switch (choice) {
		case KEY_ONE:
			viewInventory();
			std::ignore = _getch();
			break;
		case KEY_TWO:
			addItem();
			std::ignore = _getch();
			break;
		case KEY_THREE:
			removeItem();
			std::ignore = _getch();
			break;
		case KEY_FOUR:
			exit();
			std::ignore = _getch();
			backgroundPlay("theme.wav");
			break;
		default:
			break;
		}
	} while (choice != KEY_FOUR);
}

void InventoryMenu::manageInventory() {
	return;
}

void InventoryMenu::viewInventory() {
	LinkedList<Item*> list = player->getInventory()->getItems();
	std::vector<Item*> items;
	for (Node<Item*>* cur = list.getHead(); cur; cur = cur->nextNode)
		items.push_back(cur->data);

	if (items.empty()) {
		clear();
		std::cout << "\n--- Inventory is empty ---\n";
		std::cout << "Press enter to continue... ";
		_getch();
		return;
	}
	int index = 0;
	int ch;
	do {
		clear();
		std::cout << "\n--- Inventory ---\n";
		for (int i = 0; i < (int)items.size(); ++i) {
			std::string label = items[i]->getName() + " (x" + std::to_string(items[i]->getQuantity()) + ")";
			if (i == index)
				std::cout << yellow(label) << "\n";
			else
				std::cout << " " << label << "\n";
		}
		std::cout << "\nUse  arrows keys to move up and down, Enter to consume/equip, and Esc to back out.\n";

		ch = _getch();
		if (ch == KEY_UP) {
			index = (index - 1 + items.size()) % items.size();
		}
		else if (ch == KEY_DOWN) {
			index = (index + 1) % items.size();
		}
		if (ch == KEY_ENTER) {
			Item* item1 = items[index];

			if (ch == KEY_ENTER) {
				Item* item1 = items[index];

				if (auto eqItem = dynamic_cast<Equippable*>(item1)) {
					if (!item1->getEquipped()) {
						eqItem->equip(player);
						item1->setEquipped(true);
						std::cout << "\nEquipped " << item1->getName() << "!\n";
					}
					else {
						eqItem->unequip(player);
						item1->setEquipped(false);
						std::cout << "\nUnequipped " << item1->getName() << "!\n";
					}
					player->displayStats();
				}
				else if (auto co = dynamic_cast<Consumable*>(item1)) {
					co->consume(player);
					player->getInventory()->removeItem(item1);
					std::cout << "\nConsumed " << item1->getName() << "!\n";
				}
				else {
					std::cout << "\nCannot use " << item1->getName() << ".\n";
				}

				std::cout << "\nPress any key to continue (or Esc to exit)...";
				int c = _getch();
				if (c == 27)  // Esc
					break;
				else
					continue;
			}
		}
	} while (ch != 27);
} 



void InventoryMenu::addItem() {
	std::cout << std::endl;
	std::string itemName;
	int quantity;
	// Allow the user multiple attempts to add items.
	std::string flag{ "yes" };
	do {
		// Some issues arise from the input buffer containing characters; this clears it.
		std::cin.clear();

		std::cout << "What item would you like to add?\n";
		std::getline(std::cin, itemName);

		std::cout << "How many do you want to add?\n";
		std::cin >> quantity;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		player->getInventory()->addItem(itemName, quantity);

		std::cout << "Do you wish to add more items? Please type 'yes' or 'no'\n";
		std::cin >> flag;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} while (flag != "no" && flag != "n");

	std::cout << "Press enter to continue... ";
	return;
}

void InventoryMenu::removeItem() {
	std::cout << std::endl;
	std::string itemName;
	int quantity;
	// Allow the user multiple attempts to remove items.
	std::string flag{ "yes" };
	do {
		// Some issues arise from the input buffer containing characters; this clears it.
		std::cin.clear();

		std::cout << "What item would you like to remove?\n";
		std::getline(std::cin, itemName);

		std::cout << "How many do you want to remove?\n";
		std::cin >> quantity;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		player->getInventory()->removeItem(itemName, quantity);

		std::cout << "Do you wish to remove more items? Please type 'yes' or 'no'\n";
		std::cin >> flag;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} while (flag != "no" && flag != "n");

	std::cout << "Press enter to continue... ";
	return;
}

int InventoryMenu::exit() {
	std::cout << std::endl;
	std::cout << "Exiting.\n";
	std::cout << "Press enter to continue... \n";
	return 0;
}

ShopMenu::ShopMenu(Player* p)
	: ShopMenu(p, generateShop()) {}

ShopMenu::ShopMenu(Player* p, Shop* s) {
	backgroundPlay("shop.wav");
	// Initialize the player variable.
	player = p;
	// Initialize the shop variable.
	shop = s;

	int choice{ KEY_UP };
	// The highlighted yellow text, when Enter key is pressed this option is selected.
	int index{ 1 };
	do {
		clear();
		std::cout << yellow("Shop Menu") << "\n";
		std::vector<std::string> options = {
			"1. Browse Wares",
			"2. Buy an Item",
			"3. Sell an Item",
			"4. Exit"
		};
		options[index - 1] = yellow(options[index - 1]);
		for (int i = 0; i < options.size(); i++) {
			std::cout << options[i] << "\n";
		}

		choice = _getch(); // Take input from the keyboard.

		const int INDEX_MAX = 4;
		switch (choice) {
		case KEY_UP:
			if (index != 1) index--;
			else index = INDEX_MAX;
			break;
		case KEY_DOWN:
			if (index != INDEX_MAX) index++;
			else index = 1;
			break;
		case KEY_ENTER:
			// When the enter key is pressed we don't break out of the case.
			// Using the index we reassign the choice to the appropriate key sequence.
			switch (index) {
			case 1: choice = KEY_ONE; break;
			case 2: choice = KEY_TWO; break;
			case 3: choice = KEY_THREE; break;
			case 4: choice = KEY_FOUR; break;
			}
		}

		switch (choice) {
		case KEY_ONE:
			browse();
			std::ignore = _getch(); // Wait for keypress before redrawing.
			break;
		case KEY_TWO:
			buy();
			std::ignore = _getch();
			break;
		case KEY_THREE:
			sell();
			std::ignore = _getch();
			break;
		case KEY_FOUR:
			exit();
			std::ignore = _getch();
			backgroundPlay("theme.wav");
			break;
		default:
			break;
		}
	} while (choice != KEY_FOUR);


}

void ShopMenu::browse() {
	clear();
	std::cout << "\"Come to see my wares?\"\n";
	std::cout << player->getName() << "'s Gold Amount: " << player->getGold() << ".\n\n";

	// Build the list of shop items.
	LinkedList<Item*> list = shop->getInventory()->getItems();
	Node<Item*>* node = list.getHead();

	std::vector<std::string> options{};
	int storeSize = 0;
	while (node) {
		storeSize++;
		std::string name = node->data->getName();
		int quantity = node->data->getQuantity();
		int cost = node->data->getCost();

		options.push_back(
			std::to_string(storeSize) + ". - " + name +
			" (x" + std::to_string(quantity) + ") - " +
			std::to_string(cost) + " gold."
		);

		node = node->nextNode;
	}

	for (int i = 0; i < options.size(); i++) {
		std::cout << options[i] << "\n";
	}

	std::cout << "\nPress enter to continue... \n";
}

void ShopMenu::buy() {
	int choice{ KEY_UP };
	int index{ 1 };
	int storeSize{ shop->getInventory()->getSize() };
	do {
		clear();
		std::cout << "\"Looking to buy something? Hope you've brough enough gold.\"\n";
		std::cout << player->getName() << "'s Gold Amount: " << player->getGold() << ".\n\n";

		// Build the list of options and append them to the options vector of strings.
		LinkedList<Item*> list = shop->getInventory()->getItems();
		Node<Item*>* current = list.getHead();
		std::vector<std::string> options{};
		storeSize = 0; // Rebuild the storeSize and use it to number the entries.
		while (current) {
			// Fetch the variables
			storeSize++;
			std::string name = current->data->getName();
			int quantity = current->data->getQuantity();
			int cost = current->data->getCost();
			// Append to options.
			options.push_back(
				std::to_string(storeSize) + ". - " + name +
				" (x" + std::to_string(quantity) + ") - " +
				std::to_string(cost) + " gold."
			);
			// Move to next node
			current =  current->nextNode;
		}
		options.push_back(std::to_string(storeSize + 1) + ". - Exit");

		// Display options
		options[index - 1] = yellow(options[index - 1]);
		for (int i = 0; i < options.size(); i++) {
			std::cout << options[i] << "\n";
		}

		choice = _getch(); // Take input from the keyboard.

		int index_max = storeSize + 1;
		switch (choice) {
		case KEY_UP:
			if (index != 1) index--;
			else index = index_max;
			break;
		case KEY_DOWN:
			if (index != index_max) index++;
			else index = 1;
			break;
		case KEY_ENTER:
			if (index != index_max) {
				// Fetch the details of the item from the store.
				current = list.getHead();
				int ctr = 0;
				std::string name;
				int storeQuantity;
				int cost;
				while (current) {
					ctr++;
					if (ctr == index) {
						name = current->data->getName();
						storeQuantity = current->data->getQuantity();
						cost = current->data->getCost();
						break;
					}
					current = current->nextNode;
				}

				// Validate how much the user wants to buy.
				std::cout << "\"So you want a " + name + "? How many do you want?\"\n";
				int userWants;
				std::cin >> userWants;
				while (userWants < 0 || userWants > storeQuantity) {
					if (userWants < 0) {
						std::cout << "\"I'm not sure what you mean by that\"\n";
					}
					else {
						std::cout << "\"I don't have enough of that in stock.\"\n";
					}
					std::cout << "\"I have x" + std::to_string(storeQuantity) +
						" " + name + " available. " + 
						"You'll have to tell give me an amount to work with.\"\n";
					std::cin >> userWants;
				}

				// Check to see if the player entered 0 for quantity.
				if (userWants == 0) {
					std::cout << "\"Oh. Doesn't look you want anything. "
						<< "Come back when you do have something in mind.\"\n";
					// Wait for the user to read the message.
					std::cout << "Press enter to continue... \n";
					std::ignore = _getch();
					break;
				}

				// Validate the player has enough gold.
				int totalCost = cost * userWants;
				if (player->getGold() - totalCost < 0) {
					std::cout << "\"Sorry, looks like you're a little short on gold. Come back to me once you have enough.\"\n";
					// Wait for the user to read the message.
					std::cout << "Press enter to continue... \n";
					std::ignore = _getch();
					break;
				}

				// Check that the player wants to complete the transaction.
				std::string flag;
				std::cout << "\"Are you sure you want to buy x" + std::to_string(userWants) +
					" " + name + " with " + std::to_string(totalCost) + " gold?\"\n";
				std::cout << "Please type 'yes' to proceed... \n";
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::getline(std::cin, flag);
				if (flag == "yes" || flag == "y") {
					player->setGold(player->getGold() - totalCost);
					player->getInventory()->addItem(name, userWants);
					shop->getInventory()->removeItem(name, userWants);
				}
				else {
					std::cout << "\"Ok, well come back if you change your mind.\"\n";
					// Wait for the user to read the message.
					std::cout << "Press enter to continue... \n";
					std::ignore = _getch();
					break;
				}

				// Inform the player of a successful transaction.
				std::cout << name + " x" + std::to_string(userWants) + " added to inventory.\n";
				std::cout << std::to_string(totalCost)
					<< " gold removed. New total amount is " << std::to_string(player->getGold()) << ".\n";
				// Wait for the user to read the message.
				std::cout << "Press enter to continue... \n";
				std::ignore = _getch();
				break;
			}
			break;
		}


	} while (!(index == (storeSize + 1) && choice == KEY_ENTER));

	std::cout << "Press enter to continue... \n";
}

void ShopMenu::sell() {
	//std::cout << std::endl;
	//std::cout << "Selling items.\n";
	//std::cout << "Press enter to continue... \n";
	//return;

	int choice{ KEY_UP };
	int index{ 1 };
	int inventorySize{ player->getInventory()->getSize() };
	do {
		clear();
		std::cout << "\"Looking to sell something? I'd be willing to take a gander.\"\n";
		std::cout << player->getName() << "'s Gold Amount: " << player->getGold() << ".\n\n";

		// Build the list of options from the player and append them to options.
		LinkedList<Item*> list = player->getInventory()->getItems();
		Node<Item*>* current = list.getHead();
		std::vector<std::string> options;
		inventorySize = 0; // Rebuild the inventorySize and use it to number the entries.
		while (current) {
			// Fetch the variables.
			inventorySize++;
			std::string name = current->data->getName();
			int quantity = current->data->getQuantity();
			int cost = current->data->getCost();
			// Append to options.
			options.push_back(
				std::to_string(inventorySize) + ". - " + name +
				" (x" + std::to_string(quantity) + ") - " +
				std::to_string(cost) + " gold."
			);
			// Move to next node
			current = current->nextNode;
		}
		options.push_back(std::to_string(inventorySize + 1) + ". - Exit");

		// Display options
		options[index - 1] = yellow(options[index - 1]);
		for (int i = 0; i < options.size(); i++) {
			std::cout << options[i] << "\n";
		}

		choice = _getch(); // Take input from the keyboard.

		int index_max = inventorySize + 1;
		switch (choice) {
		case KEY_UP:
			if (index != 1) index--;
			else index = index_max;
			break;
		case KEY_DOWN:
			if (index != index_max) index++;
			else index = 1;
			break;
		case KEY_ENTER:
			if (index != index_max) {
				// Fetch the details of the item from the player.
				current = list.getHead();
				int ctr = 0;
				std::string name;
				int userQuantity;
				int cost;
				while (current) {
					ctr++;
					if (ctr == index) {
						name = current->data->getName();
						userQuantity = current->data->getQuantity();
						cost = current->data->getCost();
						break;
					}
					current = current->nextNode;
				}

				// Validate how much the user wants to sell.
				std::cout << "\"So you want to sell your " + name + "? How many do you want to sell?\"\n";
				int userWants;
				std::cin >> userWants;
				while (userWants < 0 || userWants > userQuantity) {
					if (userWants < 0) {
						std::cout << "\"I'm not sure what you mean by that\"\n";
					}
					else {
						std::cout << "\"You don't have enough items to sell.\"\n";
					}
					std::cout << "Player: " << player->getName() << "'s quantity of " <<
						name << " is x" << userQuantity << ". "
						<< "\"You'll have to give me an amount to work with.\"\n";
					std::cin >> userWants;
				}

				// Check to see if the player entered 0 for quantity.
				if (userWants == 0) {
					std::cout << "\"Oh. Doesn't look you want to sell anything. "
						<< "Come back when you do have something in mind.\"\n";
					// Wait for the user to read the message.
					std::cout << "Press enter to continue... \n";
					std::ignore = _getch();
					break;
				}

				// Check that the player wants to complete the transaction.
				int totalCost = cost * userWants; // Amount player earns.
				std::string flag;
				std::cout << "\"Are you sure you want to sell x" + std::to_string(userWants) +
					" " + name + " earning " + std::to_string(totalCost) + " gold?\"\n";
				std::cout << "Please type 'yes' to proceed... \n";
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::getline(std::cin, flag);
				if (flag == "yes" || flag == "y") {
					player->setGold(player->getGold() + totalCost);
					shop->getInventory()->addItem(name, userWants);
					player->getInventory()->removeItem(name, userWants);
				}
				else {
					std::cout << "\"Ok, well come back if you change your mind.\"\n";
					// Wait for the user to read the message.
					std::cout << "Press enter to continue... \n";
					std::ignore = _getch();
					break;
				}

				// Inform the player of a successful transaction.
				std::cout << name + " x" + std::to_string(userWants) + " removed from inventory.\n";
				std::cout << std::to_string(totalCost) 
					<< " gold added. New total amount is " << std::to_string(player->getGold()) << ".\n";
				// Wait for the user to read the message.
				std::cout << "Press enter to continue... \n";
				std::ignore = _getch();
				break;
			}
					
		}


	} while (!(index == (inventorySize + 1) && choice == KEY_ENTER));

	std::cout << "Press enter to continue... \n";
}

void ShopMenu::chat() {
	std::cout << std::endl;
	std::cout << "Chatting.\n";
	std::cout << "Press enter to continue... ";
}

int ShopMenu::exit() {
	std::cout << std::endl;
	std::cout << "Exiting.\n";
	std::cout << "Press enter to continue... \n";
	return 0;
}
