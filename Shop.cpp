#include "Shop.h"
#include "Inventory.h"
#include "Item.h"
#include "Player.h"
#include "./utilities/Roll.h"

Shop::Shop() : inventory(new Inventory()) {

	//std::vector<std::string> shopItems;
	//switch (roll(1, 3)) {
	//case 1:
	//	shopItems = store_one;
	//	break;
	//case 2:
	//	shopItems = store_two;
	//	break;
	//case 3:
	//	shopItems = store_three;
	//	break;
	//}

	//// Probablistically generate items in the store.
	//for (int i = 0; i < shopItems.size(); i++) {
	//	int addItemScore = 100; // When the roll is under this value, add an item.
	//	while (roll(1, 100) < addItemScore) {
	//		inventory->addItem(shopItems[i]);
	//		addItemScore -= 15;
	//	}
	//}
}

Inventory* const Shop::getInventory() { return inventory; }
void Shop::setInventory(Inventory* inv) { inventory = inv; }

void Shop::browse() {
	inventory->printInventory();
}

void Shop::buy(Player* player, Item* item) {
	if (player->getGold() >= item->getCost()) {
		player->setGold(player->getGold() - item->getCost());
		player->getInventory()->addItem(item);
		inventory->removeItem(item);
	}
	else {
		std::cout << "You don't have enough funds.\n";
	}
}

void Shop::sell(Player* player, Item* item) {
	if (player->getInventory()->findItem(item)->getName() == item->getName()) {
		player->setGold(player->getGold() + item->getCost());
		inventory->addItem(item);
		player->getInventory()->removeItem(item);
	}
	else {
		std::cout << "You don't have that item.\n";
	}
}