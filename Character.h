// Filename: "Character.h"
#include <string>
#include "Inventory.h"
#ifndef CHARACTER_H
#define CHARACTER_H
using namespace std;


class Character {
protected:
	Inventory inventory;
public:
	Character(string nombre);
	Character(string nombre, int hp, int sp, int mp, int str, int arm);
	virtual ~Character() = default;
	// Retrieves the value of name.
	string getName(); 	
	// Sets the value of name.
	void setName(std::string newName); 	
	// Retrieves the value of health.
	int getHealth();
	// Sets the value of health.
	void setHealth(int newHealth); 	
	// Retrieves the value of stamina.
	int getStamina(); 	
	// Sets the value of stamina.
	void setStamina(int newStamina);
	// Retrieves the value of mana.
	int getMana(); 	
	// Sets the value of mana.
	void setMana(int newMana);
	// Retrieves the value of strength.
	int getStrength();
	// Sets the value of strength.
	void setStrength(int newStrength);
	// Retrieves the value of armor.
	int getArmor();
	// Sets the value of armor.
	void setArmor(int newArmor);

	void addItemToInventory(Item* item);
	void removeItemFromInventory(string itemName);
	void displayInventory();
	Item* findItem(string name);


	virtual void displayStats();


	//
	void attack(Character *opponent); // The Character deals damage to an opponent equal to their strength.
	void defend(); 	// The Character blocks damage equal to double their armor.
	void run(); // The Character leaves the battle.
	// virtual void chat(Character* opponent) = 0; // The Character enters a chat with an opponent.
	//

private:
	std::string name;
	int health{ 20 };
	int stamina{ 20 };
	int mana{ 20 };
	int strength{ 20 };
	int armor{ 0 };
};

#endif
