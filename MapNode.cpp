#include <conio.h> // Includes the _getch() function to retrieve keyboard input.
#include <string>
#include <tuple> // Includes std::ignore.
#include <vector>
#include "MapNode.h"
#include "Menu.h"
#include "Enemy.h"
#include "Shop.h"
#include "TalkingNPC.h"
#include "./utilities/Generator.h"
//#include "./utilities/KeyBindings.h" // Brings over keyboard input constants.
//#include "./utilities/Music.h"

MapNode::MapNode(std::string nombre, std::string des)
	: MapNode(nombre, des, nullptr, nullptr, nullptr, nullptr) {}
MapNode::MapNode(std::string nombre, std::string des, MapNode* n, MapNode* w, MapNode* e, MapNode* s)
	: locationName{ nombre }, description{ des }, menu{ new Menu }, north {n}, west{ w }, east{ e }, south{ s } {}

//void MapNode::execLocation(Player* p) {
//	Player* player = p;
//
//	backgroundPlay("theme.wav");
//	int choice{ KEY_UP };
//	// The highlighted yellow text, when Enter key is pressed this option is selected.
//	int index{ 1 };
//	std::vector<MenuOption> options{};
//	do {
//		menu->clear();
//		std::cout << getLocationName() << std::endl;
//
//		// Identify the options to list for the player.
//		options.emplace_back(
//			"Display Player Stats",
//			[player] { player->displayStats(); }
//		);
//		options.emplace_back("Manage Inventory",
//			[new InventoryMenu(player)] { menu->InventoryMenu() }
//		);
//		// Add enemies to options.
//		if (enemy1) {
//			options.emplace_back(std::to_string(options.size() + 1) + ". Fight " + enemy1->getName());
//		}
//		if (enemy2) {
//			options.emplace_back(std::to_string(options.size() + 1) + ". Fight " + enemy2->getName());
//		}
//		if (enemy3) {
//			options.emplace_back(std::to_string(options.size() + 1) + ". Fight " + enemy3->getName());
//		}
//		// Add shops to options.
//		if (shop1) {
//			options.emplace_back(std::to_string(options.size() + 1) + ". Enter Shop 1");
//		}
//		if (shop2) {
//			options.emplace_back(std::to_string(options.size() + 1) + ". Enter Shop 2");
//		}
//		if (shop3) {
//			options.emplace_back(std::to_string(options.size() + 1) + ". Enter Shop 3");
//		}
//		// Add talkingNPCs to options.
//		if (npc1) {
//			options.emplace_back(std::to_string(options.size() + 1) + ". Chat with " + npc1->getName());
//		}
//		if (npc2) {
//			options.emplace_back(std::to_string(options.size() + 1) + ". Chat with " + npc2->getName());
//		}
//		if (npc3) {
//			options.emplace_back(std::to_string(options.size() + 1) + ". Chat with " + npc3->getName());
//		}
//
//		options.emplace_back(
//			std::to_string(options.size() + 1) + ". Quit Game"
//		);
//
//		// Display options
//		options[index - 1] = menu->yellow(options[index - 1]);
//		for (int i = 0; i < options.size(); i++) {
//			std::cout << options[i] << "\n";
//		}
//
//		choice = _getch(); // Take input from the keyboard.
//
//		int index_max = options.size();
//		switch (choice) {
//		case KEY_UP:
//			if (index != 1) index--;
//			else index = index_max;
//			break;
//		case KEY_DOWN:
//			if (index != index_max) index++;
//			else index = 1;
//			break;
//		case KEY_ENTER:
//			if (index != index_max) {
//
//			}
//			break;
//		}
//
//
//	} while (!(index == (options.size() && choice == KEY_ENTER)));
//}

// Handle cardinal setters for both directions (e.g. 1->setEast(2) counts also as 2->setWest(1)).
std::string const MapNode::getLocationName() { return locationName; }
void MapNode::setLocationName(std::string nombre) { locationName = nombre; }
std::string const MapNode::getDescription() { return description; }
void MapNode::setDescription(std::string des) { description = des; }
MapNode* const MapNode::getNorth() { return north; }
void MapNode::setNorth(MapNode* n) { north = n; n->setSouth(this); }
MapNode* const MapNode::getWest() { return west; }
void MapNode::setWest(MapNode* w) { west = w; w->setEast(this); }
MapNode* const MapNode::getEast() { return east; }
void MapNode::setEast(MapNode* e) { east = e; e->setWest(this); }
MapNode* const MapNode::getSouth() { return south; }
void MapNode::setSouth(MapNode* s) { south = s; s->setNorth(this); }

