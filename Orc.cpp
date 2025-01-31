// Filename: "Orc.cpp"
#include "Orc.h"
using namespace std;

Orc::Orc(string name)
	: Orc(name, 70, 70, 70, 10, 10) {};

Orc::Orc(string name, int health, int stamina, int mana, int strength, int armor)
	: Enemy(name, health, stamina, mana, strength, armor) {};
