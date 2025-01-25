// Filename: "Swiftie.cpp"
#include "Swiftie.h"
using namespace std;

Swiftie::Swiftie(string name)
	: Swiftie(name, 70, 70, 70, 10, 10) {};

Swiftie::Swiftie(string name, int health, int stamina, int mana, int strength, int armor)
	: Enemy(name, health, stamina, mana, strength, armor) {};
