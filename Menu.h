#ifndef MENU_H
#define MENU_H
#include <functional> // Allows std::function
class Enemy;
class MapNode;
class Player;
class Shop;

class OptionNode {
public:
	using Action = std::function<void()>;

	std::string description;
	Action action;
	OptionNode* prevNode{ nullptr };
	OptionNode* nextNode{ nullptr };

	OptionNode(std::string desc, Action act)
		: description(desc), action(act) {}

	void execute() { if (action) action(); }
};

class Menu {
public:
	Menu() = default;
	virtual ~Menu() = default;

	void clear();

	void yellow();
	std::string yellow(std::string text);

	Player* getPlayer();
	void setPlayer(Player* p);

protected:
	Player* player{ nullptr };
};

class StartMenu : public Menu {
public:
	StartMenu();
	virtual ~StartMenu() = default;

	void newGame();
	void continueGame();
	void quitGame();

	MapNode* getLastLocation();
	void setLastLocation(MapNode* node);

protected:
	MapNode* lastLocation{ nullptr }; // The last node the player was on. Puts them back into the game.
};

class PlayerSelectMenu : public Menu {
public:
	PlayerSelectMenu();

	// Adds a player type to selected player and exits the menu.
	void playWarrior();
	void playRogue();
	void playMage();
	int returnToStart();

	Player* getSelectedPlayer();
	void setSelectedPlayer(Player* play);

protected:
	Player* selectedPlayer{ nullptr };
};

class MainMenu : public Menu {
public:
	MainMenu(Player* p);
	void returnToOverworld();
	void displayStats();
	void enterBattle();
	void manageInventory();
	void enterShop();
	void chat();
	int quitGame();
};

class BattleMenu : public Menu {
public:
	BattleMenu(Player* p);
	BattleMenu(Player* p, Enemy* e);
	void attacks(); // Opens attack options submenu.
	void magic(); // Opens a spell options submenu.
	void block();
	void displayStats(); // Displays the player's stats.
	void inventory(); // Opens the player's inventory.
	void chat(); // Opens up a dialogue with an enemy.
	void flee(); // Allows the player to flee the battle.
	Enemy* enemy{ nullptr };  

};

class InventoryMenu : public Menu {
public:
	InventoryMenu(Player* p);
	void manageInventory(); // Allows for equipping, unequipping, consuming items, and removing items. 

	// Testing options.
	void viewInventory();
	void addItem();
	void removeItem();
	// To Be Added - void equip() // equips/unequips equippables
	// To Be Added - void use() // uses consumables
	int exit();
};

class ShopMenu : public Menu {
public:
	ShopMenu(Player* p); // Generates a random shop.
	ShopMenu(Player* p, Shop* shop);
	void browse();
	void buy();
	void sell();
	void chat();
	int exit();

protected:
	Shop* shop{ nullptr };
};

#endif
