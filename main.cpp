#include <iostream>
#include "Map.h"
#include "Menu.h"
#include "Player.h"

int main() {

	// Initialize a player object.
	Player* player{ nullptr };

	// Create a Player Selection Menu to get the user to choose a player model.
	PlayerSelectMenu playerMenu;
	if (playerMenu.getSelectedPlayer()) {
		player = playerMenu.getSelectedPlayer();
	}
	else {
		return 0;
	}

	Map* ohio = new Map(player);
	ohio->getIndex()->execLocation(player);

	// Create a Main Menu to navigate.
	// MainMenu menu(player);

	return 0;
}