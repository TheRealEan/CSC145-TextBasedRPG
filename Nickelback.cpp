// Filename: "Nickelback.cpp"
#include "Nickelback.h"
using namespace std;

Nickelback::Nickelback(string name)
	: Nickelback(name, 70, 70, 70, 10, 10) {};

Nickelback::Nickelback(string name, int health, int stamina, int mana, int strength, int armor)
	: Enemy(name, health, stamina, mana, strength, armor) {};
