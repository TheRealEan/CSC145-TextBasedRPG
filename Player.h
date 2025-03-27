#ifndef PLAYER_H
#define PLAYER_H
#include "Character.h"

class Player : public Character {
public:
	Player();
	Player(std::string name);
	Player(std::string name, int hp, int stam, int magic, int str, int dex, int arm, int money);
	Player(std::string name, int hp, int stam, int magic, int str, int dex, int arm, int money, int exp);

	int const getExperience();
	void setExperience(int amt);
	int const getLevel();
	void checkLevelUp();

	void displayStats() override;

protected:
	// std::string classType;
	int xp;
	int level{ 1 };
};

#endif