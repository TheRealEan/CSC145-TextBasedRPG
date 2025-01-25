// Filename: "Drake.cpp"
#include "Drake.h"
using namespace std;

Drake::Drake(string name)
	: Drake(name, 70, 70, 70, 10, 10) {};

Drake::Drake(string name, int health, int stamina, int mana, int strength, int armor)
	: Enemy(name, health, stamina, mana, strength, armor) {};
