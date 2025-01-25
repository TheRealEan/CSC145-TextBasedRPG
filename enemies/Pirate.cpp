// Filename: "Pirate.cpp"
#include "Pirate.h"
using namespace std;

Pirate::Pirate(string name)
	: Pirate(name, 70, 70, 70, 10, 10) {};

Pirate::Pirate(string name, int health, int stamina, int mana, int strength, int armor)
	: Enemy(name, health, stamina, mana, strength, armor) {};
