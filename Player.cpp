#include "Player.h"

Player::Player() : Player("Nameless", 100, 100, 100, 20, 20, 20, 100, 0) {}
Player::Player(std::string nombre) : Player(nombre, 100, 100, 100, 20, 20, 20, 100, 0) {}
Player::Player(std::string nombre, int hp, int stam, int magic, int str, int dex, int arm, int money) : Player(nombre, hp, stam, magic, str, dex, arm, money, 0) {}
Player::Player(std::string nombre, int hp, int stam, int magic, int str, int dex, int arm, int money, int exp) {
	setName(nombre);
	setHealth(hp);
	setStamina(stam);
	setMana(magic);
	setStrength(str);
	setDexterity(dex);
	setArmor(arm);
	setGold(money);
	setExperience(exp);
}

int const Player::getExperience() { return xp; }
void Player::setExperience(int amt) {
	if (amt < 0) xp = 0;
	else xp = amt;
}
int const Player::getLevel() { return level; }
void Player::checkLevelUp() {
	// Checks if xp meets a threshold.
	// If so, adds a level and changes stats accordingly.
	return;
}

void Player::displayStats() {
	std::cout << "Character: " << getName() << "\n"
		<< "Health: " << getHealth() << "\n"
		<< "Stamina: " << getStamina() << "\n"
		<< "Mana: " << getMana() << "\n"
		<< "Strength: " << getStrength() << "\n"
		<< "Dexterity: " << getDexterity() << "\n"
		<< "Armor: " << getArmor() << "\n"
		<< "Gold: " << getGold() << "\n"
		<< "Level: " << getLevel() << "\n"
		<< "Experience: " << getExperience() << "\n";
}