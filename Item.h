// "Filename: "Item.h"
#include <string>
#ifndef ITEM_H
#define ITEM_H

class Item {
public:
	std::string name;
};

class EquippableItem : public Item {
	// void equip();
	// void unequip();
};

class Consumable : public Item {
	// void use();
};

// ------------------------------------------------------------------ //

/* Weapons */

class IronSword : EquippableItem {
	// On equip it should add an attack function to player.
};

class WiiiRemote : EquippableItem {
	// Nintendo can't sue us with three i's.
};

/* Armor */

class AirJordans : EquippableItem {
	// Stamina increase, for sure.
};

class DiamondArmor : EquippableItem {
	// On equip it should increase hit percentage to player.
};

/* Consumables */
class PotionOfHealing : Consumable {
	// Add health stat increase to player, should not go above max health.
};

class Cookie : Consumable {
	// Add health or stamina increase to player.
};

class Ibuprofen : Consumable {
	// Probably magic increase or something, idk it's ibuprofen.
};

#endif
