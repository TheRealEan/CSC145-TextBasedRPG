// Filename: "Hippie.h"
#include <string>
#include "../Enemy.h"
#ifndef HIPPIE_H
#define HIPPIE_H

class Hippie : public Enemy {
public:
	// Constructors and Destructors

	Hippie(std::string name);
	Hippie(std::string name, int health, int stamina, int mana, int strength, int armor);
	virtual ~Hippie() = default;
};

#endif
