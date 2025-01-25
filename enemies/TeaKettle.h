// Filename: "TeaKettle.h"
#include <string>
#include "../Enemy.h"
#ifndef TEAKETTLE_H
#define TEAKETTLE_H

class TeaKettle : public Enemy {
public:
	// Constructors and Destructors

	TeaKettle(std::string name);
	TeaKettle(std::string name, int health, int stamina, int mana, int strength, int armor);
	virtual ~TeaKettle() = default;
};

#endif
