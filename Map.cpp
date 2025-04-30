#include <conio.h> // Includes the _getch() function to retrieve keyboard input.
#include <string>
#include <tuple> // Includes std::ignore.
#include <vector>
#include "Map.h"
#include "Menu.h"
#include "Enemy.h"
#include "Shop.h"
#include "Player.h"
#include "TalkingNPC.h"
#include "./utilities/Generator.h"
#include "./utilities/KeyBindings.h" // brings over keyboard input constants.
#include "./utilities/Music.h"

MapNode::MapNode(const std::string& nombre, const std::string& des, Map* own)
	: MapNode(nombre, des, own, nullptr, nullptr, nullptr, nullptr) {}
MapNode::MapNode(const std::string& nombre, const std::string& des, Map* own, MapNode* n, MapNode* w, MapNode* e, MapNode* s)
	: locationName{ nombre }, description{ des }, owner{ own }, menu { new Menu }, north{ n }, west{ w }, east{ e }, south{ s } {}

void MapNode::execLocation(Player* p) {
	Player* player = p;

	backgroundPlay("theme.wav");
	int choice{ KEY_UP };
	// The highlighted yellow text, when Enter key is pressed this option is selected.
	int index{ 1 };
	
	
	int optionsSize = 0; // The size of all the options available.
	//std::vector<std::string> options{};
	
	do {
		menu->clear();
		std::cout << getLocationName() << "\n\n";

		// Reset options for each run.
		LinkedList<OptionNode*>* options = new LinkedList<OptionNode*>;
		optionsSize = 0; // The size of all the options available.

		// Identify the options to list for the player.
		options->pushBack(
			new OptionNode(
				std::to_string(optionsSize + 1) + ". Display Player Stats",
				[player] {
					std::cout << std::endl;
					player->displayStats();
					std::cout << "Press enter to continue... \n";
					(void)_getch(); }
			)
		); optionsSize++;

		options->pushBack(
			new OptionNode(
				std::to_string(optionsSize + 1) + ". Manage Inventory",
				[player] { InventoryMenu menu(player); menu.manageInventory(); })
		); optionsSize++;


		// Identify possible cardinal directions for the player to navigate.
		if (north) {
			MapNode* node = north;
			options->pushBack(
				new OptionNode(
					std::to_string(optionsSize + 1) + ". Travel North",
					[player, node] { 
						std::string flag{ "yes" };
						std::cout << std::endl;
						std::cout << node->getDescription() << "\n";
						std::cout << "Do you wish to travel here? Type 'yes' to accept." << std::endl;
						std::cin.clear(); std::getline(std::cin, flag);
						if (flag != "yes" && flag != "y") { return; }
						node->execLocation(player); }
				)
			); optionsSize++;
		}
		if (west) {
			MapNode* node = west;
			options->pushBack(
				new OptionNode(
					std::to_string(optionsSize + 1) + ". Travel West",
					[player, node] {
						std::string flag{ "yes" };
						std::cout << std::endl;
						std::cout << node->getDescription() << "\n";
						std::cout << "Do you wish to travel here? Type 'yes' to accept." << std::endl;
						std::cin.clear(); std::getline(std::cin, flag);
						if (flag != "yes" && flag != "y") { return; }
						node->execLocation(player); }
				)
			); optionsSize++;
		}
		if (east) {
			MapNode* node = east;
			options->pushBack(
				new OptionNode(
					std::to_string(optionsSize + 1) + ". Travel East",
					[player, node] {
						std::string flag{ "yes" };
						std::cout << std::endl;
						std::cout << node->getDescription() << "\n";
						std::cout << "Do you wish to travel here? Type 'yes' to accept." << std::endl;
						std::cin.clear(); std::getline(std::cin, flag);
						if (flag != "yes" && flag != "y") { return; }
						node->execLocation(player); }
				)
			); optionsSize++;
		}
		if (south) {
			MapNode* node = south;
			options->pushBack(
				new OptionNode(
					std::to_string(optionsSize + 1) + ". Travel South",
					[player, node] {
						std::string flag{ "yes" };
						std::cout << std::endl;
						std::cout << node->getDescription() << "\n";
						std::cout << "Do you wish to travel here? Type 'yes' to accept." << std::endl;
						std::cin.clear(); std::getline(std::cin, flag);
						if (flag != "yes" && flag != "y") { return; }
						node->execLocation(player); }
				)
			); optionsSize++;
		}

		// Add enemies to options.
		if (enemy1) {
			Enemy* enemy = enemy1;
			options->pushBack(
				new OptionNode(
					std::to_string(optionsSize + 1) + ". Fight " + enemy1->getName(),
					[player, enemy] { BattleMenu menu(player, enemy); })
			); optionsSize++;
		}
		if (enemy2) {
			Enemy* enemy = enemy2;
			options->pushBack(
				new OptionNode(
					std::to_string(optionsSize + 1) + ". Fight " + enemy2->getName(),
					[player, enemy] { BattleMenu menu(player, enemy); }
				)
			); optionsSize++;
		}
		if (enemy3) {
			Enemy* enemy = enemy3;
			options->pushBack(
				new OptionNode(
					std::to_string(optionsSize + 1) + ". Fight " + enemy3->getName(),
					[player, enemy] { BattleMenu menu(player, enemy); }
				)
			); optionsSize++;
		}
		// Add shops to options.
		if (shop1) {
			Shop* shop = shop1;
			options->pushBack(
				new OptionNode(
					std::to_string(optionsSize + 1) + ". Enter Shop 1",
					[player, shop] { ShopMenu menu(player, shop); }
				)
			); optionsSize++;

		}
		if (shop2) {
			Shop* shop = shop2;
			options->pushBack(
				new OptionNode(
					std::to_string(optionsSize + 1) + ". Enter Shop 2",
					[player, shop] { ShopMenu menu(player, shop); }
				)
			); optionsSize++;
		}
		if (shop3) {
			Shop* shop = shop3;
			options->pushBack(
				new OptionNode(
					std::to_string(optionsSize + 1) + ". Enter Shop 3",
					[player, shop] { ShopMenu menu(player, shop); }
				)
			); optionsSize++;
		}
		// Add talkingNPCs to options.
		if (npc1) {
			TalkingNPC* npc = npc1;
			options->pushBack(
				new OptionNode(
					std::to_string(optionsSize + 1) + ". Chat with " + npc->getName(),
					[npc] { npc->printDialogue(0); }
				)
			); optionsSize++;
		}
		if (npc2) {
			TalkingNPC* npc = npc2;
			options->pushBack(
				new OptionNode(
					std::to_string(optionsSize + 1) + ". Chat with " + npc->getName(),
					[npc] { npc->printDialogue(0); }
				)
			); optionsSize++;
		}
		if (npc3) {
			TalkingNPC* npc = npc3;
			options->pushBack(
				new OptionNode(
					std::to_string(optionsSize + 1) + ". Chat with " + npc->getName(),
					[npc] { npc->printDialogue(0); }
				)
			); optionsSize++;
		}

		options->pushBack(
			new OptionNode(
				std::to_string(optionsSize + 1) + ". Show Map",
				[this] {
					menu->clear();
					std::cout << "\nWorld Map:\n";
					auto highlight = [&](const std::string& name) {
						return (name == this->getLocationName())
							? menu->yellow(name)
							: name;
						};
					std::cout << "                       [" << highlight("Cuyahoga Cross") << "] <--> ["
						<< highlight("The Bridge of Jefferson") << "] <--> ["
						<< highlight("CTT - Ground Floor, Room 03") << "]\n";
					std::cout << "                              ||\n";
					std::cout << " [" << highlight("Tollgate Town") << "] <--> ["
						<< highlight("Buckeye Bend") << "]\n\n";

					std::cout << "Press enter to continue... ";
					(void)_getch();
				}
			)
		); optionsSize++;


		options->pushBack(
			new OptionNode(
				std::to_string(optionsSize + 1) + ". Return to Start Menu",
				[this] {
					Map* m = this->getMap();
					StartMenu* sm = m->getStartMenu();
					sm->setLastLocation(this);
					std::cout << "\nReturning to Start Menu\nPress enter to continue... ";
					(void)_getch();
					throw 1;   
				}
			)
		); optionsSize++;

		// Display options
		Node<OptionNode*>* current = options->getHead();
		int ctr = 1; // Counts the lines.
		while (current) {
			std::string text = current->data->description;
			if (ctr == index) {
				text = menu->yellow(std::move(text));
			}
			std::cout << text << "\n";

			current = current->nextNode;
			ctr++;
		}

		choice = _getch(); // Take input from the keyboard.

		int index_max = ctr - 1;
		switch (choice) {
		case KEY_UP:
			if (index != 1) index--;
			else index = index_max;
			break;
		case KEY_DOWN:
			if (index != index_max) index++;
			else index = 1;
			break;
		case KEY_ENTER:
			Node<OptionNode*>* node = options->getHead();
			for (int i = 1; i < index && node; ++i) {
				node = node->nextNode;
			}

			if (node) node->data->execute();
			break;
		}


	} while (!(index == optionsSize && choice == KEY_ENTER));
}

