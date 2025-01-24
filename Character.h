#include <iostream>
#ifndef CHARACTER_H
#define CHARACTER_H

class Character {

public:
	// Constructor Prototype
	Character(std::string Name, int Health, int Strength, int Stamina, int Mana, int Armor);

	// Getter and Setter Function Prototypes

	// Retrieves the value of name.
	std::string getName();
	// Sets the value of name.
	void setName(std::string newName);
	// Retrieves the value of health.
	int getHealth();
	// Sets the value of health.
	void setHealth(int newHealth);
	// Retrieves the value of strength.
	int getStrength();
	// Sets the value of strength.
	void setStrength(int newStrength);
	// Retrieves the value of stamina.
	int getStamina();
	// Sets the value of stamina.
	void setStamina(int newStamina);
	// Retrieves the value of mana.
	int getMana();
	// Sets the value of mana.
	void setMana(int newMana);
	// Retrieves the value of armor.
	int getArmor();
	// Sets the value of armor.
	void setArmor(int newArmor);

	// Combat Functions

	// The Character deals damage to an opponent equal to their strength.
	void attack(Character *opponent);
	// The Character blocks damage equal to double their armor.
	void defend();
	// The Character leaves the battle.
	void run();

private:
	// Data Members

	std::string name;
	int health;
	int strength;
	int stamina;
	int mana;
	int armor;
	
};

#endif