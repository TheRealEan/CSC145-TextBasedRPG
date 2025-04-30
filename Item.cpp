// Item.cpp
#include "Item.h"
#include "Player.h"

// Define lists which can be iterated over to check the existence of items in inventories.
std::vector<std::string> listOfWeapons{ "Really Big Stick", "Longbow", "Longsword", "Maul", "Scimitar", "Shortbow", "Shortsword", "Sling", "Enederpearl"};
std::vector<std::string> listOfArmor{ "Chainmail", "Leather Armor", "Diamond Boots" };
std::vector<std::string> listOfPotions{
    "Small Potion of Healing",
    "Medium Potion of Healing",
    "Large Potion of Healing"
};
std::vector<std::string> listOfValuables{ "Enderpearl", "Flint and Steel"};

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
bool itemInitialized = initItems();

// Item constructors
Item::Item() : Item("Nameless", 1, 0) {}
Item::Item(std::string nombre) : Item(nombre, 1, 0) {}
Item::Item(std::string nombre, int amt) : Item(nombre, amt, 0) {}
Item::Item(std::string nombre, int amt, int goldCost)
    : name{ nombre }, quantity{ amt }, cost{ goldCost }, equipped{ false } {
}

// Factory
Item* Item::create(std::string itemName) {
    return create(itemName, 1, 0, false);
}
Item* Item::create(std::string itemName, int amt) {
    return create(itemName, amt, 0, false);
}
Item* Item::create(std::string itemName, int amt, int goldCost, bool equipped) {
    if (itemName == "Longsword") {
        return new Longsword(amt);
    }
    else if (itemName == "Flint and Steel") {
        return new FlintNSteel(amt);
    }
    else if (itemName == "Shortbow") {
        return new Shortbow(amt);
    }
    else if (itemName == "Enderpearl") {
        return new Enderpearl(amt);
    }
    else if (itemName == "Chainmail") {
        return new Chainmail(amt);
    }
    else if (itemName == "Leather Armor") {
        return new LeatherArmor(amt);
    }
    else if (itemName == "Small Potion of Healing") {
        return new SmallPotionOfHealing(amt);
    }
    else if (itemName == "Medium Potion of Healing") {
        return new MediumPotionOfHealing(amt);
    }
    else if (itemName == "Large Potion of Healing") {
        return new LargePotionOfHealing(amt);
    }
    else {
        return new Item(itemName, amt, goldCost);
    }
	// The goldCost parameter is ignored if the item is a derived class.
	// These have established gold costs in their constructors.
	if (itemName == "Really Big Stick") {
		return new BigStick(amt);
	}
	else if (itemName == "Longbow") {
		return new Longbow(amt);
	}
	else if (itemName == "Maul") {
		return new Maul(amt);
	}
	else if (itemName == "Scimitar") {
		return new Scimitar(amt);
	}
	else if (itemName == "Shortsword") {
		return new Shortsword(amt);
	}
	else if (itemName == "Sling") {
		return new Sling(amt);
	}
	else if (itemName == "Chainmail") {
		return new Chainmail(amt);
	}
	else if (itemName == "Leather Armor") {
		return new LeatherArmor(amt);
	}
	else if (itemName == "Diamond Boots") {
		return new DiamondBoots(amt);
	}
	else if (itemName == "Small Potion of Healing") {
		return new SmallPotionOfHealing(amt);
	}
	else if (itemName == "Medium Potion of Healing") {
		return new MediumPotionOfHealing(amt);
	}
	else if (itemName == "Large Potion of Healing") {
		return new LargePotionOfHealing(amt);
	}
	else if (itemName == "Enderpearl") {
		return new Enderpearl(amt);
	}
	else if (itemName == "Flint and Steel") {
		return new FlintNSteel(amt);
	}
	else {
		return new Item(itemName, amt, goldCost);
	}
	return nullptr;
}

// Accessors
std::string const Item::getName() { return name; }
int const Item::getQuantity() { return quantity; }
bool Item::getEquipped() { return equipped; }
int const Item::getCost() { return cost; }

