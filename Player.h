//
// Created by camut on 24/05/19.
//

#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H


#include "GameCharacter.h"
#include "Inventory.h"

class Player: public GameCharacter {
public:
    Player ();
    void move();
    void getInput();
    void update(Weapon* weapon);
    void fight();
    void dead();
    void updateSituation(CollisionObserver* enemy);
    
    Inventory inventory;

private:
    sf::Vector2f movement;
};


#endif //GAME_PLAYER_H
