#ifndef PLAYER_H
#define PLAYER_H
#include "Character.h"
using namespace std;
class Player : public Character {
public:
	Player();
	Player(std::string name);
	Player(std::string name, int hp, int stam, int magic, int str, int dex, int arm, int money);
	Player(std::string name, string cClass, int hp, int stam, int magic, int str, int dex, int arm, int money, int exp, int level);

	int getExperience();
	void setExperience(int amt);
	void setClass(string Cclass);
	string getClass();
	int getLevel();
	int getBaseHealth();
	void checkLevelUp();
	void displayStats() override;

protected:
	// std::string classType;
	int exp;
	int level{ 1 };
	string cClass;
	int bassW = 50;
	int baseR = 30;
	int baseM = 25;
};

#endif