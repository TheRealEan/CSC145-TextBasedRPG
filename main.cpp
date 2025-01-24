/*
** This project was designed for the CSC-145 Data Structures class at Franciscan University of Steubenville.
** Authors: Ian McCurdy, Noah Parkhurst, Philomene Sturgeon, Christian Wolk
** 
** Update Notes (McCurdy) - 1/23/25: Comments have been added for development clarity.
** Comments have been added specifically before member functions for Visual Studio's context clues.
** Class names are capitalized as per standard convention in both files and filenames.
** Data members were made private as per standard convention.
** Constructors now use a member-initializer list and are prototyped in the headers.
** The using namespace std was removed in the header files as per standard convention.
** Include guards are used in the header files are per standard convention.
** The mainMenu.cpp file was removed; all functionality persists in the Menu class.
** New test cases introduced in main.cpp.
* 
** Developer Note: Highlighting text and pressing CTRL + K + C comments all highlighted text. CTRL + K + U undoes it.
*/

// 
#include "Character.h"
#include "Menu.h"
#include <iostream>
using namespace std;

// Initialize starting characters.
Character dude("dude", 100, 20, 20, 50, 10);
Character bro("bro", 100, 20, 20, 50, 10);

// Define a main menu.
Menu choices;

int main() {

	/*
	** Test Case for Program
	*/

	// Testing getters and setters.
	// 
	// Show initial data members.
	cout << "Showing initial data members." << endl;
	cout << "Dude's Name: " << dude.getName() << endl
		<< "Dude's Health: " << dude.getHealth() << endl
		<< "Dude's Strength: " << dude.getStrength() << endl
		<< "Dude's Stamina: " << dude.getStamina() << endl
		<< "Dude's Mana: " << dude.getMana() << endl
		<< "Dude's Armor: " << dude.getArmor() << endl << endl;

	// Change data members.
	cout << "Changing data members." << endl << endl;
	dude.setName("radical dude");
	dude.setHealth(dude.getHealth() / 2);
	dude.setStrength(dude.getStrength() / 2);
	dude.setStamina(dude.getStamina() / 2);
	dude.setMana(dude.getMana() / 2);
	dude.setArmor(dude.getArmor() / 2);

	// Show changed data members.
	cout << "Showing changed data members." << endl;
	cout << "Dude's Name: " << dude.getName() << endl
		<< "Dude's Health: " << dude.getHealth() << endl
		<< "Dude's Strength: " << dude.getStrength() << endl
		<< "Dude's Stamina: " << dude.getStamina() << endl
		<< "Dude's Mana: " << dude.getMana() << endl
		<< "Dude's Armor: " << dude.getArmor() << endl << endl;

	// Reset to original values.
	cout << "Resetting to original values." << endl << endl;
	dude.setName("dude");
	dude.setHealth(dude.getHealth() * 2);
	dude.setStrength(dude.getStrength() * 2);
	dude.setStamina(dude.getStamina() * 2);
	dude.setMana(dude.getMana() * 2);
	dude.setArmor(dude.getArmor() * 2);

	// Test Combat Functions
	//
	// Test the attack function.
	cout << "Testing attack function." << endl;
	cout << "Bro's strength before attack: " << bro.getStrength() << endl
		<< "Dude's health before attack: " << dude.getHealth() << endl
		<< "Dude's armor before attack: " << dude.getArmor() << endl;
	bro.attack(&dude);
	cout << "Bro attacks dude!!!" << endl
		<< "Dude's health after attack: " << dude.getHealth() << endl
		<< "Dude's armor after attack: " << dude.getArmor() << endl << endl;
	dude.setHealth(100);

	// Test the defend function.
	cout << "Testing defend function." << endl;
	dude.defend();
	cout << "Bro's strength before attack: " << bro.getStrength() << endl
		<< "Dude's health before attack: " << dude.getHealth() << endl
		<< "Dude's armor before attack: " << dude.getArmor() << endl;
	bro.attack(&dude);
	cout << "Bro attacks dude!!!" << endl
		<< "Dude's health after attack: " << dude.getHealth() << endl
		<< "Dude's armor after attack: " << dude.getArmor() << endl << endl; // We don't want defense to stay permanent.

	// Test the run function.
	cout << "Testing run function." << endl;
	dude.run(); // To have better functionality with the battle sequence.

	//cout << "dude health: " << dude.getHealth() << endl;

	//bro.attack(&dude);

	//cout << "dude health: " << dude.getHealth() << endl;

	//cout << "dude armor: " << dude.getArmor() << endl;

	//dude.defend();

	//cout << "dude armor: " << dude.getArmor() << endl;

	//cout << "dude stamina: " << dude.getStamina() << endl;

	//dude.setStamina(55);

	//cout << "dude stamina: " << dude.getStamina() << endl;

	//cout << "dude mana: " << dude.getMana() << endl;

	//dude.setMana(60);

	//cout << "dude mana: " << dude.getMana() << endl;

	//cout << "dude name: " << dude.getName() << endl;

	//dude.setName("duuuuude");

	//cout << "dude name: " << dude.getName() << endl;

	//cout << "dude strength: " << dude.getStrength() << endl;

	//dude.setStrength(65);

	//cout << "dude strength: " << dude.getStrength() << endl;

	//cout << "bro health: " << bro.getHealth() << endl;

	//dude.attack(&bro);

	//cout << "bro health: " << bro.getHealth() << endl;

	//dude.run();

	//bro.run();

	//choices.mainMenu();

	return 0;
}