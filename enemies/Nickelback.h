// Filename: "Nickelback.h"
#include <string>
#include "../Enemy.h"
#ifndef NICKELBACK_H
#define NICKELBACK_H

class Nickelback : public Enemy {
public:
	// Constructors and Destructors

	Nickelback(std::string name);
	Nickelback(std::string name, int health, int stamina, int mana, int strength, int armor);
	virtual ~Nickelback() = default;
};

#endif
