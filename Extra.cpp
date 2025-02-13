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
    int num = roll(1, 3);  // pseudorandomly pick number between 1 and 3
    switch (num) {
    case 1:
        return new Roomba("Roomba");
    case 2:
        return new Swiftie("Swiftie");
    case 3:
        return new Ninja("Ninja");
    }
    return nullptr;
}
