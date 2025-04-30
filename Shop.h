#ifndef SHOP_H
#define SHOP_H
#include <string>
#include <vector>
class Player;
class Item;
#include "Inventory.h"

class Shop {
public:
	Shop();
	~Shop() = default;

	Inventory* const getInventory();
	void setInventory(Inventory* inv);

	void browse(); // See the inventory of shop

	void buy(Player* player, Item* item); // Buy an item from the shop
	void sell(Player* player, Item* item); // Sell an item to the shop

protected:
	Inventory* inventory{ nullptr };
};

#endif