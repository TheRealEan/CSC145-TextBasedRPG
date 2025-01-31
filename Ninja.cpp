// Filename: "Ninja.cpp"
#include "Ninja.h"
using namespace std;

Ninja::Ninja()
	: Ninja("Ninja", 100, 70, 70, 10, 10) { };

Ninja::Ninja(string name, int health, int stamina, int mana, int strength, int armor)
	: Enemy(name, health, stamina, mana, strength, armor) {};