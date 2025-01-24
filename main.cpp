#include"character.h"
#include"menu.h"
#include<iostream>

using namespace std;

//This is all demo to make sure everything works, everything here can be deleted once confirmed it works

character dude("dude", 100, 20, 20, 50, 10);

character bro("bro", 100, 20, 20, 50, 10);

menu choices;

int main() {
	cout << "dude health: " << dude.getHealth() << endl;

	bro.attack(&dude);

	cout << "dude health: " << dude.getHealth() << endl;

	cout << "dude armor: " << dude.getArmor() << endl;

	dude.defend();

	cout << "dude armor: " << dude.getArmor() << endl;

	cout << "dude stamina: " << dude.getStamina() << endl;

	dude.setStamina(55);

	cout << "dude stamina: " << dude.getStamina() << endl;

	cout << "dude mana: " << dude.getMana() << endl;

	dude.setMana(60);

	cout << "dude mana: " << dude.getMana() << endl;

	cout << "dude name: " << dude.getName() << endl;

	dude.setName("duuuuude");

	cout << "dude name: " << dude.getName() << endl;

	cout << "dude strength: " << dude.getStrength() << endl;

	dude.setStrength(65);

	cout << "dude strength: " << dude.getStrength() << endl;

	cout << "bro health: " << bro.getHealth() << endl;

	dude.attack(&bro);

	cout << "bro health: " << bro.getHealth() << endl;

	dude.run();

	bro.run();

	choices.mainMenu();
}