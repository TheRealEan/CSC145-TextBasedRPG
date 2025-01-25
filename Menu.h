// Filename: "Menu.h"
#include <iostream>
#ifndef MENU_H
#define MENU_H

class Menu {
public:
	// Main Menu Functions

	void mainMenu(); // Open the main menu.
	void returnToOverworld(); // Return to the overworld.
	void enterBattle(); // Enter into a battle sequence.
	void manageInventory(); // Manage inventory options.
	void enterShop(); // Enter the shop.
	void chat(); // Chat with a Character.
	int quitGame(); // Quit the game.
};

#endif
