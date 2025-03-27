#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include "Inventory.h"

class Character {
public:
	Character();
	Character(std::string nombre, int hp, int stam, int magic, int str, int dex, int arm, int money);

	std::string const getName();
	void setName(std::string nombre);
	Inventory* const getInventory();
	void setInventory(Inventory* inv);
	Character* const getTarget();
	void setTarget(Character* newTarget);

	int const getHealth();
	void setHealth(int amt);
	int const getStamina();
	void setStamina(int amt);
	int const getMana();
	void setMana(int amt);
	int const getStrength();
	void setStrength(int amt);
	int const getDexterity();
	void setDexterity(int amt);
	int const getArmor();
	void setArmor(int amt);
	int const getGold();
	void setGold(int amt);
	int const getWeightCap();
	int const getWeight();

	virtual void displayStats();

protected:
	// Derived Statistics Setter Functions
	// Should be updated when strength is updated.
	void setWeight(int amt);
	void setWeightCap(int amt);

	/*******************************************************************************************
	*** Name	  - the name of the character that is referenced in menus and dialogue.
	*** Inventory - a list of all the Items the Character can equip/unequip, consume and/or
			buy or sell at the shop.
	*** Target	  - used in battle sequences to target themselves with healing effects or
	***		enemies with harmful effects. 
	*** Health    - MAX: 100, acts as health points, affects effectiveness of healing items.
	*** Stamina   - MAX: 100, acts as action points (determine combat actions).
	*** Mana      - MAX: 100, acts as magic points which are used to cast spells.
	*** Strength  - MAX: 20, affects strength-based weapon damage, determines ability to equip
	***		strength-based weapons, and affects weight capacity.
	*** Dexterity - MAX: 20, affects dexterity-based weapon damage, determines ability to equip
	***		dexterity-based weapons, affects chance to be hit in combat, and affects chance
	***		to flee in battle.
	*** Armor     - MAX: 20, acts as armor score which affects damage blocked in combat.
	*** Gold      - MAX: SIZEOF(INT), acts as currency which can be used to buy and sell items.
	*** Weight	  - the weight of the character determined by their strength and inventory.
	*** Weight Cap. - weight capacity, determined by strength. Should not be set by the program.
	********************************************************************************************/

	// Basic/Utility Statistics
	std::string name{ "Nameless" };
	Inventory* inventory;
	Character* target;

	// Primary Statistics
	int health{ 0 };
	int stamina{ 0 };
	int mana{ 0 };
	int strength{ 0 };
	int dexterity{ 0 };
	int armor{ 0 };
	int gold{ 0 };

	// Derived Statistics
	int weight{ 0 };
	int weightCap{ 0 };
};

#endif