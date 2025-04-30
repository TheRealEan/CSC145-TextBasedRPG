#include "Shop.h"
#include "Inventory.h"
#include "Item.h"
#include "Player.h"
#include "./utilities/Roll.h"

Shop::Shop() : inventory(new Inventory()) {}

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