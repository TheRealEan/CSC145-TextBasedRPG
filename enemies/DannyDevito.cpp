// Filename: DannyDevito.cpp"
#include "DannyDevito.h"
using namespace std;

DannyDevito::DannyDevito(string name)
	: DannyDevito(name, 70, 70, 70, 10, 10) {};

DannyDevito::DannyDevito(string name, int health, int stamina, int mana, int strength, int armor)
	: Enemy(name, health, stamina, mana, strength, armor) {};
