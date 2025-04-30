#include <iostream>
#include "Enemy.h"

Enemy::Enemy() : Enemy("Nameless", 100, 100, 100, 20, 20, 20, 0) {}
Enemy::Enemy(std::string nombre) : Enemy(nombre, 100, 100, 100, 20, 20, 20, 0) {}
Enemy::Enemy(std::string nombre, int hp, int stam, int magic, int str, int dex, int arm, int money) {
	setName(nombre);
	setHealth(hp);
	setStamina(hp);
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

ChineseSpyPigeon::ChineseSpyPigeon() : ChineseSpyPigeon(20, 100, 100, 100, 20, 0, 5000) {};
ChineseSpyPigeon::ChineseSpyPigeon(int hp, int stam, int magic, int str, int dex, int arm, int money)
	: Enemy("Chinese Spy Pigeon", hp, stam, magic, str, dex, arm, money) {};

DannyDevito::DannyDevito() : DannyDevito(250, 100, 500, 20, 20, 0, 50) {};
DannyDevito::DannyDevito(int hp, int stam, int magic, int str, int dex, int arm, int money)
	: Enemy("Danny Devito", hp, stam, magic, str, dex, arm, money) {};

Roomba::Roomba() : Roomba(30, 100, 100, 20, 20, 0, 50) {};
Roomba::Roomba(int hp, int stam, int magic, int str, int dex, int arm, int money)
	: Enemy("Roomba", hp, stam, magic, str, dex, arm, money) {};

TylerBrown::TylerBrown() : TylerBrown(500, 100, 100, 20, 20, 0, 1000000) {};
TylerBrown::TylerBrown(int hp, int stam, int magic, int str, int dex, int arm, int money)
	: Enemy("Tyler Brown", hp, stam, magic, str, dex, arm, money) {};