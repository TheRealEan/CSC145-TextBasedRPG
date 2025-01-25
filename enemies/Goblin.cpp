// Filename: "Goblin.cpp"
#include "Goblin.h"
using namespace std;

Goblin::Goblin(string name)
	: Goblin(name, 70, 70, 70, 10, 10) {};

Goblin::Goblin(string name, int health, int stamina, int mana, int strength, int armor)
	: Enemy(name, health, stamina, mana, strength, armor) {};
