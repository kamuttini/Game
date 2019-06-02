//
// Created by camut on 24/05/19.
//

#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H


#include "GameCharacter.h"
#include "Inventory.h"
#include "Sidebar.h"


class Player: public GameCharacter {
public:
    Player ();
    void move();
    void getInput();
    void update(Weapon* weapon);
    void fight();
    void dead();
    void updateSituation(CollisionObserver* enemy);
    void addObserver (Sidebar* o);
    Inventory inventory;

private:
    sf::Vector2f movement;
    Sidebar* stats;
};


#endif //GAME_PLAYER_H
