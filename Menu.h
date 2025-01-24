/*
* Developer's Note: The menu class is designed to offer modularity to the options made available to the user.
*/
#include <iostream>
#ifndef MENU_H
#define MENU_H

class Menu {
public:
	// Open the main menu.
	void mainMenu();
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

#endif