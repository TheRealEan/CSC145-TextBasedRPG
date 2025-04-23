#include "Item.h"

// Define lists which can be iterated over to check the existence of items in inventories.
std::vector<std::string> listOfWeapons{ "Longsword" };
std::vector<std::string> listOfArmor{ "Chainmail" };
std::vector<std::string> listOfPotions{ "Samll Potion of Healing" };

std::vector<std::string> listOfConsumables;
std::vector<std::string> listOfEquippables;

std::vector<std::string> listOfAllItems;

static bool initItems() {
	listOfConsumables.insert(listOfConsumables.end(), listOfPotions.begin(), listOfPotions.end());

	listOfEquippables.insert(listOfEquippables.end(), listOfWeapons.begin(), listOfWeapons.end());
	listOfEquippables.insert(listOfEquippables.end(), listOfArmor.begin(), listOfArmor.end());

	listOfAllItems.insert(listOfAllItems.end(), listOfEquippables.begin(), listOfEquippables.end());
	listOfAllItems.insert(listOfAllItems.end(), listOfConsumables.begin(), listOfConsumables.end());
	return true;
}
// Forces the function to run exactly once at program startup.
// A neat trick using static.
static bool itemInitialized = initItems();

// Try to avoid making items directly; use the create() function.
Item::Item() : Item("Nameless", 1, 0) {}
Item::Item(std::string nombre) : Item(nombre, 1, 0) {}
Item::Item(std::string nombre, int amt) : Item(nombre, amt, 0) {}
Item::Item(std::string nombre, int amt, int goldCost) : name{ nombre }, quantity{ amt }, cost{ goldCost } {}

Item* Item::create(std::string itemName) { return create(itemName, 1, 0); }
Item* Item::create(std::string itemName, int amt) { return create(itemName, amt, 0); }
Item* Item::create(std::string itemName, int amt, int goldCost) {
	// The goldCost parameter is ignored if the item is a derived class.
	// These have established gold costs in their constructors.
	if (itemName == "Longsword") {
		return new Longsword(amt);
	}
	else if (itemName == "Chainmail") {
		return new Chainmail(amt);
	}
	else if (itemName == "Small Potion of Healing") {
		return new SmallPotionOfHealing(amt);
	}
	else {
		return new Item(itemName, amt, goldCost);
	}
	return nullptr;
}

std::string const Item::getName() { return name; }
void Item::setName(std::string nombre) { name = nombre; }
int const Item::getQuantity() { return quantity; }
void Item::setQuantity(int amt) {
	if (amt < 0) quantity = 0;
	else quantity = amt;
}
int const Item::getCost() { return cost; }
void Item::setCost(int amt) {
	if (amt < 0) cost = 0;
	else cost = amt;
}

Equippable::Equippable() : Item("Nameless", 1, 0) {}
Equippable::Equippable(std::string nombre) : Item(nombre, 1, 0) {}
Equippable::Equippable(std::string nombre, int amt) : Item(nombre, amt, 0) {}
Equippable::Equippable(std::string nombre, int amt, int goldCost) : Item(nombre, amt, goldCost) {}

Consumable::Consumable() : Item("Nameless", 1, 0) {}
Consumable::Consumable(std::string nombre) : Item(nombre, 1, 0) {}
Consumable::Consumable(std::string nombre, int amt) : Item(nombre, amt, 0) {}
Consumable::Consumable(std::string nombre, int amt, int goldCost) : Item(nombre, amt, goldCost) {}

/**********************************************
******************* Items *********************
***********************************************/

/**********************************************
******************* Weapons *******************
***********************************************/

Longsword::Longsword() : Longsword(1) {}
Longsword::Longsword(int amt) : Equippable("Longsword", amt, 25) {}
Slot Longsword::getSlot() const {
	return Slot::LEFT_HAND;
}
void Longsword::equip(Character* target) {
	// Add attack function to Character's attack list.
	return;
}
void Longsword::unequip(Character* target) {
	// Remove attack function from Character's attack list.
	return;
}
//void Longsword::dealDamage(Character* target) {
//	target->setHealth(target->getHealth() - roll(1, 8));
//}

/**********************************************
******************* Armor *********************
***********************************************/

Chainmail::Chainmail() : Chainmail(1) {}
Chainmail::Chainmail(int amt) : Equippable("Chainmail", amt, 50) {
	//statBonus[StatBonus::ARMOR] = 3;
}
Slot Chainmail::getSlot() const {
	return Slot::TORSO;
}
void Chainmail::equip(Character* target) {
	//target->setArmor(target->getArmor() + 3);
	return;
}
void Chainmail::unequip(Character* target) {
	//target->setArmor(target->getArmor() - 3);
	return;
}

/**********************************************
******************* Potions *******************
***********************************************/

SmallPotionOfHealing::SmallPotionOfHealing() : SmallPotionOfHealing(1) {}
SmallPotionOfHealing::SmallPotionOfHealing(int amt) : Consumable("Small Potion of Healing", amt, 75) {}
void SmallPotionOfHealing::consume(Character* target) {
	// Add health.
	return;
}