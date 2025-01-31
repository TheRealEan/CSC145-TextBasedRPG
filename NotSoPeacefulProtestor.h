// Filename: "NotSoPeacefulProtestor.h"
#include <string>
#include "../Enemy.h"
#ifndef NOTSOPEACEFULPROTESTOR_H
#define NOTSOPEACEFULPROTESTOR_H

class NotSoPeacefulProtestor : public Enemy {
public:
	// Constructors and Destructors

	NotSoPeacefulProtestor(std::string name);
	NotSoPeacefulProtestor(std::string name, int health, int stamina, int mana, int strength, int armor);
	virtual ~NotSoPeacefulProtestor() = default;
};

#endif
