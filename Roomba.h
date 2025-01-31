// Filename: "Roomba.h"
#include <string>
#include "../Enemy.h"
#ifndef ROOMBA_H
#define ROOMBA_H

class Roomba : public Enemy {
public:
	// Constructors and Destructors

	Roomba();
	Roomba(std::string name, int health, int stamina, int mana, int strength, int armor);
	virtual ~Roomba() = default;
};

#endif
