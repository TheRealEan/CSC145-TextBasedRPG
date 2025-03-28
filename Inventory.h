#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include "Item.h"
#include "LinkedList.h"
using namespace std;

class Inventory {
private:
    LinkedList<Item*> items;  // Linked list to store items
    int numItems = 0;         // Track the number of unique items

public:
    Inventory();
    void addItem(Item* item, bool battle);
    void removeItem(string itemName);
    Item* findItem(string name);
    void printInventory();
};

#endif
