#include"character.h"
#include"menu.h"

string character::getName() {
	return name;
}

void character::setName(string newName) {
	name = newName;
}

int character::getHealth() {
	return health;
}

void character::setHealth(int newHealth) {
	health = newHealth;
}

int character::getStrength() {
	return strength;
}

void character::setStrength(int newStrength) {
	strength = newStrength;
}

int character::getStamina() {
	return stamina;
}

void character::setStamina(int newStamina) {
	stamina = newStamina;
}

int character::getMana() {
	return mana;
}

void character::setMana(int newMana) {
	mana = newMana;
}

int character::getArmor() {
	return armor;
}

void character::setArmor(int newArmor) {
	armor = newArmor;
}

void character::attack(character* opponent) {
	//Subtracts attackers strength minus opponents armor from opponents health
	opponent->setHealth(opponent->getHealth() - (this->getStrength() - opponent->getArmor()));
}

void character::defend() {
	//Just multiplied by 2 for now but it can be changed
	//Will need a way to reset armor after the defend turn is over
	setArmor(getArmor() * 2);
}

void character::run() {
	cout << getName() << " ran away.\n";
}