// Mutators
void Item::setName(std::string nombre) { name = nombre; }
void Item::setQuantity(int amt) { quantity = (amt < 0 ? 0 : amt); }
void Item::setEquipped(bool e) { equipped = e; }
void Item::setCost(int amt) { cost = (amt < 0 ? 0 : amt); }

// Equippable constructors
Equippable::Equippable() : Item("Nameless", 1, 0) {}
Equippable::Equippable(std::string nombre) : Item(nombre, 1, 0) {}
Equippable::Equippable(std::string nombre, int amt) : Item(nombre, amt, 0) {}
Equippable::Equippable(std::string nombre, int amt, int goldCost)
    : Item(nombre, amt, goldCost) {
}

// Consumable constructors
Consumable::Consumable() : Item("Nameless", 1, 0) {}
Consumable::Consumable(std::string nombre) : Item(nombre, 1, 0) {}
Consumable::Consumable(std::string nombre, int amt) : Item(nombre, amt, 0) {}
Consumable::Consumable(std::string nombre, int amt, int goldCost)
    : Item(nombre, amt, goldCost) {
}

/**********************************************
******************* Items *********************
***********************************************/

// Longsword
/**********************************************
******************* Weapons *******************
***********************************************/

BigStick::BigStick() : BigStick(1) {}
BigStick::BigStick(int amt) : Equippable("Really Big Stick", amt, 2) {}
Slot BigStick::getSlot() const {
	return Slot::LEFT_HAND;
}
void BigStick::equip(Character* target) {
	originalStr = target->getStrength();
	target->setStrength(originalStr + 1); // Come on man, you chose a big stick.
	return;
}
void BigStick::unequip(Character* target) {
	target->setStrength(originalStr);
	return;
}

Longbow::Longbow() : Longbow(1) {}
Longbow::Longbow(int amt) : Equippable("Longbow", amt, 20) {}
Slot Longbow::getSlot() const {
	return Slot::LEFT_HAND;
}
void Longbow::equip(Character* target) {
	originalDex = target->getDexterity();
	target->setDexterity(originalDex + 1);
	return;
}
void Longbow::unequip(Character* target) {
	target->setDexterity(originalDex);
	return;
}

Longsword::Longsword() : Longsword(1) {}
Longsword::Longsword(int amt) : Equippable("Longsword", amt, 25) {}
Slot Longsword::getSlot() const { return Slot::LEFT_HAND; }
void Longsword::equip(Character* target) {
    target->setStrength(target->getStrength() + 25);
	return;
}
void Longsword::unequip(Character* target) {
    target->setStrength(target->getStrength() - 25);
	return;
}

Maul::Maul() : Maul(1) {}
Maul::Maul(int amt) : Equippable("Maul", amt, 12) {}
Slot Maul::getSlot() const {
	return Slot::LEFT_HAND;
}
void Maul::equip(Character* target) {
	originalStr = target->getStrength();
	target->setStrength(originalStr + 15);
	return;
}
void Maul::unequip(Character* target) {
	target->setStrength(originalStr);
	return;
}

Scimitar::Scimitar() : Scimitar(1) {}
Scimitar::Scimitar(int amt) : Equippable("Scimitar", amt, 10) {}
Slot Scimitar::getSlot() const {
	return Slot::LEFT_HAND;
}
void Scimitar::equip(Character* target) {
	originalStr = target->getStrength();
	target->setStrength(originalStr + 10);
	return;
}
void Scimitar::unequip(Character* target) {
	target->setStrength(originalStr);
	return;
}

Shortsword::Shortsword() : Shortsword(1) {}
Shortsword::Shortsword(int amt) : Equippable("Shortsword", amt, 15) {}
Slot Shortsword::getSlot() const {
	return Slot::LEFT_HAND;
}
void Shortsword::equip(Character* target) {
	originalDex = target->getDexterity();
	target->setDexterity(originalDex + 10);
	return;
}
void Shortsword::unequip(Character* target) {
	target->setDexterity(originalDex);
	return;
}

