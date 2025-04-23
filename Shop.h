#ifndef SHOP_H
#define SHOP_H
#include <string>
#include <vector>
class Player;
class Item;
#include "Inventory.h"

//static const std::vector<std::string> potentialStoreItems {
//	"Longsword", "Chainmail", "Small Potion of Healing", "Moth-Eaten Shirt"
//};
//static const std::vector<std::string> store_one{
//	"Longsword", "Enderpearl", "Shortbow"
//};
//static const std::vector<std::string> store_two{
//	"Chainmail", "Leather Armor", "Flint and Steel"
//};
//static const std::vector<std::string> store_three{
//	"Small Potion of Healing", "Medium Potion of Healing", "Large Potion of Healing"
//};

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