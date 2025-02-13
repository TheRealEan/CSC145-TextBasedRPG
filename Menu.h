// Filename: "Menu.h"
#include <iostream>
#include "Player.h"
#ifndef MENU_H
#define MENU_H

void checkForItems(Player& player);
void startBattle(Player& player);

class Menu {
public:
    // Clear the screen.
    void clear();
};

class MainMenu : public Menu {
public:
    MainMenu(Player& player);
    // Return to the overworld.
    void returnToOverworld();
    // Enter into a battle sequence.
    void enterBattle(Player& player);
    // Manage inventory options.
    void manageInventory(Player& player);
    // Enter the shop.
    void enterShop();
    // Chat with a Character.
    void chat();
    // Quit the game.
    int quitGame();
};

class BattleMenu : public Menu {
public:
    BattleMenu();
    void attack();
    void magic();
    void actions();
    void inventory();
    void chat();
    void flee();
};


#endif

