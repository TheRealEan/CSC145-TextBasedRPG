#include <conio.h> // Includes the _getch() function to retrieve keyboard input.
#include <string>
#include <vector>
#include "./utilities/KeyBindings.h" // Brings over keyboard input constants.
#include "Menu.h"

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

/**********************************************
************** Player Select Menu *************
***********************************************/
PlayerSelectMenu::PlayerSelectMenu() {

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
			"4. Quit Game"
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
			_getch(); // Wait for keypress before redrawing.
			break;
		case KEY_TWO:
			playRogue();
			_getch();
			break;
		case KEY_THREE:
			playMage();
			_getch();
			break;
		case KEY_FOUR:
			quitGame();
			_getch();
			break;
		default:
			break;
		}
	} while (choice != KEY_FOUR && getSelectedPlayer() == nullptr);
}

Player* PlayerSelectMenu::getSelectedPlayer() { return selectedPlayer; }
void PlayerSelectMenu::setSelectedPlayer(Player* play) { selectedPlayer = play; }

void PlayerSelectMenu::playWarrior() {
	std::cout << "Choosing warrior!\n";
	std::string name;
	std::cout << "What name should this warrior bear?\n";
	std::getline(std::cin, name);

	Player* warrior = new Player(name, 25, 15, 10, 15, 10, 10, 75);
	setSelectedPlayer(warrior);

	std::cout << getSelectedPlayer()->getName() << " is now a Warrior!\n";
	std::cout << "Press enter to continue... ";
}

void PlayerSelectMenu::playRogue() {
	std::cout << "Choosing rogue!\n";
	std::string name;
	std::cout << "What name should this rogue bear?\n";
	std::getline(std::cin, name);

	Player* rogue = new Player(name, 25, 15, 10, 15, 10, 10, 75);
	setSelectedPlayer(rogue);

	std::cout << getSelectedPlayer()->getName() << " is now a Rogue!\n";
	std::cout << "Press enter to continue... ";
}

void PlayerSelectMenu::playMage() {
	std::cout << "Choosing mage!\n";
	std::string name;
	std::cout << "What name should this mage bear?\n";
	std::getline(std::cin, name);

	Player* mage = new Player(name, 25, 15, 10, 15, 10, 10, 75);
	setSelectedPlayer(mage);

	std::cout << getSelectedPlayer()->getName() << " is now a Mage!\n";
	std::cout << "Press enter to continue... ";
}

int PlayerSelectMenu::quitGame() {
	std::cout << "Quitting game.\n";
	std::cout << "Press enter to continue... ";
	return 0;
}

/**********************************************
****************** Main Menu ******************
***********************************************/

MainMenu::MainMenu(Player* p) : Menu() {
	// Initialize the player variable.
	player = p;

	std::cout << "The Video Game Main Menu\n";
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
			}
		}

		switch (choice) {
		case KEY_ONE:
			returnToOverworld();
			_getch(); // Wait for keypress before redrawing.
			break;
		case KEY_TWO:
			displayStats();
			_getch();
			break;
		case KEY_THREE:
			enterBattle();
			_getch();
			break;
		case KEY_FOUR:
			manageInventory();
			_getch();
			break;
		case KEY_FIVE:
			enterShop();
			_getch();
			break;
		case KEY_SIX:
			chat();
			_getch();
			break;
		case KEY_SEVEN:
			quitGame();
			_getch();
		default:
			break;
		}
	} while (choice != KEY_SEVEN);
}

void MainMenu::returnToOverworld() {
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
	std::cout << "Enter Battle.\n";
	std::cout << "Press enter to continue... ";
	return;
}

void MainMenu::manageInventory() {
	if (player) {
		InventoryMenu menu(player);
	}
	else {
		std::cout << "No player found.\n";
	}
	return;
}

void MainMenu::enterShop() {
	if (player) {
		ShopMenu menu(player);
	}
	else {
		std::cout << "No player found.\n";
	}
	return;
}

void MainMenu::chat() {
	std::cout << "Chatting.\n";
	std::cout << "Press enter to continue... ";
	return;
}

int MainMenu::quitGame() {
	std::cout << "Quitting.\n";
	std::cout << "Press enter to continue... ";
	return 0;
}