FlintNSteel::FlintNSteel() : FlintNSteel(1) {}
FlintNSteel::FlintNSteel(int amt) : Equippable("Flint and Steel", amt, 25) {}
Slot FlintNSteel::getSlot() const { return Slot::LEFT_HAND; }
void FlintNSteel::equip(Character* target) {
    target->setStrength(target->getStrength() + 25);
}
void FlintNSteel::unequip(Character* target) {
    target->setStrength(target->getStrength() - 25);
}
Sling::Sling() : Sling(1) {}
Sling ::Sling(int amt) : Equippable("Sling", amt, 10) {}
Slot Sling::getSlot() const {
	return Slot::LEFT_HAND;
}
void Sling::equip(Character* target) {
	originalDex = target->getDexterity();
	target->setDexterity(originalDex + 20); // Rocks hurt.
	return;
}
void Sling::unequip(Character* target) {
	target->setDexterity(originalDex);
	return;
}

Enderpearl::Enderpearl() : Enderpearl(1) {}
Enderpearl::Enderpearl(int amt) : Equippable("Enderpearl", amt, 1000) {}
Slot Enderpearl::getSlot() const { return Slot::LEFT_HAND; }
void Enderpearl::equip(Character* target) {
    target->setMana(target->getMana() + 999);
}
void Enderpearl::unequip(Character* target) {
    target->setMana(target->getMana() - 999);
}

Shortbow::Shortbow() : Shortbow(1) {}
Shortbow::Shortbow(int amt) : Equippable("Shortbow", amt, 40) {}
Slot Shortbow::getSlot() const { return Slot::LEFT_HAND; }
void Shortbow::equip(Character* target) {
	target->setDexterity(target->getDexterity() + 40);
}
void Shortbow::unequip(Character* target) {
	target->setDexterity(target->getDexterity() - 40);
}


// Chainmail
Chainmail::Chainmail() : Chainmail(1) {}
Chainmail::Chainmail(int amt) : Equippable("Chainmail", amt, 50) {}
Slot Chainmail::getSlot() const { return Slot::TORSO; }
void Chainmail::equip(Character* target) {
    target->setArmor(target->getArmor() + 35);
	return;
}
void Chainmail::unequip(Character* target) {
    target->setArmor(target->getArmor() - 35);
	return;
}


DiamondBoots::DiamondBoots() : DiamondBoots(1) {}
DiamondBoots::DiamondBoots(int amt) : Equippable("Diamond Boots", amt, 150) {
	//statBonus[StatBonus::ARMOR] = 3;
}
Slot DiamondBoots::getSlot() const {
	return Slot::FEET;
}
void DiamondBoots::equip(Character* target) {
	originalArm = target->getArmor();
	target->setArmor(originalArm + 75);
	return;
}
void DiamondBoots::unequip(Character* target) {
	target->setArmor(originalArm);
	return;
}

// Leather Armor
LeatherArmor::LeatherArmor() : LeatherArmor(1) {}
LeatherArmor::LeatherArmor(int amt) : Equippable("Leather Armor", amt, 35) {}
Slot LeatherArmor::getSlot() const { return Slot::TORSO; }
void LeatherArmor::equip(Character* target) {
    target->setArmor(target->getArmor() + 20);
}
void LeatherArmor::unequip(Character* target) {
    target->setArmor(target->getArmor() - 20);
}

// Potions
SmallPotionOfHealing::SmallPotionOfHealing() : SmallPotionOfHealing(1) {}
SmallPotionOfHealing::SmallPotionOfHealing(int amt)
    : Consumable("Small Potion of Healing", amt, 75) {
}
void SmallPotionOfHealing::consume(Character* target) {
    target->setHealth(target->getHealth() + 30);
}

MediumPotionOfHealing::MediumPotionOfHealing() : MediumPotionOfHealing(1) {}
MediumPotionOfHealing::MediumPotionOfHealing(int amt)
    : Consumable("Medium Potion of Healing", amt, 150) {
}
void MediumPotionOfHealing::consume(Character* target) {
    target->setHealth(target->getHealth() + 60);
}

LargePotionOfHealing::LargePotionOfHealing() : LargePotionOfHealing(1) {}
LargePotionOfHealing::LargePotionOfHealing(int amt)
    : Consumable("Large Potion of Healing", amt, 300) {
}
void LargePotionOfHealing::consume(Character* target) {
    target->setHealth(target->getHealth() + 100);
}


/**********************************************
***************** Valuables *******************
***********************************************/

