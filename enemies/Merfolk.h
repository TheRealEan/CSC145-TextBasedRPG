// Filename: "Merfolk.h"
#include <string>
#include "../Enemy.h"
#ifndef MERFOLK_H
#define MERFOLK_H

class Merfolk : public Enemy {
public:
	// Constructors and Destructors

	Merfolk(std::string name);
	Merfolk(std::string name, int health, int stamina, int mana, int strength, int armor);
	virtual ~Merfolk() = default;
};

#endif
