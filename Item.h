// "Filename: "Item.h"
#include <string>


#include <string>

class Item {
public:
    std::string name;
    int quantity;

    Item(std::string itemName, int qty) : name(itemName), quantity(qty) {}
    void display() const {
        std::cout << "\033[1;32m" << name << "\033[0m"  // Green for item name
            << " (x\033[1;34m" << quantity << "\033[0m)"  // Blue for quantity
            << std::endl;
    }
};

class EquippableItem : public Item {
    using Item::Item; // Inherit constructor
};

class Consumable : public Item {
    using Item::Item; // Inherit constructor
};

//YOU CAN STILL ADD OTHER THINGIES IT WAS CAUSING GLITCHESAND I WNNA GO TO BED
