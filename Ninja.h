// Filename: "Ninja.h"
#include <string>
#include "../Enemy.h"
#ifndef NINJA_H
#define NINJA_H

class Ninja : public Enemy {
public:
	// Constructors and Destructors

	Ninja();
	Ninja(std::string name, int health, int stamina, int mana, int strength, int armor);
	virtual ~Ninja() = default;
};

#endif
