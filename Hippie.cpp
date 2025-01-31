// Filename: "Hippie.cpp"
#include "Hippie.h"
using namespace std;

Hippie::Hippie(string name)
	: Hippie(name, 70, 70, 70, 10, 10) {};

Hippie::Hippie(string name, int health, int stamina, int mana, int strength, int armor)
	: Enemy(name, health, stamina, mana, strength, armor) {};
