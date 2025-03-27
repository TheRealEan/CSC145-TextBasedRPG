// Filename: "Enemies.cpp"
#include "Enemies.h"
using namespace std;

ChineseSpyPigeon::ChineseSpyPigeon(string name)
	: ChineseSpyPigeon(name, 70, 70, 70, 10, 10, 20, battleResponses) {
	battleResponses = { "Chinese Spy Pigeon scratches you with his claws!", "Chinese Spy Pigeon pecks you!", "Chinese Spy Pigeon sends drone strike to your location!", "Chinese Spy Pigeon strikes you with his wings!", "Chinese Spy Pigeon dodges!", "Chinese Spy Pigeon flies out of the way!", "Chinese Spy Pigeon defends with his wings!", "Chinese Spy Pigeon flies out of your reach!", "Chinese Spy Pigeon flies off to spill your secrets to the Chinese government!", "Chinese Spy Pigeon flies off into the distance", "Chinese Spy Pigeon flies back to his base!", "Chinese Spy Pigeon flies into the clouds, out of view!" };
};

ChineseSpyPigeon::ChineseSpyPigeon(string name, int health, int stamina, int mana, int strength, int armor, int gold, vector<string> battleResponses)
	: Enemy(name, health, stamina, mana, strength, armor, gold, battleResponses) {
};

// ------------------------------------------------------------------ //

DannyDevito::DannyDevito(string name)
	: DannyDevito(name, 70, 70, 70, 10, 10, 20, battleResponses) {
	battleResponses = { "Danny Devito throws a bowling ball at your head!", "Danny Devito punches you in the gut!", "Danny Devito kicks you in the back of the knees!", "Danny Devito pours boiling hot nacho cheese on your head!", "Danny Devito dodges your blow!", "Danny Devito backflips out of the way!", "Danny Devito cartwheels out of the way!", "You miss!", "Danny Devito skedaddles", "Danny Devito ran out the door!", "Danny Devito throws a chair in your general direction as he runs away", "Danny Devito jumps out the window into a bush below" };
};

DannyDevito::DannyDevito(string name, int health, int stamina, int mana, int strength, int armor, int gold, vector<string> battleResponses)
	: Enemy(name, health, stamina, mana, strength, armor, gold, battleResponses) {
};

// ------------------------------------------------------------------ //

Roomba::Roomba(string name)
	: Roomba(name, 70, 70, 70, 10, 10, 20, battleResponses) {
	battleResponses = { "Roomba hits your feet!", "Roomba zaps you!", "Roomba tries to vaccuum your shoes!", "Roomba trips you!", "Roomba dodges your attack!", "Roomba rumbles out of the way!", "Your blow was blocked by Roomba's armor!", "Roomba zig-zags out of the way!", "Roomba gets taken over by a wandering cat and rumbles away", "Roomba changes it's mind and leaves", "Roomba shuts down for a software update", "Roomba gets stuck in a corner" };
};

Roomba::Roomba(string name, int health, int stamina, int mana, int strength, int armor, int gold, vector<string> battleResponses)
	: Enemy(name, health, stamina, mana, strength, armor, gold, battleResponses) {
};



// ------------------------------------------------------------------ // 
// ------------------- THE ENEMIES GRAVEYARD ------------------------ // 
// ------------------------------------------------------------------ // 


