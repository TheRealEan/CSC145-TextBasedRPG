#pragma once
#include<iostream>

using namespace std;

//I moved these functions into their own class to keep things more modular

class menu {
public:
	void mainMenu();

	void returnToOverworld();

	void enterBattle();

	void manageInventory();

	void enterShop();

	void chat();

	int quitGame();
};
