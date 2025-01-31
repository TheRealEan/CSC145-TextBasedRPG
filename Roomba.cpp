// Filename: "Roomba.cpp"
#include "Roomba.h"
using namespace std;

Roomba::Roomba()
	: Roomba("Roomba", 70, 70, 70, 10, 10) { };

Roomba::Roomba(string name, int health, int stamina, int mana, int strength, int armor)
	: Enemy(name, health, stamina, mana, strength, armor) {};
