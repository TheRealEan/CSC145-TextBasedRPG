#ifndef ENEMY_H
#define ENEMY_H
#include <string>
#include "Character.h"

class Enemy : public Character {
public:
	Enemy();
	Enemy(std::string nombre);
	Enemy(std::string nombre, int hp, int stam, int magic, int str, int dex, int arm, int money);
	virtual ~Enemy() = default;

	void displayStats();
};

class ChineseSpyPigeon : public Enemy {
public:
	ChineseSpyPigeon();
	ChineseSpyPigeon(int hp, int stam, int magic, int str, int dex, int arm, int money);
	virtual ~ChineseSpyPigeon() = default;
};

class DannyDevito : public Enemy {
public:
	DannyDevito();
	DannyDevito(int hp, int stam, int magic, int str, int dex, int arm, int money);
	virtual ~DannyDevito() = default;
};

class Roomba : public Enemy {
public:
	Roomba();
	Roomba(int hp, int stam, int magic, int str, int dex, int arm, int money);
	virtual ~Roomba() = default;
};

class ChickenJockey : public Enemy {
public:
	ChickenJockey();
	ChickenJockey(int hp, int stam, int magic, int str, int dex, int arm, int money);
	virtual ~ChickenJockey() = default;
};

class TylerBrown : public Enemy {
public:
	TylerBrown();
	TylerBrown(int hp, int stam, int magic, int str, int dex, int arm, int money);
	virtual ~TylerBrown() = default;
};


#endif