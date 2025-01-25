// Filename: "ChineseSpyPigeon.h"
#include <string>
#include "../Enemy.h"
#ifndef CHINESESPYPIGEON_H
#define CHINESESPYPIGEON_H

class ChineseSpyPigeon : public Enemy {
public:
	// Constructors and Destructors

	ChineseSpyPigeon(std::string name);
	ChineseSpyPigeon(std::string name, int health, int stamina, int mana, int strength, int armor);
	virtual ~ChineseSpyPigeon() = default;
};

#endif
