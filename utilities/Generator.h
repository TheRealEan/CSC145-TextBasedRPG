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
	"Sling", "Scimitar", "Shortbow", "Really Big Stick", "Maul", "Enderpearl", "Flint and Steel"
};
static const std::vector<std::string> store_two{
	"Chainmail", "Leather Armor", "Diamond Boots", "Moth-Eaten Shirt", "Small Potion of Healing"
};
static const std::vector<std::string> store_three{
	"Small Potion of Healing", "Medium Potion of Healing", "Large Potion of Healing", "Longsword", "Longbow"
};

Shop* generateShop();
