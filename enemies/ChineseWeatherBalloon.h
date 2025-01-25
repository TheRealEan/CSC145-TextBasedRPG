// Filename: "ChineseWeatherBalloon.h"
#include <string>
#include "../Enemy.h"
#ifndef CHINESEWEATHERBALLOON_H
#define CHINESEWEATHERBALLOON_H

class ChineseWeatherBalloon : public Enemy {
public:
	// Constructors and Destructors
	ChineseWeatherBalloon(std::string name);
	ChineseWeatherBalloon(std::string name, int health, int stamina, int mana, int strength, int armor);
	virtual ~ChineseWeatherBalloon() = default;
};

#endif
