// Developer Note: Highlighting text and pressing CTRL + K + C comments all highlighted text. CTRL + K + U undoes it.
#include <iostream>
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "Enemies.h"
#include "Menu.h"
#include "Extra.h"
using namespace std;

int main() {
	Player richard("Richard the Third");
	
	startBattle(richard);

	return 0;
}
