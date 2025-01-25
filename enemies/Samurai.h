// Filename: "Samurai.h"
#include <string>
#include "../Enemy.h"
#ifndef SAMURAI_H
#define SAMURAI_H

class Samurai : public Enemy {
public:
	// Constructors and Destructors

	Samurai(std::string name);
	Samurai(std::string name, int health, int stamina, int mana, int strength, int armor);
	virtual ~Samurai() = default;
};

#endif
