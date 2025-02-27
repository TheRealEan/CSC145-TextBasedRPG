// Filename: "Player.cpp"
#include "Player.h"
using namespace std;

Player::Player(string name)
	: Player(name, 100, 100, 100, 100, 100, 0) {
};



Player::Player(string name, int health, int stamina, int mana, int strength, int armor, int gold) 
	: Character(name, health, stamina, mana, strength, armor, gold) {};

int Player::getExperience() {
	return experience;
}

void Player::setExperience(int newExperience) {
	experience = newExperience;
}

void Player::checkLevelUp() {
	if (experience >= xpThreshold) {
		cout << "Congratulations! You have leveled up!" << endl;
		experience = 0;
		xpThreshold += 100;
		setHealth(getHealth()+10);
		setStamina(getStamina()+10);
		setMana(getMana()+10);
		setStrength(getStrength()+10);
		setArmor(getArmor()+10);
	}
}

int Player::getxpThreshold() {
	return xpThreshold;
}

void Player::setxpThreshold(int newxpThreshold) {
	xpThreshold = newxpThreshold;
}

void Player::classSelection() {
	cout << "Please select a class: " << endl;
	cout << "1. Warrior" << endl;
	cout << "2. Mage" << endl;
	cout << "3. Rogue" << endl;
	int choice;
	cin >> choice;
	switch (choice) {
	case 1:
		setHealth(getHealth() + 25);
		setMana(getMana() - 25);
		setStrength(getStrength() + 10);
		break;
	case 2:
		setHealth(getHealth() - 25);
		setStamina(getStamina() + 10);
		setMana(getMana() + 25);
		setStrength(getStrength() - 10);
		break;
	case 3:
		setStamina(getStamina() + 25);
		break;
	default:
		cout << "Invalid choice. Please try again." << endl;
		break;

	}
}