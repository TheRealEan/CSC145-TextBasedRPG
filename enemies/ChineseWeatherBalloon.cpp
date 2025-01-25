// Filename: "ChineseWeatherBalloon.cpp"
#include "ChineseWeatherBalloon.h"
using namespace std;

ChineseWeatherBalloon::ChineseWeatherBalloon(string name)
	: ChineseWeatherBalloon(name, 70, 70, 70, 10, 10) {};

ChineseWeatherBalloon::ChineseWeatherBalloon(string name, int health, int stamina, int mana, int strength, int armor)
	: Enemy(name, health, stamina, mana, strength, armor) {};
