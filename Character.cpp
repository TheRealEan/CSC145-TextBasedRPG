// Filename: "Character.cpp"
#include <iostream>
#include "Character.h"
#include "Menu.h"
using namespace std;

Character::Character(string name)  // Delegating constuctor.
	: Character(name, 100, 100, 100, 1000, 100) {};

Character::Character(string name, int health, int stamina, int mana, int strength, int armor) { // Primary constructor.
	Character::setName(name);
	Character::setHealth(health);
	Character::setStamina(stamina);
	Character::setMana(mana);
	Character::setStrength(strength);
	Character::setArmor(armor);
};

string Character::getName() {
	return name;
}

void Character::setName(string newName) {
	name = newName;
}

int Character::getHealth() {
	return health;
}

void Character::setHealth(int newHealth) { // Implement error checking for below zero health.
	health = newHealth;
}

int Character::getStamina() {
	return stamina;
}

void Character::setStamina(int newStamina) { // Implement error checking for below zero stamina.
	stamina = newStamina;
}

int Character::getMana() {
	return mana;
}

void Character::setMana(int newMana) { // Implement error checking for below zero mana.
	mana = newMana;
}

int Character::getStrength() {
	return strength;
}

void Character::setStrength(int newStrength) { // Implement error checking for below zero strength.
	strength = newStrength;
}

int Character::getArmor() {
	return armor;
}

void Character::setArmor(int newArmor) { // Implement error checking for below zero armor.
	armor = newArmor;
}

// Damage dealt is the attacker's strength minus defender's armor dealt to health points.
void Character::attack(Character* opponent) {
	opponent->setHealth(opponent->getHealth() - (this->getStrength() - opponent->getArmor()));
}

// Multiplies defense by two.
void Character::defend() { // Need a method to reset armor.
	setArmor(getArmor() * 2);
}

// Should leave/end the battle sequence.
void Character::run() {
	cout << getName() << " ran away." << endl;
}

// Display all statistics relating to the Character.
void Character::displayStats() {
	cout << getName() << "'s Health: " << getHealth() << endl;
	cout << getName() << "'s Stamina: " << getStamina() << endl;
	cout << getName() << "'s Mana: " << getMana() << endl;
	cout << getName() << "'s Strength: " << getStrength() << endl;
	cout << getName() << "'s Armor: " << getArmor() << endl;
}
