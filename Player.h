//
// Created by camut on 24/05/19.
//

#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H


#include "GameCharacter.h"
#include "Weapon.h"

class Player: public GameCharacter {
public:
    Player ();
    void move();
    void getInput();

private:
};


#endif //GAME_PLAYER_H
