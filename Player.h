// Filename: "Player.h"
#include <string>
#include "Character.h"
#ifndef PLAYER_H
#define PLAYER_H

class Player : public Character {
public:
	// Constructors and Destructors

	Player(std::string name);
	Player(std::string name, int health, int stamina, int mana, int strength, int armor, int gold, vector<string> battleResponses);
	virtual ~Player() = default;

	int getExperience();

	void setExperience(int newExperience);

	void checkLevelUp();

	int getxpThreshold();

	void setxpThreshold(int newxpThreshold);

	void classSelection();

protected:
	int experience{ 0 };
	int xpThreshold{ 100 };

};

#endif
