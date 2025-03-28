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
	talkingNPC* npc = new talkingNPC("Senor Brown", 4); //four node of dialogue, first the inital 0 and then 1, 2, and 3
    vector<int> next = {1, 2, 3};
    npc->setDialogue(0, new DialogueNode("Hey, you. You're finally awake. You were trying to cross the border, right? Walked right into that Imperial ambush, same as us, and that thief over there.", //this is dialgoue 0
        "1: Oui\n2: Non non\n3: Shut up",
        next));

    vector<int> next1 = {}; 
    npc->setDialogue(1, new DialogueNode("Darn you Stormcloaks. Skyrim was fine until you came along. Empire was nice and lazy.", //this is dialgoue 1
        "Press any key to continue",
        next1));

    vector<int> next2 = {}; 
    npc->setDialogue(2, new DialogueNode("D:", //this is dialgoue 2
        "Press any key to continue",
        next2));

    vector<int> next3 = {};
    npc->setDialogue(3, new DialogueNode("Bruh", //this is dialgoue 3
        "Press any key to continue",
        next3));
    npc->printDialogue(0);
	Player richard("Richard the Third");
	Item plank("Plank", 1, 15);
	plank.display();
	richard.addItemToInventory(new Item("Sword", 5, 200), false);
	richard.addItemToInventory(new Item("Shield", 1, 150), false);
	richard.addItemToInventory(new Item("Potion", 7, 60), false);
	richard.addItemToInventory(new Item("Boots", 1, 100), false);
    bool gameRunning = true;
    while (gameRunning) {
        MainMenu menu(richard);  
        menu.clear();
    }

	return 0;
}
