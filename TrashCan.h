// Filename: "TrashCan.h"
#include <string>
#include "../Enemy.h"
#ifndef TRASHCAN_H
#define TRASHCAN_H

class TrashCan : public Enemy {
public:
	// Constructors and Destructors

	TrashCan(std::string name);
	TrashCan(std::string name, int health, int stamina, int mana, int strength, int armor);
	virtual ~TrashCan() = default;
};

#endif