Enemy* MapNode::getEnemy(int index) {
	switch (index) {
	case 1: { return enemy1; }
	case 2: { return enemy2; }
	case 3: { return enemy3; }
	default: { return nullptr; }
	}
}
void MapNode::setEnemy(Enemy* en) {
	if (!enemy1) { enemy1 = en; }
	else if (!enemy2) { enemy2 = en; }
	else if (!enemy3) { enemy3 = en; }
	else { return; }
}
void MapNode::setEnemy(Enemy* en, int index) {
	switch (index) {
	case 1: { enemy1 = en; }
	case 2: { enemy2 = en; }
	case 3: { enemy3 = en; }
	}
}
void MapNode::setEnemies(Enemy* en1, Enemy* en2, Enemy* en3) {
	enemy1 = en1;
	enemy2 = en2;
	enemy3 = en3;
}

Shop* MapNode::getShop(int index) {
	switch (index) {
	case 1: { return shop1; }
	case 2: { return shop2; }
	case 3: { return shop3; }
	default: { return nullptr; }
	}
}
void MapNode::setShop(Shop* sh) {
	if (!shop1) { shop1 = sh; }
	else if (!shop2) { shop2 = sh; }
	else if (!shop3) { shop3 = sh; }
	else { return; }
}
void MapNode::setShop(Shop* sh, int index) {
	switch (index) {
	case 1: { shop1 = sh; }
	case 2: { shop2 = sh; }
	case 3: { shop3 = sh; }
	default: { return; }
	}
}
void MapNode::setShops(Shop* sh1, Shop* sh2, Shop* sh3) {
	shop1 = sh1;
	shop2 = sh2;
	shop3 = sh3;
}

TalkingNPC* MapNode::getNPC(int index) {
	switch (index) {
	case 1: { return npc1; }
	case 2: { return npc2; }
	case 3: { return npc3; }
	default: { return nullptr; }
	}
}
void MapNode::setNPC(TalkingNPC* np) {
	if (!npc1) { npc1 = np; }
	else if (!npc2) { npc2 = np; }
	else if (!npc3) { npc3 = np; }
	else { return; }
}
void MapNode::setNPC(TalkingNPC* np, int index) {
	switch (index) {
	case 1: { npc1 = np; }
	case 2: { npc2 = np; }
	case 3: { npc3 = np; }
	default: { return; }
	}
}
void MapNode::setNPCs(TalkingNPC* np1, TalkingNPC* np2, TalkingNPC* np3) {
	npc1 = np1;
	npc2 = np2;
	npc3 = np3;
}

Map::Map(Player* p) {
	// Set the player.
	player = p;

	// The Ohio Turnpike
	MapNode* tollgate = new MapNode("Tollgate Town", "A toll town is ahead.");
	MapNode* buckeye = new MapNode("Buckeye Bend", "A sharp bend.");
	MapNode* cuyahoga = new MapNode("Cuyahoga Cross", "Something descriptive.");
	MapNode* jefferson = new MapNode("The Bridge of Jefferson", "Something else.");
	MapNode* ctt = new MapNode("CTT - Ground Floor, Room 03", "A challenger approaches...");

	// Link the nodes.
	tollgate->setEast(buckeye);
	buckeye->setNorth(cuyahoga);
	cuyahoga->setEast(jefferson);
	jefferson->setEast(ctt);

	// Create details for tollgate.
	tollgate->setShop(generateShop());
	tollgate->setShop(generateShop());

	// Create details for buckeye.
	buckeye->setEnemy(new Roomba);

	// Create details for cuyahoga.
	cuyahoga->setEnemy(new ChineseSpyPigeon);

	// Create details for jefferson.
	jefferson->setEnemy(new DannyDevito);

	// Create details for ctt.
	ctt->setEnemy(new TylerBrown);

}

MapNode* Map::getIndex() { return index; }
void Map::setIndex(MapNode* node) { index = node; }
MapNode* Map::getHead() { return head; }
void Map::setHead(MapNode* node) { head = node; }
