#include <iostream>
#include "Inventory.h"

Inventory::Inventory() : Inventory(LinkedList<Item*>()) {}
Inventory::Inventory(LinkedList<Item*> list) : items{ list } {
	// Dynamically identifies the number of items in the list when constructed.
	Node<Item*>* index = items.getHead();
	while (index) {
		numberOfUniqueItems++;
		index = index->nextNode;
	}
}

void Inventory::printInventory() {
	std::cout << "\n--- Inventory ---\n";
	Node<Item*>* current = items.getFirst();
	while (current) {
		std::cout << "- " << current->data->getName() << " (x" << current->data->getQuantity() << ") - " << current->data->getCost() << " gold.\n";
		current = current->nextNode;
	}
	std::cout << "-----------------\n";
}

Item* const Inventory::findItem(Item* item) {
	Node<Item*>* current = items.getFirst();
	while (current) {
		if (current->data->getName() == item->getName()) {
			return current->data;
		}
		current = current->nextNode;
	}
	return nullptr;
}

void Inventory::addItem(Item* item) {
	Item* found = findItem(item);
	if (found) {
		// Sets the quantity of the found item to its current quantity plus new item's quantity.
		found->setQuantity(found->getQuantity() + item->getQuantity());
	}
	else {
		items.pushBack(item);
		item->setQuantity(item->getQuantity());
		numberOfUniqueItems++; // Describes a new unique item being added to the inventory.
	}
}

void Inventory::removeItem(Item* item) {
	Item* found = findItem(item);
	if (!found) return;
	Node<Item*>* current = items.getHead();
	while (current) {
		if (current->data == found) {
			items.setIndex(current);
			break;
		}
		current = current->nextNode;
	}
	int currentQuantity = items.getIndex()->data->getQuantity();
	if (item->getQuantity() >= currentQuantity) {
		items.deleteCurrent();
		numberOfUniqueItems--;
	}
	else {
		items.getIndex()->data->setQuantity(currentQuantity - item->getQuantity());
	}
}

// Delegating Functions

Item* const Inventory::findItem(std::string itemName) { // Delegating function
	Item* newItem = Item::create(itemName);
	return findItem(newItem);
}

void Inventory::addItem(std::string itemName) {
	Item* newItem = Item::create(itemName, 1);
	addItem(newItem);
}

void Inventory::addItem(std::string itemName, int amt) {
	Item* newItem = Item::create(itemName, amt);
	addItem(newItem);
}

void Inventory::removeItem(std::string itemName) {
	Item* newItem = Item::create(itemName, 1);
	removeItem(newItem);
}

void Inventory::removeItem(std::string itemName, int amt) {
	Item* newItem = Item::create(itemName, amt);
	removeItem(newItem);
}

LinkedList<Item*> const Inventory::getItems() { return items; }
int const Inventory::getSize() { return numberOfUniqueItems; }
