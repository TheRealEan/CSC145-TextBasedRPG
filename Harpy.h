// Filename: "Harpy.h"
#include <string>
#include "../Enemy.h"
#ifndef HARPY_H
#define HARPY_H

class Harpy : public Enemy {
public:
	// Constructors and Destructors

	Harpy(std::string name);
	Harpy(std::string name, int health, int stamina, int mana, int strength, int armor);
	virtual ~Harpy() = default;
};

#endif
