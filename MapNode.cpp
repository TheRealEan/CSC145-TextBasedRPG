#include "MapNode.h"
#include "Enemy.h"
#include "Shop.h"
#include "TalkingNPC.h"
#include "./utilities/Generator.h"

MapNode::MapNode(std::string nombre, std::string des)
	: MapNode(nombre, des, nullptr, nullptr, nullptr, nullptr) {}
MapNode::MapNode(std::string nombre, std::string des, MapNode* n, MapNode* w, MapNode* e, MapNode* s)
	: locationName{ nombre }, description{ des }, north{ n }, west{ w }, east{ e }, south{ s } {}

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

Map::Map() {
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
