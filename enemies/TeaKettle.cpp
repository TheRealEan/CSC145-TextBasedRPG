// Filename: "TeaKettle.cpp"
#include "TeaKettle.h"
using namespace std;

TeaKettle::TeaKettle(string name)
	: TeaKettle(name, 70, 70, 70, 10, 10) {};

TeaKettle::TeaKettle(string name, int health, int stamina, int mana, int strength, int armor)
	: Enemy(name, health, stamina, mana, strength, armor) {};
