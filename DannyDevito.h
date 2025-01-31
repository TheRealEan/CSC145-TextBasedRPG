// Filename: "DannyDevito.h"
#include <string>
#include "../Enemy.h"
#ifndef DANNYDEVITO_H
#define DANNYDEVITO_H

class DannyDevito : public Enemy {
public:
	// Constructors and Destructors

	DannyDevito(std::string name);
	DannyDevito(std::string name, int health, int stamina, int mana, int strength, int armor);
	virtual ~DannyDevito() = default;
};

#endif
