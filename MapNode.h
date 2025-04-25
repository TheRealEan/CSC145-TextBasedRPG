#ifndef MAPNODE_H
#define MAPNODE_H
#include <string>
class Enemy;
class Shop;
class TalkingNPC;

class MapNode {
public:
	MapNode(std::string nombre, std::string des);
	// Primary constructor. Use setters for other variables.
	MapNode(std::string nombre, std::string des, MapNode* n, MapNode* w, MapNode* e, MapNode* s);

	std::string const getLocationName();
	void setLocationName(std::string nombre);
	std::string const getDescription();
	void setDescription(std::string des);
	MapNode* const getNorth();
	void setNorth(MapNode* n);
	MapNode* const getWest();
	void setWest(MapNode* w);
	MapNode* const getEast();
	void setEast(MapNode* e);
	MapNode* const getSouth();
	void setSouth(MapNode* s);

	// Getters for specified enemies, shops, and talking NPCs.
	Enemy* getEnemy(int index);
	void setEnemy(Enemy* en);
	void setEnemy(Enemy* en, int index);
	void setEnemies(Enemy* en1, Enemy* en2, Enemy* en3);

	Shop* getShop(int index);
	void setShop(Shop* sh);
	void setShop(Shop* sh, int index);
	void setShops(Shop* sh1, Shop* sh2, Shop* sh3);

	TalkingNPC* getNPC(int index);
	void setNPC(TalkingNPC* np);
	void setNPC(TalkingNPC* np, int index);
	void setNPCs(TalkingNPC* np1, TalkingNPC* np2, TalkingNPC* np3);

	
protected:
	std::string locationName;
	std::string description; // A text description of this location when seen from an adjacent node.

	MapNode* north;
	MapNode* west;
	MapNode* east;
	MapNode* south;

	Enemy* enemy1{ nullptr };
	Enemy* enemy2{ nullptr };
	Enemy* enemy3{ nullptr };
	Shop* shop1{ nullptr };
	Shop* shop2{ nullptr };
	Shop* shop3{ nullptr };
	TalkingNPC* npc1{ nullptr };
	TalkingNPC* npc2{ nullptr };
	TalkingNPC* npc3{ nullptr };
};

class Map {
public:
	Map(); // Creates the MapNode details and links them by cardinal pointers (N-W-E-S).

	MapNode* getIndex();
	void setIndex(MapNode* node);
	MapNode* getHead(); 
	void setHead(MapNode* node);

private:
	MapNode* index; // Tracks where the player is located.
	MapNode* head; // Tracks where the map initially starts.
};

#endif
