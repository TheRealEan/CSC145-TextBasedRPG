// Filename: "Orc.h"
#include <string>
#include "../Enemy.h"
#ifndef ORC_H
#define ORC_H

class Orc : public Enemy {
public:
	// Constructors and Destructors

	Orc(std::string name);
	Orc(std::string name, int health, int stamina, int mana, int strength, int armor);
	virtual ~Orc() = default;
};

#endif
