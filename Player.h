// Filename: "Player.h"
#include <string>
#include "Character.h"
#ifndef PLAYER_H
#define PLAYER_H

class Player : public Character {
public:
	// Constructors and Destructors

	Player(std::string name);
	Player(std::string name, int health, int stamina, int mana, int strength, int armor);
	virtual ~Player() = default;
};

#endif
