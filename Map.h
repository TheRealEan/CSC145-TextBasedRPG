#ifndef MAP_H
#define MAP_H
#include <string>
class Enemy;
class Map;
class Menu;
class Shop;
class StartMenu;
class Player;
class TalkingNPC;

class MapNode {
public:
	MapNode(const std::string& nombre, const std::string& des, Map* own);
	// Primary constructor. Use setters for other variables.
	MapNode(const std::string& nombre, const std::string& des, Map* own, MapNode* n, MapNode* w, MapNode* e, MapNode* s);

	void execLocation(Player* p); // Lists options for the player to do at a node's location.

	std::string const getLocationName();
	void setLocationName(std::string nombre);
	std::string const getDescription();
	void setDescription(std::string des);
	Map* const getMap();
	void setMap(Map* m);
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
	Map* owner;

	Menu* menu; // Used for menu functions in execLocation(). 

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
	Map(Player* p, StartMenu* sm); // Creates the MapNode details and links them by cardinal pointers (N-W-E-S).

	Player* getPlayer();
	void setPlayer(Player* p);
	StartMenu* getStartMenu();
	void setStartMenu(StartMenu* sm);
	MapNode* getIndex();
	void setIndex(MapNode* node);
	MapNode* getHead(); 
	void setHead(MapNode* node);

protected:
	Player* player;
	StartMenu* startMenu;
	MapNode* index; // Tracks where the player is located.
	MapNode* head; // Tracks where the map initially starts.
};

#endif
