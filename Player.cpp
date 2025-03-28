// Filename: "Player.cpp"
#include "Player.h"
using namespace std;

Player::Player(string name)
	: Player(name, 100, 100, 100, 100, 100, 0, battleResponses) {
	battleResponses = { "You punch the enemy!", "You kick the back of their knees!", "You slash them with your weapon!", "You hit them with your shield!", "Their attack is stopped by your shield!", "Their hit is deflected off of your armour!", "You dodge the attack!", "The enemy misses!", "You skedaddle away", "You shirked this fight", "You failed. You turn away in defeat.", "You give up and leave" };
};



Player::Player(string name, int health, int stamina, int mana, int strength, int armor, int gold, vector<string> battleResponses) 
	: Character(name, health, stamina, mana, strength, armor, gold, battleResponses) {
};

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