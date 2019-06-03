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
    Player (Sidebar* sidebar, sf::Color=sf::Color::Red);
    void move();
    void getInput();
    void update(Weapon* weapon);
    void fight();
    bool dead();
    void updateSituation(CollisionObserver* enemy);
    void updateState()override;
    void addObserver (Sidebar* o);
    Inventory inventory;
    Sidebar* stats;


private:
    sf::Vector2f movement;
};


#endif //GAME_PLAYER_H
