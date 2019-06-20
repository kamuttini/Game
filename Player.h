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
    explicit Player (HUD& hud);
    ~Player(){};
    void move() override ;
    void getInput();
    void update(Weapon* weapon) override;
    void fight() override;
    void updateTarget(CollisionObserver *enemy);
    void updateState()override;
    HUD& stats;
    Inventory inventory;
};


#endif //GAME_PLAYER_H
