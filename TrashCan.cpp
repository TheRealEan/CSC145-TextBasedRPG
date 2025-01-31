// Filename: "TrashCan.cpp"
#include "TrashCan.h"
using namespace std;

TrashCan::TrashCan(string name)
	: TrashCan(name, 70, 70, 70, 10, 10) {};

TrashCan::TrashCan(string name, int health, int stamina, int mana, int strength, int armor)
	: Enemy(name, health, stamina, mana, strength, armor) {};
