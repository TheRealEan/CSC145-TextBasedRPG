// Filename: "Merfolk.cpp"
#include "Merfolk.h"
using namespace std;

Merfolk::Merfolk(string name)
	: Merfolk(name, 70, 70, 70, 10, 10) {};

Merfolk::Merfolk(string name, int health, int stamina, int mana, int strength, int armor)
	: Enemy(name, health, stamina, mana, strength, armor) {};
