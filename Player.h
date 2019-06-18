//
// Created by camut on 24/05/19.
//

#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H


#include "GameCharacter.h"
#include "Inventory.h"
#include "HUD.h"


class Player: public GameCharacter {
public:
    explicit Player (HUD& sidebar);
    ~Player(){};
    void move() override ;
    void getInput();
    void update(Weapon* weapon) override;
    void fight() override;
    void updateTarget(CollisionObserver *enemy);
    void updateState()override;
    void getPosition();

    Inventory inventory;
    HUD& stats;

private:
    sf::Vector2f movement;
};


#endif //GAME_PLAYER_H
