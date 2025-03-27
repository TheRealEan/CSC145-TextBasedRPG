#ifndef SHOP_H
#define SHOP_H
#include <vector>
#include "Player.h"
#include "Item.h"
#include "Inventory.h"

// Forward Declarations
class Item;

static const std::vector<std::string> potentialStoreItems {
	"Longsword", "Chainmail", "Small Potion of Healing", "Moth-Eaten Shirt"
};

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
	Inventory* inventory;
};

#endif