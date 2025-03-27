#include "Character.h"

Character::Character() : Character("Nameless", 100, 100, 100, 20, 20, 20, 100) {}
Character::Character(std::string nombre, int hp, int stam, int magic, int str, int dex, int arm, int money)
{
	setName(nombre);
	Inventory* newInventory = new Inventory();
	setInventory(newInventory);
	setTarget(nullptr);

	setHealth(hp);
	setMana(magic);
	setStrength(str);
	setDexterity(dex);
	setArmor(arm);
	setGold(money);
}

std::string const Character::getName() { return name; }
void Character::setName(std::string nombre) { name = nombre; }
Inventory* const Character::getInventory() { return inventory; }
void Character::setInventory(Inventory* inv) { inventory = inv; }
Character* const Character::getTarget() { return target; }
void Character::setTarget(Character* newTarget) { target = newTarget; }

int const Character::getHealth() { return health; }
void Character::setHealth(int amt) {
	if (amt > 100) health = 100;
	else if (amt < 0) health = 0;
	else health = amt;
}
int const Character::getStamina() { return stamina; }
void Character::setStamina(int amt) {
	if (amt > 100) stamina = 100;
	else if (amt < 0) stamina = 0;
	else stamina = amt;
}
int const Character::getMana() { return mana; }
void Character::setMana(int amt) {
	if (amt > 100) mana = 100;
	else if (amt < 0) mana = 0;
	else mana = amt;
}
int const Character::getStrength() { return strength; }
void Character::setStrength(int amt) {
	if (amt > 20) strength = 20;
	else if (amt < 0) strength = 0;
	else strength = amt;
}
int const Character::getDexterity() { return dexterity; }
void Character::setDexterity(int amt) {
	if (amt > 20) dexterity = 20;
	else if (amt < 0) dexterity = 0;
	else dexterity = amt;
}
int const Character::getArmor() { return armor; }
void Character::setArmor(int amt) {
	if (amt > 20) armor = 20;
	else if (amt < 0) armor = 0;
	else armor = amt;
}
int const Character::getGold() { return gold; }
void Character::setGold(int amt) {
	if (amt < 0) gold = 0;
	else gold = amt;
}
int const Character::getWeight() { return weight; }
void Character::setWeight(int amt) {
	if (amt < 0) weight = 0;
	else weight = amt;
}
int const Character::getWeightCap() { return weightCap; }
void Character::setWeightCap(int amt) {
	if (amt < 0) weightCap = 0;
	else weightCap = amt;
}

void Character::displayStats() {
	std::cout << "Character: " << getName() << "\n"
		<< "Health: " << getHealth() << "\n"
		<< "Stamina: " << getStamina() << "\n"
		<< "Mana: " << getMana() << "\n"
		<< "Strength: " << getStrength() << "\n"
		<< "Dexterity: " << getDexterity() << "\n"
		<< "Armor: " << getArmor() << "\n"
		<< "Gold: " << getGold() << "\n";
}