/*ChineseWeatherBalloon::ChineseWeatherBalloon(string name)
	: ChineseWeatherBalloon(name, 70, 70, 70, 10, 10, 20, battleResponses) {
	battleResponses = { "Response 1", "Response 2", "Response 3", "Response 4", "Response 5", "Response 6", "Response 7", "Response 8", "Response 9", "Response 10", "Response 11", "Response 12" };
};

ChineseWeatherBalloon::ChineseWeatherBalloon(string name, int health, int stamina, int mana, int strength, int armor, int gold, vector<string> battleResponses)
	: Enemy(name, health, stamina, mana, strength, armor, gold, battleResponses) {
};


};

// ------------------------------------------------------------------ //
// ------------------------------------------------------------------ //

Drake::Drake(string name)
	: Drake(name, 70, 70, 70, 10, 10, 20, battleResponses) {
	battleResponses = { "Response 1", "Response 2", "Response 3", "Response 4", "Response 5", "Response 6", "Response 7", "Response 8", "Response 9", "Response 10", "Response 11", "Response 12" };
};

// ------------------------------------------------------------------ //

Drake::Drake(string name, int health, int stamina, int mana, int strength, int armor, int gold, vector<string> battleResponses)
	: Enemy(name, health, stamina, mana, strength, armor, gold, battleResponses) {
};

// ------------------------------------------------------------------ //

Goblin::Goblin(string name)
	: Goblin(name, 70, 70, 70, 10, 10, 20, battleResponses) {
	battleResponses = { "Response 1", "Response 2", "Response 3", "Response 4", "Response 5", "Response 6", "Response 7", "Response 8", "Response 9", "Response 10", "Response 11", "Response 12" };
};

Goblin::Goblin(string name, int health, int stamina, int mana, int strength, int armor, int gold, vector<string> battleResponses)
	: Enemy(name, health, stamina, mana, strength, armor, gold, battleResponses) {
};

// ------------------------------------------------------------------ //

Harpy::Harpy(string name)
	: Harpy(name, 70, 70, 70, 10, 10, 20, battleResponses) {
	battleResponses = { "Response 1", "Response 2", "Response 3", "Response 4", "Response 5", "Response 6", "Response 7", "Response 8", "Response 9", "Response 10", "Response 11", "Response 12" };
};

Harpy::Harpy(string name, int health, int stamina, int mana, int strength, int armor, int gold, vector<string> battleResponses)
	: Enemy(name, health, stamina, mana, strength, armor, gold, battleResponses) {
};

// ------------------------------------------------------------------ //

Hippie::Hippie(string name)
	: Hippie(name, 70, 70, 70, 10, 10, 20, battleResponses) {
	battleResponses = { "Response 1", "Response 2", "Response 3", "Response 4", "Response 5", "Response 6", "Response 7", "Response 8", "Response 9", "Response 10", "Response 11", "Response 12" };
};

Hippie::Hippie(string name, int health, int stamina, int mana, int strength, int armor, int gold, vector<string> battleResponses)
	: Enemy(name, health, stamina, mana, strength, armor, gold, battleResponses) {
};

// ------------------------------------------------------------------ //

Merfolk::Merfolk(string name)
	: Merfolk(name, 70, 70, 70, 10, 10, 20, battleResponses) {
	battleResponses = { "Response 1", "Response 2", "Response 3", "Response 4", "Response 5", "Response 6", "Response 7", "Response 8", "Response 9", "Response 10", "Response 11", "Response 12" };
};

Merfolk::Merfolk(string name, int health, int stamina, int mana, int strength, int armor, int gold, vector<string> battleResponses)
	: Enemy(name, health, stamina, mana, strength, armor, gold, battleResponses) {
};

// ------------------------------------------------------------------ //

Nickelback::Nickelback(string name)
	: Nickelback(name, 70, 70, 70, 10, 10, 20, battleResponses) {
	battleResponses = { "Response 1", "Response 2", "Response 3", "Response 4", "Response 5", "Response 6", "Response 7", "Response 8", "Response 9", "Response 10", "Response 11", "Response 12" };
};

Nickelback::Nickelback(string name, int health, int stamina, int mana, int strength, int armor, int gold, vector<string> battleResponses)
	: Enemy(name, health, stamina, mana, strength, armor, gold, battleResponses) {
};

// ------------------------------------------------------------------ //

Ninja::Ninja(string name)
	: Ninja(name, 70, 70, 70, 10, 10, 20, battleResponses) {
	battleResponses = { "Response 1", "Response 2", "Response 3", "Response 4", "Response 5", "Response 6", "Response 7", "Response 8", "Response 9", "Response 10", "Response 11", "Response 12" };
};

Ninja::Ninja(string name, int health, int stamina, int mana, int strength, int armor, int gold, vector<string> battleResponses)
	: Enemy(name, health, stamina, mana, strength, armor, gold, battleResponses) {
};

// ------------------------------------------------------------------ //

Protestor::Protestor(string name)
	: Protestor(name, 70, 70, 70, 10, 10, 20, battleResponses) {
	battleResponses = { "Response 1", "Response 2", "Response 3", "Response 4", "Response 5", "Response 6", "Response 7", "Response 8", "Response 9", "Response 10", "Response 11", "Response 12" };
};

Protestor::Protestor(string name, int health, int stamina, int mana, int strength, int armor, int gold, vector<string> battleResponses)
	: Enemy(name, health, stamina, mana, strength, armor, gold, battleResponses) {
};

Orc::Orc(string name)
	: Orc(name, 70, 70, 70, 10, 10, 20, battleResponses) {
	battleResponses = { "Response 1", "Response 2", "Response 3", "Response 4", "Response 5", "Response 6", "Response 7", "Response 8", "Response 9", "Response 10", "Response 11", "Response 12" };
};

Orc::Orc(string name, int health, int stamina, int mana, int strength, int armor, int gold, vector<string> battleResponses)
	: Enemy(name, health, stamina, mana, strength, armor, gold, battleResponses) {
};

// ------------------------------------------------------------------ //

Pirate::Pirate(string name)
	: Pirate(name, 70, 70, 70, 10, 10, 20, battleResponses) {
	battleResponses = { "Response 1", "Response 2", "Response 3", "Response 4", "Response 5", "Response 6", "Response 7", "Response 8", "Response 9", "Response 10", "Response 11", "Response 12" };
};

Pirate::Pirate(string name, int health, int stamina, int mana, int strength, int armor, int gold, vector<string> battleResponses)
	: Enemy(name, health, stamina, mana, strength, armor, gold, battleResponses) {
};


// ------------------------------------------------------------------ //

Samurai::Samurai(string name)
	: Samurai(name, 70, 70, 70, 10, 10, 20, battleResponses) {
	battleResponses = { "Response 1", "Response 2", "Response 3", "Response 4", "Response 5", "Response 6", "Response 7", "Response 8", "Response 9", "Response 10", "Response 11", "Response 12" };
};

Samurai::Samurai(string name, int health, int stamina, int mana, int strength, int armor, int gold, vector<string> battleResponses)
	: Enemy(name, health, stamina, mana, strength, armor, gold, battleResponses) {
};

// ------------------------------------------------------------------ //

Swiftie::Swiftie(string name)
	: Swiftie(name, 70, 70, 70, 10, 10, 20, battleResponses) {
	battleResponses = { "Response 1", "Response 2", "Response 3", "Response 4", "Response 5", "Response 6", "Response 7", "Response 8", "Response 9", "Response 10", "Response 11", "Response 12" };
};

Swiftie::Swiftie(string name, int health, int stamina, int mana, int strength, int armor, int gold, vector<string> battleResponses)
	: Enemy(name, health, stamina, mana, strength, armor, gold, battleResponses) {
};

// ------------------------------------------------------------------ //

TeaKettle::TeaKettle(string name)
	: TeaKettle(name, 70, 70, 70, 10, 10, 20, battleResponses) {
	battleResponses = { "Response 1", "Response 2", "Response 3", "Response 4", "Response 5", "Response 6", "Response 7", "Response 8", "Response 9", "Response 10", "Response 11", "Response 12" };
};

TeaKettle::TeaKettle(string name, int health, int stamina, int mana, int strength, int armor, int gold, vector<string> battleResponses)
	: Enemy(name, health, stamina, mana, strength, armor, gold, battleResponses) {
};

// ------------------------------------------------------------------ //

TrashCan::TrashCan(string name)
	: TrashCan(name, 70, 70, 70, 10, 10, 20, battleResponses) {
	battleResponses = { "Response 1", "Response 2", "Response 3", "Response 4", "Response 5", "Response 6", "Response 7", "Response 8", "Response 9", "Response 10", "Response 11", "Response 12" };
};

TrashCan::TrashCan(string name, int health, int stamina, int mana, int strength, int armor, int gold, vector<string> battleResponses)
	: Enemy(name, health, stamina, mana, strength, armor, gold, battleResponses) {
};*/
