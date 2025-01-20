#pragma once
#include<iostream>
#include<string>

using namespace std;

class character {
	string name;
	int health;
	int strength;
	int stamina;
	int mana;
	int armor;
public:
	character(string Name, int Health, int Strength, int Stamina, int Mana, int Armor) {
		name = Name;
		health = Health;
		strength = Strength;
		stamina = Stamina;
		mana = Mana;
		armor = Armor;
	}

	string getName();

	void setName(string newName);

	int getHealth();

	void setHealth(int newHealth);

	int getStrength();

	void setStrength(int newStrength);

	int getStamina();

	void setStamina(int newStamina);

	int getMana();

	void setMana(int newMana);

	int getArmor();

	void setArmor(int newArmor);

	void attack(character *opponent);

	void defend();

	void run();
};