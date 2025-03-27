// Filename: "Enemy.h"
#include "Character.h"
#ifndef ENEMY_H
#define ENEMY_H

class Enemy : public Character {
public:
	// Constructor and Destructors.

	Enemy(std::string name);
	Enemy(std::string name, int health, int stamina, int mana, int strength, int armor, int gold, vector<string> battleResponses);
	virtual ~Enemy() = default;

	// Combat Functions

	virtual void target(Character* opponent); // Makes decisions during battle sequence.
};

#endif
