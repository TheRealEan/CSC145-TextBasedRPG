// Filename: "Character.h"
#include <string>
#ifndef CHARACTER_H
#define CHARACTER_H
using namespace std;

class Character {
public:
	// Constructor and Destructors

	Character(std::string nombre);
	Character(std::string nombre, int hp, int sp, int mp, int str, int arm);
	virtual ~Character() = default;

	// Getter and Setter Functions

	std::string getName(); 	// Retrieves the value of name.
	void setName(std::string newName); 	// Sets the value of name.
	int getHealth(); // Retrieves the value of health.
	void setHealth(int newHealth); 	// Sets the value of health.
	int getStamina(); 	// Retrieves the value of stamina.
	void setStamina(int newStamina); 	// Sets the value of stamina.
	int getMana(); 	// Retrieves the value of mana.
	void setMana(int newMana); 	// Sets the value of mana.
	int getStrength(); 	// Retrieves the value of strength.
	void setStrength(int newStrength); 	// Sets the value of strength.
	int getArmor(); 	// Retrieves the value of armor.
	void setArmor(int newArmor); 	// Sets the value of armor.

	// Combat Functions

	void attack(Character *opponent); // The Character deals damage to an opponent equal to their strength.
	void defend(); 	// The Character blocks damage equal to double their armor.
	void run(); // The Character leaves the battle.
	// virtual void chat(Character* opponent) = 0; // The Character enters a chat with an opponent.

	// Statistic Functions

	virtual void displayStats();

	void target(Character* opponent, Character* self);/* {
		srand(static_cast<unsigned int>(time(0))); // Seeds using the current time.
		unsigned int roll = (1 + rand() % 3); // Generates a number from 1 to 3.

		// Determines which options is chosen.
		switch (roll) {
		case 1:
			Character::attack(opponent);
			cout << self->getName() << " Attacks!";
			break;
		case 2:
			Character::defend();
			cout << self->getName() << " Defends!";
			break;
		case 3:
			Character::run();
			cout << self->getName() << " Runs away!";
			break;
		}
	};*/

private:
	// Data Members

	std::string name;
	int health{ 100 };
	int stamina{ 100 };
	int mana{ 100 };
	int strength{ 100 };
	int armor{ 100 };
};

#endif
