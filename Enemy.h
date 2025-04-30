// Enemy.h
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

    /// Return a fresh copy of this exact subclass (at full health)
    virtual Enemy* clone() const = 0;

    void displayStats();
};

class ChineseSpyPigeon : public Enemy {
public:
    ChineseSpyPigeon();
    ChineseSpyPigeon(int hp, int stam, int magic, int str, int dex, int arm, int money);
    ~ChineseSpyPigeon() override = default;
    Enemy* clone() const override;
};

class DannyDevito : public Enemy {
public:
    DannyDevito();
    DannyDevito(int hp, int stam, int magic, int str, int dex, int arm, int money);
    ~DannyDevito() override = default;
    Enemy* clone() const override;
};

class Roomba : public Enemy {
public:
    Roomba();
    Roomba(int hp, int stam, int magic, int str, int dex, int arm, int money);
    ~Roomba() override = default;
    Enemy* clone() const override;
};

class ChickenJockey : public Enemy {
public:
	ChickenJockey();
	ChickenJockey(int hp, int stam, int magic, int str, int dex, int arm, int money);
	virtual ~ChickenJockey() = default;
    Enemy* clone() const override;
};

class TylerBrown : public Enemy {
public:
    TylerBrown();
    TylerBrown(int hp, int stam, int magic, int str, int dex, int arm, int money);
    ~TylerBrown() override = default;
    Enemy* clone() const override;
};

#endif // ENEMY_H
