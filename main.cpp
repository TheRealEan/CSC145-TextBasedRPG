// Developer Note: Highlighting text and pressing CTRL + K + C comments all highlighted text. CTRL + K + U undoes it.

// Import Libraries
#include <iostream>
// Import Primary Classes
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "Menu.h"
// Import Enemy Classes
#include "enemies/ChineseSpyPigeon.h"
#include "enemies/ChineseWeatherBalloon.h"
#include "enemies/DannyDevito.h"
#include "enemies/Drake.h"
#include "enemies/Goblin.h"
#include "enemies/Harpy.h"
#include "enemies/Hippie.h"
#include "enemies/Merfolk.h"
#include "enemies/Nickelback.h"
#include "enemies/Ninja.h"
#include "enemies/NotSoPeacefulProtestor.h"
#include "enemies/Orc.h"
#include "enemies/Pirate.h"
#include "enemies/Roomba.h"
#include "enemies/Samurai.h"
#include "enemies/Swiftie.h"
#include "enemies/TeaKettle.h"
#include "enemies/TrashCan.h"
// Set Namespace
using namespace std;

// Initialize Starting Players

// Player object dude
Player dude("dude", 100, 20, 20, 50, 10);
// Player object bro
Player bro("bro", 100, 20, 20, 50, 10);

// Main Menu
Menu choices;

int main() {

	// Show initial player stats.

	cout << "Showing initial player stats." << endl;
	dude.displayStats();
	bro.displayStats();
	cout << "------------------------------" << endl;

	// Change data members.

	cout << "Changing data members." << endl << endl;
	dude.setName("radical dude");
	dude.setHealth(dude.getHealth() / 2);
	dude.setStrength(dude.getStrength() / 2);
	dude.setStamina(dude.getStamina() / 2);
	dude.setMana(dude.getMana() / 2);
	dude.setArmor(dude.getArmor() / 2);
	cout << "------------------------------" << endl;

	// Show changed data members.

	cout << "Showing changed player stats." << endl;
	dude.displayStats();
	cout << "------------------------------" << endl;

	// Reset to original values.

	cout << "Resetting to original values." << endl << endl;
	dude.setName("dude");
	dude.setHealth(dude.getHealth() * 2);
	dude.setStrength(dude.getStrength() * 2);
	dude.setStamina(dude.getStamina() * 2);
	dude.setMana(dude.getMana() * 2);
	dude.setArmor(dude.getArmor() * 2);
	cout << "------------------------------" << endl;

	// Test the attack function.

	cout << "Testing attack function." << endl;
	cout << "Dude's pre-attack statistics:" << endl;
	dude.displayStats();
	bro.attack(&dude);
	cout << "Bro attacks dude!!!" << endl;
	cout << "Dude's post-attack statistics:" << endl;
	dude.displayStats();
	dude.setHealth(100); // Reset health.
	cout << "------------------------------" << endl;

	// Test the defend function.

	cout << "Testing defend function." << endl;
	cout << "Dude's pre-defend statistics:" << endl;
	dude.defend();
	cout << "Dude's post-defend statistics:" << endl;
	dude.displayStats();
	bro.attack(&dude);
	cout << "Bro attacks dude!!!" << endl;
	cout << "Dude's post-attack statistics:" << endl;
	dude.displayStats();
	cout << "------------------------------" << endl;

	// Test the run function.

	cout << "Testing run function." << endl;
	dude.run();
	cout << "------------------------------" << endl;

	// Create enemy objects.

	ChineseSpyPigeon harold("Harold");
	ChineseWeatherBalloon ca122("CA-112");
	DannyDevito danny("Danny DeVito");
	Drake richard("Richard");
	Goblin goblin("Bimbo");
	Harpy harpy("Patricia");
	Hippie lennon("John Lennon");
	Merfolk sammy("Sammy");
	Nickelback nickelback("Nickelback");
	Ninja gus("Gus");
	NotSoPeacefulProtestor travis("Travis");
	Orc wesley("Wesley");
	Pirate jack("Jack");
	Roomba xae112("XAE-112");
	Samurai yoshido("Yoshido");
	Swiftie fangirl("Karen");
	TeaKettle kettle("Mr. Coffee");
	TrashCan trashCan("Oskar the Grouch's Home");

	// Display enemy statistics.

	harold.displayStats();
	cout << "------------------------------" << endl;
	ca122.displayStats();
	cout << "------------------------------" << endl;
	danny.displayStats();
	cout << "------------------------------" << endl;
	richard.displayStats();
	cout << "------------------------------" << endl;
	goblin.displayStats();
	cout << "------------------------------" << endl;
	harpy.displayStats();
	cout << "------------------------------" << endl;
	lennon.displayStats();
	cout << "------------------------------" << endl;
	sammy.displayStats();
	cout << "------------------------------" << endl;
	nickelback.displayStats();
	cout << "------------------------------" << endl;
	gus.displayStats();
	cout << "------------------------------" << endl;
	travis.displayStats();
	cout << "------------------------------" << endl;
	wesley.displayStats();
	cout << "------------------------------" << endl;
	jack.displayStats();
	cout << "------------------------------" << endl;
	xae112.displayStats();
	cout << "------------------------------" << endl;
	yoshido.displayStats();
	cout << "------------------------------" << endl;
	fangirl.displayStats();
	cout << "------------------------------" << endl;
	kettle.displayStats();
	cout << "------------------------------" << endl;
	trashCan.displayStats();
	cout << "------------------------------" << endl;

	return 0;
}