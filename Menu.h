#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <vector>
#include "Player.h"
#include "Shop.h"

class Menu {
public:
	Menu() = default;
	virtual ~Menu() = default;

	void clear();

	void yellow();
	std::string yellow(std::string text);

protected:
	Player* player{ nullptr };
};

class PlayerSelectMenu : public Menu {
public:
	PlayerSelectMenu();

	// Adds a player type to selected player and exits the menu.
	void playWarrior();
	void playRogue();
	void playMage();
	int quitGame();

	Player* getSelectedPlayer();
	void setSelectedPlayer(Player* play);

private:
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

class InventoryMenu : public Menu {
public:
	InventoryMenu(Player* p);
	void viewInventory();
	void addItem();
	void removeItem();
	// To Be Added - void equip() // equips/unequips equippables
	// To Be Added - void use() // uses consumables
	int exit();
};

class ShopMenu : public Menu {
public:
	ShopMenu(Player* p);
	void browse();
	void buy();
	void sell();
	void chat();
	int exit();

protected:
	Shop* shop{ nullptr };
};

#endif
