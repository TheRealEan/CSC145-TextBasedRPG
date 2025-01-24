#include "Character.h"
#include "Menu.h"
using namespace std;

// Constructor Function

Character::Character(string Name, int Health, int Strength, int Stamina, int Mana, int Armor)
	: name{ Name }, health{ Health }, strength{ Strength }, stamina{ Stamina }, mana{ Mana }, armor{ Armor } {};

// Getter and Setter Functions

string Character::getName() {
	return name;
}

void Character::setName(string newName) {
	name = newName;
}

int Character::getHealth() {
	return health;
}

void Character::setHealth(int newHealth) {
	health = newHealth;
}

int Character::getStrength() {
	return strength;
}

void Character::setStrength(int newStrength) {
	strength = newStrength;
}

int Character::getStamina() {
	return stamina;
}

void Character::setStamina(int newStamina) {
	stamina = newStamina;
}

int Character::getMana() {
	return mana;
}

void Character::setMana(int newMana) {
	mana = newMana;
}

int Character::getArmor() {
	return armor;
}

void Character::setArmor(int newArmor) {
	armor = newArmor;
}

// Combat Functions

void Character::attack(Character* opponent) {
	//Subtracts attackers strength minus opponents armor from opponents health
	opponent->setHealth(opponent->getHealth() - (this->getStrength() - opponent->getArmor()));
}

void Character::defend() {
	//Just multiplied by 2 for now but it can be changed
	//Will need a way to reset armor after the defend turn is over
	setArmor(getArmor() * 2);
}

void Character::run() {
	cout << getName() << " ran away.\n";
}