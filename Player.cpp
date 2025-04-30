#include <iostream>
#include "Player.h"
#include <conio.h>
#include "utilities/Music.h"

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
			std::system("cls");
			soundEffect("levelUp2.wav");
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
		<< "Character: " << "\033[34m" << getName() << "\033[0m\n"
		<< "Health: " << "\033[34m" << getHealth() << "\033[0m\n"
		<< "Stamina: " << "\033[34m" << getStamina() << "\033[0m\n"
		<< "Mana: " << "\033[34m" << getMana() << "\033[0m\n"
		<< "Strength: " << "\033[34m" << getStrength() << "\033[0m\n"
		<< "Dexterity: " << "\033[34m" << getDexterity() << "\033[0m\n"
		<< "Armor: " << "\033[34m" << getArmor() << "\033[0m\n"
		<< "Gold: " << "\033[34m" << getGold() << "\033[0m\n"
		<< "Level: " << "\033[34m" << getLevel() << "\033[0m\n"
		<< "Experience: " << "\033[34m" << getExperience() << "\033[0m\n"
		<< "Class: " << "\033[34m" << getClass() << "\033[0m\n";
}