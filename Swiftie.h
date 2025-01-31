// Filename: "Swiftie.h"
#include <string>
#include "../Enemy.h"
#ifndef SWIFTIE_H
#define SWIFTIE_H

class Swiftie : public Enemy {
public:
	// Constructors and Destructors

	Swiftie();
	Swiftie(std::string name, int health, int stamina, int mana, int strength, int armor);
	virtual ~Swiftie() = default;
};

#endif
