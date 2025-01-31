// Filename: "Pirate.h"
#include <string>
#include "../Enemy.h"
#ifndef PIRATE_H
#define PIRATE_H

class Pirate : public Enemy {
public:
	// Constructors and Destructors

	Pirate(std::string name);
	Pirate(std::string name, int health, int stamina, int mana, int strength, int armor);
	virtual ~Pirate() = default;
};

#endif