InventoryMenu::InventoryMenu(Player* p) {
	// Initialize the player variable.
	player = p;

	std::cout << "Inventory Menu\n";
	int choice{ KEY_UP };
	// The highlighted yellow text, when Enter key is pressed this option is selected.
	int index{ 1 };
	do {
		clear();

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
			case 5: choice = KEY_FIVE; break;
			case 6: choice = KEY_SIX; break;
			}
		}

		switch (choice) {
		case KEY_ONE:
			viewInventory();
			_getch(); // Wait for keypress before redrawing.
			break;
		case KEY_TWO:
			addItem();
			_getch();
			break;
		case KEY_THREE:
			removeItem();
			_getch();
			break;
		case KEY_FOUR:
			exit();
			_getch();
			break;
		default:
			break;
		}
	} while (choice != KEY_FOUR);
}

void InventoryMenu::viewInventory() {
	player->getInventory()->printInventory();
	std::cout << "Press enter to continue... ";
}

void InventoryMenu::addItem() {
	std::string itemName;
	int quantity;
	// Allow the user multiple attempts to add items.
	std::string flag{ "yes" };
	do {
		// Some issues arise from the input buffer containing characters; these clear it.
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << "What item would you like to add?\n";
		std::getline(std::cin, itemName);

		std::cout << "How many do you want to add?\n";
		std::cin >> quantity;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		player->getInventory()->addItem(itemName, quantity);

		std::cout << "Do you wish to add more items? Please type 'yes' or 'no'\n";
		std::cin >> flag;
	} while (flag != "no" && flag != "n");

	std::cout << "Press enter to continue... ";
	return;
}

void InventoryMenu::removeItem() {
	std::string itemName;
	int quantity;
	// Allow the user multiple attempts to remove items.
	std::string flag{ "yes" };
	do {
		// Some issues arise from the input buffer containing characters; these clear it.
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << "What item would you like to remove?\n";
		std::getline(std::cin, itemName);

		std::cout << "How many do you want to remove?\n";
		std::cin >> quantity;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		player->getInventory()->removeItem(itemName, quantity);

		std::cout << "Do you wish to remove more items? Please type 'yes' or 'no'\n";
		std::cin >> flag;
	} while (flag != "no" && flag != "n");

	std::cout << "Press enter to continue... ";
	return;
}

int InventoryMenu::exit() {
	std::cout << "Exiting.\n";
	std::cout << "Press enter to continue... \n";
	return 0;
}

