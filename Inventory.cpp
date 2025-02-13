#include "Inventory.h"

Inventory::Inventory() : numItems(0) {}
Item* Inventory::findItem(string name) {
    Node<Item*>* current = items.getFirst();
    while (current) {
        if (current->data->name == name) {
            return current->data;
        }
        current = current->nextNode;
    }
    return nullptr;
}

void Inventory::addItem(Item* item) {
    Item* existingItem = findItem(item->name);
    if (existingItem) {
        existingItem->quantity++;
        cout << item->name << " amount increased to " << existingItem->quantity << ".\n";
        delete item; 
    }
    else {
        items.pushBack(item);
        numItems++;
        cout << "\033[0;32m" << item->name << " added to inventory. \033[0;32m	\n";
    }
}

// Remove an item
void Inventory::removeItem(string itemName) {
    Node<Item*>* current = items.getFirst();
    while (current) {
        if (current->data->name == itemName) {
            current->data->quantity--;
            if (current->data->quantity <= 0) {
                items.deleteCurrent();
                numItems--;
                cout << "\033[0;31m" << itemName << " removed from inventory.\033[0;31m\n";
            }
            else {
                cout << itemName << " quantity decreased to " << current->data->quantity << ".\n";
            }
            return;
        }
        current = current->nextNode;
    }
    cout << "\n\033[0;31mItem not found!\033[0;31m\n";
}

// Print the inventory contents
void Inventory::printInventory() {
    cout << "\n--- Inventory ---\n";
    Node<Item*>* current = items.getFirst();
    while (current) {
        cout << "- " << current->data->name << " (x" << current->data->quantity << ")\n";
        current = current->nextNode;
    }
    cout << "-----------------\n";
}
