#include "Roll.h"
#include "../Enemy.h"
#include "../Inventory.h"
#include "../Shop.h"
#include "../TalkingNPC.h"

// Generate a random enemy for battle encounters.

Enemy* generateEnemy();

// Generate shops with defined items.

static const std::vector<std::string> potentialStoreItems{
	"Longsword", "Chainmail", "Small Potion of Healing", "Moth-Eaten Shirt"
};
static const std::vector<std::string> store_one{
	"Longsword", "Enderpearl", "Shortbow"
};
static const std::vector<std::string> store_two{
	"Chainmail", "Leather Armor", "Flint and Steel"
};
static const std::vector<std::string> store_three{
	"Small Potion of Healing", "Medium Potion of Healing", "Large Potion of Healing"
};

Shop* generateShop();

// Generate a random talking NPC for the player to chat with.

//TalkingNPC* generateTalkingNPC() {
//	int randomTalkingNPC = roll(1, 3);
//	switch (randomTalkingNPC) {
//	case 1:
//		return new Somebody;
//	case 2:
//		return new Somebody;
//	case 3:
//		return new Somebody;
//	}
//}