ShopMenu::ShopMenu(Player* p) {
	// Initialize the player variable.
	player = p;
	// Initialize a new shop.
	shop = new Shop(); // CREATES A NEW SHOP EVERYTIME

	std::cout << "Shop Menu\n";
	int choice{ KEY_UP };
	// The highlighted yellow text, when Enter key is pressed this option is selected.
	int index{ 1 };
	do {
		clear();

		std::vector<std::string> options = {
			"1. Browse Wares",
			"2. Buy an Item",
			"3. Sell an Item",
			"4. Chat with Shopkeeper",
			"5. Exit"
		};
		options[index - 1] = yellow(options[index - 1]);
		for (int i = 0; i < options.size(); i++) {
			std::cout << options[i] << "\n";
		}

		choice = _getch(); // Take input from the keyboard.

		const int INDEX_MAX = 5;
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
			}
		}

		switch (choice) {
		case KEY_ONE:
			browse();
			_getch(); // Wait for keypress before redrawing.
			break;
		case KEY_TWO:
			buy();
			_getch();
			break;
		case KEY_THREE:
			sell();
			_getch();
			break;
		case KEY_FOUR:
			chat();
			_getch();
			break;
		case KEY_FIVE:
			exit();
			_getch();
			break;
		default:
			break;
		}
	} while (choice != KEY_FIVE);
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
	std::cout << "Buying items.\n";
	std::cout << "Press enter to continue... \n";
	return;
	//// KEY_LEFT and KEY_RIGHT are included so as not to trigger as bad input but they are unused.
	//std::unordered_set<int> validKeys = { KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_ENTER};

	//int choice{ KEY_UP };
	//int index{ 1 }; // Tracks the highlighted menu.

	//int storeSize{ 0 };
	//while (true) {
	//	clear();
	//	std::cout << "\"Looking to buy something? Hope you've brought enough gold.\"\n";
	//	std::cout << player->getName() << "'s Gold Amount: " << player->getGold() << ".\n\n";

	//	// Build the list of shop items.
	//	LinkedList<Item*> list = shop->getInventory()->getItems();
	//	Node<Item*>* node = list.getHead();

	//	std::vector<std::string> options{};
	//	storeSize = 0;
	//	while (node) {
	//		storeSize++;
	//		std::string name = node->data->getName();
	//		int quantity = node->data->getQuantity();
	//		int cost = node->data->getCost();

	//		options.push_back(
	//			std::to_string(storeSize) + ". - " + name +
	//			" (x" + std::to_string(quantity) + ") - " +
	//			std::to_string(cost) + " gold."
	//		);

	//		node = node->nextNode;
	//	}
	//	options.push_back(std::to_string(storeSize + 1) + ". - Exit.");

	//	options[index - 1] = yellow(options[index - 1]);
	//	for (int i = 0; i < options.size(); i++) {
	//		std::cout << options[i] << "\n";
	//	}

	//	choice = _getch(); // Take input from the keyboard.

	//	switch (choice) {
	//	case KEY_UP:
	//		if (storeSize == 0) index = 1; // No items in store.
	//		else if (index > 1) index--;
	//		else index = (storeSize + 1);
	//		break;
	//	case KEY_DOWN:
	//		if (storeSize == 0) index = 1; // No items in store.
	//		else if (index < (storeSize + 1)) index++;
	//		else index = 1;
	//		break;

	//	case KEY_ENTER:
	//		// Necessary to allow break statements to break out of the loop and leave the switch statement.
	//		// Otherwise break statements would exit the switch case.
	//		while (true) {
	//			// User selects Exit
	//			if (index == storeSize + 1) {
	//				break; // Breaks the while(true)
	//			}
	//			else {
	//				// Locate the item selected in the list.
	//				Node<Item*>* itemNode = list.getHead();
	//				for (int i = 1; i < index; i++) {
	//					if (itemNode->nextNode) itemNode = itemNode->nextNode;
	//				}
	//				std::string itemName = itemNode->data->getName();

	//				int quantity{ 0 };
	//				while (true) {
	//					std::cout << "\"How many do you want to buy?\"\n";
	//					std::cin.clear();
	//					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	//					std::cin >> quantity;

	//					// Input validate that the quantity is non-negative.
	//					if (quantity <= 0) {
	//						std::cout << "\"That doesn't make sense.\"\n";
	//						continue;
	//					}

	//					// Check if the store has enough in stock.
	//					if (quantity > itemNode->data->getQuantity()) {
	//						std::cout << "\"I don't have that many in stock!\"\n";
	//						continue;
	//					}

	//					// Check if the player has enough gold.
	//					int totalCost = itemNode->data->getCost() * quantity;
	//					if (player->getGold() < totalCost) {
	//						std::cout << "\"You don't have enough gold to buy that many.\"\n";
	//						continue;
	//					}

	//					// Buy the item.
	//					player->setGold(player->getGold() - totalCost);
	//					player->getInventory()->addItem(itemName, quantity);
	//					shop->getInventory()->removeItem(itemName, quantity);

	//					std::cout << "You bought " << quantity << " x " << itemName << " for " << totalCost << " gold.\n";
	//					break;
	//				}
	//				std::cout << "Press any key to continue...\n";
	//				_getch();
	//			}
	//			break; // Breaks the while(true)
	//		}
	//		break; // Breaks the KEY_ENTER:
	//	}
	//
	//}
}

void ShopMenu::sell() {
	std::cout << "Selling items.\n";
	std::cout << "Press enter to continue... \n";
	return;
}

void ShopMenu::chat() {
	std::cout << "Chatting.\n";
	std::cout << "Press enter to continue... ";
}

int ShopMenu::exit() {
	std::cout << "Exiting.\n";
	std::cout << "Press enter to continue... \n";
	return 0;
}
