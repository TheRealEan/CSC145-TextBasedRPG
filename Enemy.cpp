// Filename: "Enemy.cpp"
#include <cstdlib>
#include <ctime>
#include "Enemy.h"
using namespace std;

Enemy::Enemy(string name)
	: Enemy(name, 100, 100, 100, 100, 100) {};

Enemy::Enemy(string name, int health, int stamina, int mana, int strength, int armor) // Delegating constructor.
	: Character(name, health, stamina, mana, strength, armor) {};

void Enemy::target(Character* opponent) {
	srand(static_cast<unsigned int>(time(0))); // Seeds using the current time.
	unsigned int roll = (1 + rand() % 3); // Generates a number from 1 to 3.

	// Determines which options is chosen.
	switch (roll) {
	case 1:
		Character::attack(opponent);
		break;
	case 2:
		Character::defend();
		break;
	case 3:
		Character::run();
		break;
	}
};
