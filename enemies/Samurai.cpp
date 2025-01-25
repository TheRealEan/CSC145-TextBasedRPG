// Filename: "Samurai.cpp"
#include "Samurai.h"
using namespace std;

Samurai::Samurai(string name)
	: Samurai(name, 70, 70, 70, 10, 10) {};

Samurai::Samurai(string name, int health, int stamina, int mana, int strength, int armor)
	: Enemy(name, health, stamina, mana, strength, armor) {};
