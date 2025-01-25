// Filename: "Drake.h"
#include <string>
#include "../Enemy.h"
#ifndef DRAKE_H
#define DRAKE_H

class Drake : public Enemy {
public:
	// Constructors and Destructors

	Drake(std::string name);
	Drake(std::string name, int health, int stamina, int mana, int strength, int armor);
	virtual ~Drake() = default;
};

#endif
