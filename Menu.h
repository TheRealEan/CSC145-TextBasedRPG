// Filename: "Menu.h"
#include <iostream>
#include "Player.h"
#ifndef MENU_H
#define MENU_H

void startBattle(Player player);

class Menu {
public:
	// Clear the screen.
	void clear();
};

class MainMenu : public Menu {
public:
	// Open the main menu.
	MainMenu();
	// Return to the overworld.
	void returnToOverworld();
	// Enter into a battle sequence.
	void enterBattle();
	// Manage inventory options.
	void manageInventory();
	// Enter the shop.
	void enterShop();
	// Chat with a Character.
	void chat();
	// Quit the game.
	int quitGame();
};

class BattleMenu : public Menu {
public:
	BattleMenu();
	void attack();
	void magic();
	void actions();
	void inventory();
	void chat();
	void flee();

	// void startBattle(Player player);
};

#endif
