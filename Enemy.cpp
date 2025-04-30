// Enemy.cpp
#include <iostream>
#include "Enemy.h"

Enemy::Enemy()
    : Enemy("Nameless", 100, 100, 100, 20, 20, 20, 0) {
}
Enemy::Enemy(std::string nombre)
    : Enemy(nombre, 100, 100, 100, 20, 20, 20, 0) {
}
Enemy::Enemy(std::string nombre, int hp, int stam, int magic, int str, int dex, int arm, int money) {
    setName(nombre);
    setHealth(hp);
    setStamina(stam);
    setMana(magic);
    setStrength(str);
    setDexterity(dex);
    setArmor(arm);
    setGold(money);
}

void Enemy::displayStats() {
    std::cout
        << "Enemy: " << getName() << "\n"
        << "Health: " << getHealth() << "\n"
        << "Stamina: " << getStamina() << "\n"
        << "Mana: " << getMana() << "\n"
        << "Strength: " << getStrength() << "\n"
        << "Dexterity: " << getDexterity() << "\n"
        << "Armor: " << getArmor() << "\n"
        << "Gold: " << getGold() << "\n";
}

ChineseSpyPigeon::ChineseSpyPigeon()
    : ChineseSpyPigeon(500, 100, 100, 100, 20, 0, 500) {
}
ChineseSpyPigeon::ChineseSpyPigeon(int hp, int stam, int magic, int str, int dex, int arm, int money)
    : Enemy("Chinese Spy Pigeon", hp, stam, magic, str, dex, arm, money) {
}
Enemy* ChineseSpyPigeon::clone() const { return new ChineseSpyPigeon(*this); }

DannyDevito::DannyDevito()
    : DannyDevito(10000, 0, 0, 10, 20, 0, 50000) {
}
DannyDevito::DannyDevito(int hp, int stam, int magic, int str, int dex, int arm, int money)
    : Enemy("Danny Devito", hp, stam, magic, str, dex, arm, money) {
}
Enemy* DannyDevito::clone() const { return new DannyDevito(*this); }

Roomba::Roomba()
    : Roomba(30, 100, 100, 20, 20, 0, 50) {
}
Roomba::Roomba(int hp, int stam, int magic, int str, int dex, int arm, int money)
    : Enemy("Roomba", hp, stam, magic, str, dex, arm, money) {
}
Enemy* Roomba::clone() const { return new Roomba(*this); }

TylerBrown::TylerBrown()
    : TylerBrown(2000, 500, 600, 600, 600, 1000, 0) {
}
TylerBrown::TylerBrown(int hp, int stam, int magic, int str, int dex, int arm, int money)
    : Enemy("Tyler Brown", hp, stam, magic, str, dex, arm, money) {
}
Enemy* TylerBrown::clone() const { return new TylerBrown(*this); }