// Handle cardinal setters for both directions (e.g. 1->setEast(2) counts also as 2->setWest(1)).
std::string const MapNode::getLocationName() { return locationName; }
void MapNode::setLocationName(std::string nombre) { locationName = nombre; }
std::string const MapNode::getDescription() { return description; }
void MapNode::setDescription(std::string des) { description = des; }
Map* const MapNode::getMap() { return owner; }
void MapNode::setMap(Map* m) { owner = m; }
MapNode* const MapNode::getNorth() { return north; }
void MapNode::setNorth(MapNode* n) { north = n; }
MapNode* const MapNode::getWest() { return west; }
void MapNode::setWest(MapNode* w) { west = w; }
MapNode* const MapNode::getEast() { return east; }
void MapNode::setEast(MapNode* e) { east = e; }
MapNode* const MapNode::getSouth() { return south; }
void MapNode::setSouth(MapNode* s) { south = s; }

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

Map::Map(Player* p, StartMenu* sm)
	: player(p), startMenu(sm) {

	// The Ohio Turnpike
	MapNode* tollgate = new MapNode(
		"Tollgate Town",
		"A dusty way-station clustered around the interstate toll-booths.\n"
		"Lanterns swing in the breeze and the air smells of diesel and kettle-corn.",
		this
	);
	MapNode* buckeye = new MapNode(
		"Buckeye Bend",
		"The highway hooks into a tight horseshoe curve here.\n"
		"Scarlet buckeye trees lean over the asphalt, their nuts rattling on the tarmac.",
		this
	);
	MapNode* cuyahoga = new MapNode(
		"Cuyahoga Cross",
		"You reach an old covered bridge spanning the tea-colored Cuyahoga River.\n"
		"Weather-beaten signposts point toward long-abandoned canal trails.",
		this
	);
	MapNode* jefferson = new MapNode(
		"The Bridge of Jefferson",
		"A soaring steel truss bridge.\n"
		"Plaques quoting Jefferson on free travel line the railings while the wind whistles through the cables.",
		this
	);
	MapNode* ctt = new MapNode(
		"CTT - Ground Floor, Room 03",
		"Static lights emanate from the televisions amidst the shadows of the room.\n"
		"Chairs and tables are scattered about and as the server racks hum, a single console blinks an ominous prompt.",
		this
	);

	// Link the nodes.
	tollgate->setEast(buckeye); buckeye->setWest(tollgate);
	buckeye->setNorth(cuyahoga); cuyahoga->setSouth(buckeye);
	cuyahoga->setEast(jefferson); jefferson->setWest(cuyahoga);
	jefferson->setEast(ctt); ctt->setWest(jefferson);

	// Set head and index.
	setHead(tollgate); setIndex(tollgate);

	// Create details for tollgate.
	tollgate->setShop(generateShop());
	tollgate->setShop(generateShop());
	tollgate->setNPC(new Hermit);

	// Create details for buckeye.
	buckeye->setEnemy(new Roomba);

	// Create details for cuyahoga.
	cuyahoga->setEnemy(new ChineseSpyPigeon);
	cuyahoga->setNPC(new Salesman);

	// Create details for jefferson.
	jefferson->setEnemy(new DannyDevito);

	// Create details for ctt.
	ctt->setEnemy(new TylerBrown);

}

Player* Map::getPlayer() { return player; }
void Map::setPlayer(Player* p) { player = p; }
StartMenu* Map::getStartMenu() { return startMenu; }
void Map::setStartMenu(StartMenu* sm) { startMenu = sm; }
MapNode* Map::getIndex() { return index; }
void Map::setIndex(MapNode* node) { index = node; }
MapNode* Map::getHead() { return head; }
void Map::setHead(MapNode* node) { head = node; }
