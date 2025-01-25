// Filename: "ChineseSpyPigeon.cpp"
#include "ChineseSpyPigeon.h"
using namespace std;

ChineseSpyPigeon::ChineseSpyPigeon(string name)
	: ChineseSpyPigeon(name, 70, 70, 70, 10, 10) {};

ChineseSpyPigeon::ChineseSpyPigeon(string name, int health, int stamina, int mana, int strength, int armor)
	: Enemy(name, health, stamina, mana, strength, armor) {};
