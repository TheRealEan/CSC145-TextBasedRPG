#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <vector>
class Character;

// Inventory slots available for a character.
enum class Slot { LEFT_HAND, RIGHT_HAND, HEAD, TORSO, LEGS, FEET };
// Stats that can be boosted by items and/or spells.
enum class StatBonus { HEALTH, STAMINA, MANA, STRENGTH, DEXTERITY, ARMOR };

// Define lists which can be iterated over to check the existence of items in inventories.
extern std::vector<std::string> listOfWeapons;
extern std::vector<std::string> listOfArmor;
extern std::vector<std::string> listOfConsumables;
extern std::vector<std::string> listOfEquippables;
extern std::vector<std::string> listOfAllItems;

static bool initItems();
// Forces the function to run exactly once at program startup.
// A neat trick using static.
extern bool itemInitialized;

class Item {
public:
	// NOTE THESE CONSTRUCTORS CANNOT MATCH DERIVED CLASSES SO USE THE CREATE() FUNCTION INSTEAD
	Item();
	Item(std::string nombre);
	Item(std::string nombre, int amt);
	Item(std::string nombre, int amt, int goldCost);
	~Item() = default;

	// Creates items, matching item names to their correct derived class where applicable.
	// Update the primary create() function when addeing new items.
	// REPLACES making "new Item(parameters)"; these do not create derived classes.
	static Item* create(std::string itemName);
	static Item* create(std::string itemName, int quantity);
	static Item* create(std::string itemName, int quantity, int goldCost);

	std::string const getName();
	void setName(std::string nombre);
	int const getQuantity();
	void setQuantity(int amt);
	int const getCost();
	void setCost(int amt);


protected:
	std::string name;
	int quantity;
	int cost;
};

class Equippable : public Item {
public:
	Equippable();
	Equippable(std::string nombre);
	Equippable(std::string nombre, int amt);
	Equippable(std::string nombre, int amt, int goldCost);
	~Equippable() = default;

	virtual Slot getSlot() const = 0;
	virtual void equip(Character* target) = 0;
	virtual void unequip(Character* target) = 0;
};

class Consumable : public Item {
public:
	Consumable();
	Consumable(std::string nombre);
	Consumable(std::string nombre, int amt);
	Consumable(std::string nombre, int amt, int goldCost);
	~Consumable() = default;

	virtual void consume(Character* target) = 0;
};

/**********************************************
******************* Items *********************
***********************************************/

/**********************************************
******************* Weapons *******************
***********************************************/

class Longsword : public Equippable {
public:
	Longsword();
	Longsword(int amt);

	Slot getSlot() const override;
	void equip(Character* target) override;
	void unequip(Character* target) override;

private:
	void dealDamage(Character* target);
};

/**********************************************
******************* Armor *********************
***********************************************/

class Chainmail : public Equippable {
public:
	Chainmail();
	Chainmail(int amt);

	Slot getSlot() const override;
	void equip(Character* target) override;
	void unequip(Character* target) override;
};

/**********************************************
******************* Potions *******************
***********************************************/

class SmallPotionOfHealing : public Consumable {
public:
	SmallPotionOfHealing();
	SmallPotionOfHealing(int amt);

	void consume(Character* target) override;
};

#endif