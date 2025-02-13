// Filename: "Extra.cpp"
// Contains miscellaneous data structures and functions used throughout the program.
#include <random>
#include "Enemy.h"
#include "Enemies.h"
using namespace std;

int roll(int numDice, int numOfSides);
Enemy* generateRandomEnemy();

// Simulates rolling a specified number of dice.
int roll(int numDice, int numOfSides) {
	unsigned int sum{ 0 };
	for (unsigned int i = 0; i < numDice; i++) {
		sum += rand() % numOfSides + 1;
	}
    return sum;
}

// Generates a random enemy.
Enemy* generateRandomEnemy() {
   int num = roll(1, 18);  // pseudorandomly pick number between 1 and 18
switch (num) {
case 1:
    return new Roomba("Roomba");
case 2:
    return new Swiftie("Swiftie");
case 3:
    return new Ninja("Ninja");
case 4:
    return new ChineseSpyPigeon("Chinese Spy Pigeon");
case 5:
    return new ChineseWeatherBalloon("Chinese Weather Balloon");
case 6:
    return new DannyDevito("Danny Devito");
case 7:
    return new Drake("Drake");
case 8:
    return new Goblin("Goblin");
case 9:
    return new Harpy("Harpy");
case 10:
    return new Hippie("Hippie");
case 11:
    return new Merfolk("Merfolk");
case 12:
    return new Nickelback("Nickelback");
case 13:
    return new Protestor("Protestor");
case 14:
    return new Orc("Orc");
case 15:
    return new Pirate("Pirate");
case 16:
    return new Samurai("Samurai");
case 17:
    return new TeaKettle("TeaKettle");
case 18:
    return new TrashCan("TrashCan");
}
return nullptr;
}


