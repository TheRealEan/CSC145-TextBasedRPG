// Filename: "Goblin.h"
#include <string>
#include "../Enemy.h"
#ifndef GOBLIN_H
#define GOBLIN_H

class Goblin : public Enemy {
public:
	// Constructors and Destructors

	Goblin(std::string name);
	Goblin(std::string name, int health, int stamina, int mana, int strength, int armor);
	virtual ~Goblin() = default;
};

#endif
