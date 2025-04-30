#include <iostream>
#include "Player.h"
#include <conio.h>

Player::Player() : Player("Nameless", "", 100, 100, 100, 20, 20, 20, 0, 0, 1) {}
Player::Player(std::string nombre) : Player(nombre, "", 100, 100, 100, 20, 20, 20, 0, 0, 1) {}
Player::Player(std::string nombre, int hp, int stam, int magic, int str, int dex, int arm, int money) : Player(nombre, "", hp, stam, magic, str, dex, arm, money, 0, 1) {}
Player::Player(std::string nombre, string cClass, int hp, int stam, int magic, int str, int dex, int arm, int money, int exp, int level) {
	setName(nombre);
	setHealth(hp);
	setStamina(stam);
	setMana(magic);
	setStrength(str);
	setDexterity(dex);
	setArmor(arm);
	setGold(money);
	setExperience(exp);
	setClass(cClass);
}

int Player::getExperience() { return exp; }
void Player::setExperience(int amt) {
	if (amt < 0) exp = 0;
	else exp = amt;
}
void Player::setClass(string c) {
	cClass = c;
}
int Player::getBaseHealth() {
	if (cClass == "Warrior") {
		return health = 50 + (15 * (level - 1));
	}
	if (cClass == "Rogue") {
		return health = 30 + (2 * (level - 1));
	}
	if (cClass == "Mage") {
		return health = 25 + (5 * (level - 1));
	}
}
int Player::getLevel() { return level; }
void Player::checkLevelUp() {
	while (exp >= (5 * level)) {
		if (level == 100) {
			std::cout << "Max level reached; " << "\n";
			std::cout << "Press enter to continue... \n";
			std::ignore = _getch();
			break;
		}
		else {
			level++;
			cout << "Congrats! You're now level: " << level << "!\n";
			if (cClass == "Warrior") {
				health += 15;
				stamina += 1;
				strength += 2;
				dexterity += 2;
				armor += 15;
			}
			else if (cClass == "Rogue") {
				health += 2;
				mana += 5;
				stamina += 15;
				strength += 20;
				dexterity += 2;
				armor += 2;
			}
			else if (cClass == "Mage") {
				health += 5;
				mana += 15;
				stamina += 10;
				strength += 5;
				dexterity += 2;
				armor += 5;
			}
			displayStats();
			exp -= (5 * level);
			std::cout << "\nPress enter to continue... \n\n";
			std::ignore = _getch();
		}

	}
	return;
}
string Player::getClass() { return cClass; };

void Player::displayStats() {
	std::cout
		<< "Character: " << getName() << "\n"
		<< "Health: " << getHealth() << "\n"
		<< "Stamina: " << getStamina() << "\n"
		<< "Mana: " << getMana() << "\n"
		<< "Strength: " << getStrength() << "\n"
		<< "Dexterity: " << getDexterity() << "\n"
		<< "Armor: " << getArmor() << "\n"
		<< "Gold: " << getGold() << "\n"
		<< "Level: " << getLevel() << "\n"
		<< "Experience: " << getExperience() << "\n"
		<< "Class: " << getClass() << "\n";
}