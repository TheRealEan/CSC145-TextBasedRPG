// Filename: "Harpy.cpp"
#include "Harpy.h"
using namespace std;

Harpy::Harpy(string name)
	: Harpy(name, 70, 70, 70, 10, 10) {};

Harpy::Harpy(string name, int health, int stamina, int mana, int strength, int armor)
	: Enemy(name, health, stamina, mana, strength, armor) {};
