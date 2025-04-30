#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <vector>
class Character;

enum class Slot { LEFT_HAND, RIGHT_HAND, HEAD, TORSO, LEGS, FEET };

extern std::vector<std::string> listOfWeapons;
extern std::vector<std::string> listOfArmor;
extern std::vector<std::string> listOfPotions;
extern std::vector<std::string> listOfConsumables;
extern std::vector<std::string> listOfEquippables;
extern std::vector<std::string> listOfAllItems;

static bool initItems();
extern bool itemInitialized;

class Item {
public:
    Item();
    Item(std::string nombre);
    Item(std::string nombre, int amt);
    Item(std::string nombre, int amt, int goldCost);
    virtual ~Item() = default;

    static Item* create(std::string itemName);
    static Item* create(std::string itemName, int quantity);
    static Item* create(std::string itemName, int quantity, int goldCost, bool equipped);

    std::string const getName();
    void setName(std::string nombre);
    int const getQuantity();
    void setQuantity(int amt);
    int const getCost();
    void setCost(int amt);
    bool getEquipped();
    void setEquipped(bool e);

protected:
    std::string name;
    int quantity;
    int cost;
    bool equipped = false;
};

class Equippable : public Item {
public:
    Equippable();
    Equippable(std::string nombre);
    Equippable(std::string nombre, int amt);
    Equippable(std::string nombre, int amt, int goldCost);
    virtual ~Equippable() = default;

    virtual Slot getSlot() const = 0;
    virtual void equip(Character* target) = 0;
    virtual void unequip(Character* target) = 0;

protected:
    int originalStr{ 0 }; // Tracks the player's original strength.
    int originalDex{ 0 }; // Tracks the player's original dexterity.
    int originalArm{ 0 }; // Tracks the player's original armor.
};

class Consumable : public Item {
public:
    Consumable();
    Consumable(std::string nombre);
    Consumable(std::string nombre, int amt);
    Consumable(std::string nombre, int amt, int goldCost);
    virtual ~Consumable() = default;

    virtual void consume(Character* target) = 0;
};

/**********************************************
******************* Weapons *******************
***********************************************/

class BigStick : public Equippable {
public:
    BigStick();
    BigStick(int amt);

    Slot getSlot() const override;
    void equip(Character* target) override;
    void unequip(Character* target) override;
};

class Longbow : public Equippable {
public:
    Longbow();
    Longbow(int amt);

    Slot getSlot() const override;
    void equip(Character* target) override;
    void unequip(Character* target) override;
};

class Longsword : public Equippable {
public:
    Longsword();
    Longsword(int amt);

    Slot getSlot() const override;
    void equip(Character* target) override;
    void unequip(Character* target) override;

private:
    void dealDamage(Character* target);
};

class Maul : public Equippable {
public:
    Maul();
    Maul(int amt);

    Slot getSlot() const override;
    void equip(Character* target) override;
    void unequip(Character* target) override;
};

class Scimitar : public Equippable {
public:
    Scimitar();
    Scimitar(int amt);

    Slot getSlot() const override;
    void equip(Character* target) override;
    void unequip(Character* target) override;
};

class Shortbow : public Equippable {
public:
    Shortbow();
    Shortbow(int amt);

    Slot getSlot() const override;
    void equip(Character* target) override;
    void unequip(Character* target) override;
};

class Shortsword : public Equippable {
public:
    Shortsword();
    Shortsword(int amt);

    Slot getSlot() const override;
    void equip(Character* target) override;
    void unequip(Character* target) override;
};

class FlintNSteel : public Equippable {
public:
    FlintNSteel();
    FlintNSteel(int amt);

    Slot getSlot() const override;
    void equip(Character* target) override;
    void unequip(Character* target) override;
};

class Sling : public Equippable {
public:
    Sling();
    Sling(int amt);

    Slot getSlot() const override;
    void equip(Character* target) override;
    void unequip(Character* target) override;
};

class Enderpearl : public Equippable {
public:
    Enderpearl();
    Enderpearl(int amt);

    Slot getSlot() const override;
    void equip(Character* target) override;
    void unequip(Character* target) override;
};

/**********************************************
******************* Armor *********************
***********************************************/

class Chainmail : public Equippable {
public:
    Chainmail();
    Chainmail(int amt);

    Slot getSlot() const override;
    void equip(Character* target) override;
    void unequip(Character* target) override;
};

class LeatherArmor : public Equippable {
public:
    LeatherArmor();
    LeatherArmor(int amt);

    Slot getSlot() const override;
    void equip(Character* target) override;
    void unequip(Character* target) override;
};

class DiamondBoots : public Equippable {
public:
    DiamondBoots();
    DiamondBoots(int amt);

    Slot getSlot() const override;
    void equip(Character* target) override;
    void unequip(Character* target) override;
};

/**********************************************
******************* Potions *******************
***********************************************/

class SmallPotionOfHealing : public Consumable {
public:
    SmallPotionOfHealing();
    SmallPotionOfHealing(int amt);

    void consume(Character* target) override;
};

class MediumPotionOfHealing : public Consumable {
public:
    MediumPotionOfHealing();
    MediumPotionOfHealing(int amt);

    void consume(Character* target) override;
};

class LargePotionOfHealing : public Consumable {
public:
    LargePotionOfHealing();
    LargePotionOfHealing(int amt);

    void consume(Character* target) override;
};

#endif // ITEM_H
