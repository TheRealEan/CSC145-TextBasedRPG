// Filename: "Enemies.h"
#include <string>
#include "Enemy.h"
#ifndef ENEMIES
#define ENEMIES

class ChineseSpyPigeon : public Enemy {
public:
	ChineseSpyPigeon(std::string name);
	ChineseSpyPigeon(std::string name, int health, int stamina, int mana, int strength, int armor, int gold);
	virtual ~ChineseSpyPigeon() = default;
};

// ------------------------------------------------------------------ //

class ChineseWeatherBalloon : public Enemy {
public:
	ChineseWeatherBalloon(std::string name);
	ChineseWeatherBalloon(std::string name, int health, int stamina, int mana, int strength, int armor, int gold);
	virtual ~ChineseWeatherBalloon() = default;
};

// ------------------------------------------------------------------ //

class DannyDevito : public Enemy {
public:
	DannyDevito(std::string name);
	DannyDevito(std::string name, int health, int stamina, int mana, int strength, int armor, int gold);
	virtual ~DannyDevito() = default;
};

// ------------------------------------------------------------------ //

class Drake : public Enemy {
public:
	Drake(std::string name);
	Drake(std::string name, int health, int stamina, int mana, int strength, int armor, int gold);
	virtual ~Drake() = default;
};

// ------------------------------------------------------------------ //

class Goblin : public Enemy {
public:
	Goblin(std::string name);
	Goblin(std::string name, int health, int stamina, int mana, int strength, int armor, int gold);
	virtual ~Goblin() = default;
};

// ------------------------------------------------------------------ //

class Harpy : public Enemy {
public:
	Harpy(std::string name);
	Harpy(std::string name, int health, int stamina, int mana, int strength, int armor, int gold);
	virtual ~Harpy() = default;
};

// ------------------------------------------------------------------ //

class Hippie : public Enemy {
public:
	Hippie(std::string name);
	Hippie(std::string name, int health, int stamina, int mana, int strength, int armor, int gold);
	virtual ~Hippie() = default;
};

// ------------------------------------------------------------------ //

class Merfolk : public Enemy {
public:
	Merfolk(std::string name);
	Merfolk(std::string name, int health, int stamina, int mana, int strength, int armor, int gold);
	virtual ~Merfolk() = default;
};

// ------------------------------------------------------------------ //

class Nickelback : public Enemy {
public:
	Nickelback(std::string name);
	Nickelback(std::string name, int health, int stamina, int mana, int strength, int armor, int gold);
	virtual ~Nickelback() = default;
};

// ------------------------------------------------------------------ //

class Ninja : public Enemy {
public:
	Ninja(std::string name);
	Ninja(std::string name, int health, int stamina, int mana, int strength, int armor, int gold);
	virtual ~Ninja() = default;
};

// ------------------------------------------------------------------ //

class Protestor : public Enemy {
public:
	Protestor(std::string name);
	Protestor(std::string name, int health, int stamina, int mana, int strength, int armor, int gold);
	virtual ~Protestor() = default;
};

// ------------------------------------------------------------------ //

class Orc : public Enemy {
public:
	Orc(std::string name);
	Orc(std::string name, int health, int stamina, int mana, int strength, int armor, int gold);
	virtual ~Orc() = default;
};

// ------------------------------------------------------------------ //

class Pirate : public Enemy {
public:
	Pirate(std::string name);
	Pirate(std::string name, int health, int stamina, int mana, int strength, int armor, int gold);
	virtual ~Pirate() = default;
};

// ------------------------------------------------------------------ //

class Roomba : public Enemy {
public:
	Roomba(std::string name);
	Roomba(std::string name, int health, int stamina, int mana, int strength, int armor, int gold);
	virtual ~Roomba() = default;
};

// ------------------------------------------------------------------ //

class Samurai : public Enemy {
public:
	Samurai(std::string name);
	Samurai(std::string name, int health, int stamina, int mana, int strength, int armor, int gold);
	virtual ~Samurai() = default;
};

// ------------------------------------------------------------------ //

class Swiftie : public Enemy {
public:
	Swiftie(std::string name);
	Swiftie(std::string name, int health, int stamina, int mana, int strength, int armor, int gold);
	virtual ~Swiftie() = default;
};

// ------------------------------------------------------------------ //

class TeaKettle : public Enemy {
public:
	TeaKettle(std::string name);
	TeaKettle(std::string name, int health, int stamina, int mana, int strength, int armor, int gold);
	virtual ~TeaKettle() = default;
};

// ------------------------------------------------------------------ //

class TrashCan : public Enemy {
public:
	TrashCan(std::string name);
	TrashCan(std::string name, int health, int stamina, int mana, int strength, int armor, int gold);
	virtual ~TrashCan() = default;
};

#endif
