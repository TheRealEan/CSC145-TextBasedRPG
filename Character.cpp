#include "Character.h"
#include "Item.h"
#include "Inventory.h"
using namespace std;

int roll(int, int);

Character::Character() : Character("Nameless", 100, 100, 100, 20, 20, 20, 100) {}
Character::Character(std::string nombre) : Character(nombre, 100, 100, 100, 20, 20, 20, 100) {}
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
	health = amt;
}
int const Character::getStamina() { return stamina; }
void Character::setStamina(int amt) {
	stamina = amt;
}
int const Character::getMana() { return mana; }
void Character::setMana(int amt) {
	mana = amt;
}
int const Character::getStrength() { return strength; }
void Character::setStrength(int amt) {
	strength = amt;
}
int const Character::getDexterity() { return dexterity; }
void Character::setDexterity(int amt) {
	dexterity = amt;
}
int const Character::getArmor() { return armor; }
void Character::setArmor(int amt) {
	armor = amt;
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

//void equip(Slot spot, StatBonus stat, int amount) {
//	
//	modify(stat, amount);
//}
//
//void modify(StatBonus stat, int amount) {
//
//}

void Character::meleeAttack() {
	int damage = strength - (.1*target->getArmor());
	if (damage < 0) {
		damage = 0;
	}
	if (target->isBlocking == true) {
		target->setHealth(target->getHealth() - (damage / 2));
	}
	else {
		target->setHealth(target->getHealth() - damage);
	}
	target->setBlock(false);

	cout << "\033[32m" << name << " \033[0m" << "hits " << "\033[31m" << target->getName() << "\033[31m" << "for " << damage << " damage!!\n";
}

void Character::rangedAttack() {
	int damage = dexterity - (.1 * target->getArmor());
	if (damage < 0) {
		damage = 0;
	}
	if (target->isBlocking == true) {
		target->setHealth(target->getHealth() - (damage / 2));
	}
	else {
		target->setHealth(target->getHealth() - damage);
	}
	target->setBlock(false);

	cout << "\033[32m" << name << " \033[0m" << "hits " << "\033[31m" << target->getName() << " \033[0m" << "for " << damage << " damage!!\n";
}


void  Character::spellAttack() {
	int damage = mana - (.1 * target->getArmor());
	if (damage < 0) {
		damage = 0;
	}
	if (target->isBlocking == true) {
		target->setHealth(target->getHealth() - (damage/2));
	}
	else {
	target->setHealth(target->getHealth() - damage);
	}
	target->setBlock(false);
	cout << "\033[32m" << name << " \033[0m" << "hits " << "\033[31m" << target->getName() << " \033[0m" << "for " << damage << " damage!!\n";
}

void Character::setBlock(bool a) {
	isBlocking = a;
}



