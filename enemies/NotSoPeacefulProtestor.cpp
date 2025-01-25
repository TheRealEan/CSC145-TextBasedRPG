// Filename: "NotSoPeacefulProtestor.cpp"
#include "NotSoPeacefulProtestor.h"
using namespace std;

NotSoPeacefulProtestor::NotSoPeacefulProtestor(string name)
	: NotSoPeacefulProtestor(name, 70, 70, 70, 10, 10) {};

NotSoPeacefulProtestor::NotSoPeacefulProtestor(string name, int health, int stamina, int mana, int strength, int armor)
	: Enemy(name, health, stamina, mana, strength, armor) {};
