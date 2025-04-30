#ifndef INVENTORY_H
#define INVENTORY_H
#include <iostream>
#include "./utilities/LinkedList.h"
class Item;

/*
There is a case to be made that int amt should NOT BE USED in any of these
functions since that's an implicit trait of an item. If so, then anytime these
functions are used then the quantity of the item must be specified correctly.
Could be a problem with the shop where a player may want some but not all
of an item's quantity.

Check back with group. -IM.
*/

class Inventory {
public:
	Inventory();
	Inventory(LinkedList<Item*> list);

	void printInventory();

	// Base Functions
	Item* const findItem(Item* item);
	void addItem(Item* item);
	void removeItem(Item* item);

	// Delegating Functions
	
	// Checks if an item is in inventory returning a pointer if it is and nullptr if not.
	Item* const findItem(std::string itemName);
	void addItem(std::string itemName);
	void addItem(std::string itemName, int amt);
	void addItem(std::string itemName, int amt, int goldCost);
	void removeItem(std::string itemName);
	void removeItem(std::string itemName, int amt);

	LinkedList<Item*> const getItems();
	int const getSize(); // Retrieves the number of unique items in the inventory.

protected:
	LinkedList<Item*> items;
	int numberOfUniqueItems{ 0 };
};

#endif
