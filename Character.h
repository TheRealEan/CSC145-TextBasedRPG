#ifndef CHARACTER_H
#define CHARACTER_H
#include <cmath>
#include <map>
#include <string>

class Inventory;
class Equippable;

class Character {
public:
	Character();
	Character(std::string nombre);
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

	// A die-roll based attack that adds the appropriate score.
	void meleeAttack(); // Uses strength.
	void rangedAttack(); // Uses dexterity.
	void spellAttack(); // Uses mana.
	void setBlock(bool a);
	bool isBlocking;

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
	*** Health    - acts as health points, affects effectiveness of healing items.
	*** Stamina   - acts as action points (determine combat actions).
	*** Mana      - acts as magic points which are used to cast spells.
	*** Strength  - affects strength-based weapon damage, determines ability to equip
	***		strength-based weapons, and affects weight capacity.
	*** Dexterity - affects dexterity-based weapon damage, determines ability to equip
	***		dexterity-based weapons, affects chance to be hit in combat, and affects chance
	***		to flee in battle.
	*** Armor     - acts as armor score which affects damage blocked in combat.
	*** Gold      - acts as currency which can be used to buy and sell items.
	*** Weight	  - the weight of the character determined by their strength and inventory.
	*** Weight Cap. - weight capacity, determined by strength. Should not be set by the program.
	********************************************************************************************/

	// Basic/Utility Statistics
	std::string name{ "Nameless" };
	Inventory* inventory{ nullptr };
	Character* target{ nullptr };

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