// Filename: "Player.cpp"
#include "Player.h"
using namespace std;

Player::Player(string name)
	: Player(name, 100, 100, 100, 100, 100) {};

Player::Player(string name, int health, int stamina, int mana, int strength, int armor) 
	: Character(name, health, stamina, mana, strength, armor) {};
