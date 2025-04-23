#include <iostream>
#include "Generator.h"

// Generate a random enemy for battle encounters.

Enemy* generateEnemy() {
	int randomEnemy = roll(1, 3);
	switch (randomEnemy) {
	case 1:
		return new ChineseSpyPigeon;
	case 2:
		return new DannyDevito;
	case 3:
		return new Roomba;
	default:
		return nullptr;
	}
}

// Generate shops with defined items.

Shop* generateShop() {
	Shop* newShop = new Shop;
	std::vector<std::string> shopItems;
	int randomShop = roll(1, 3);

	switch (randomShop) {
	case 1:
		shopItems = store_one;
		break;
	case 2:
		shopItems = store_two;
		break;
	case 3:
		shopItems = store_three;
		break;
	default:
		return nullptr;
	}

	// Probablistically generate items in the store.
	for (int i = 0; i < shopItems.size(); i++) {
		int addItemScore = 100; // When the roll is under this value, add an item.
		while (roll(1, 100) < addItemScore) {
			newShop->getInventory()->addItem(shopItems[i]);
			addItemScore -= 15;
		}
	}

	return newShop;
}

// Generate a random talking NPC for the player to chat with.

//TalkingNPC* generateTalkingNPC() {
//	int randomTalkingNPC = roll(1, 3);
//	switch (randomTalkingNPC) {
//	case 1:
//		return new Somebody;
//	case 2:
//		return new Somebody;
//	case 3:
//		return new Somebody;
//	}
//}