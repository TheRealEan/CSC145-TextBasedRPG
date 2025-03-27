#ifndef ROLL_H
#define ROLL_H
#include <random>
#include <ctime>

int roll(int numOfDice, int sidesOfDice) {
	// Seed the random number generator with the time.
	static std::mt19937 generator(std::time(0));
	// Define a uniform distribution for the dice rolls.
	std::uniform_int_distribution<int> distribution(1, sidesOfDice);
	
	int total{ 0 };
	// Simulate rolling all of the number of dice.
	for (int i = 0; i < numOfDice; i++) {
		total += distribution(generator);
	}
	// Return the summed total of the rolls.
	return total;
}

#endif
