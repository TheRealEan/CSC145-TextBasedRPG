// Filename: "Enemies.h"
#include <string>
#include <vector>
#include "Enemy.h"
#ifndef ENEMIES
#define ENEMIES

class ChineseSpyPigeon : public Enemy {
public:
	ChineseSpyPigeon(std::string name);
	ChineseSpyPigeon(std::string name, int health, int stamina, int mana, int strength, int armor, int gold, vector<string> battleResponses);
	virtual ~ChineseSpyPigeon() = default;
};

class DannyDevito : public Enemy {
public:
	DannyDevito(std::string name);
	DannyDevito(std::string name, int health, int stamina, int mana, int strength, int armor, int gold, vector<string> battleResponses);
	virtual ~DannyDevito() = default;
};



class Roomba : public Enemy {
public:
	Roomba(std::string name);
	Roomba(std::string name, int health, int stamina, int mana, int strength, int armor, int gold, vector<string> battleResponses);
	virtual ~Roomba() = default;
};


#endif
