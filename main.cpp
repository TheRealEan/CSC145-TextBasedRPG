// Developer Note: Highlighting text and pressing CTRL + K + C comments all highlighted text. CTRL + K + U undoes it.
#include <iostream>
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "Enemies.h"
#include "Menu.h"
#include "Extra.h"
#include "TalkingNPC.h"
#include "DialogueNode.h"
using namespace std;

int main() {
	
	Player richard("Richard the Third");
	Item plank("Plank", 1, 15);
	richard.addItemToInventory(new Item("Sword", 5, 200), false);
	richard.addItemToInventory(new Item("Shield", 1, 150), false);
	richard.addItemToInventory(new Item("Potion", 7, 60), false);
	richard.addItemToInventory(new Item("Boots", 1, 100), false);
    bool gameRunning = true;
    system("cls");
    while (gameRunning) {
        MainMenu menu(richard);  
        menu.clear();
    }

	return 0;
}
