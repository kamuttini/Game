//
// Created by camut on 07/06/19.
//

#ifndef GAME_FOLLOW_H
#define GAME_FOLLOW_H


#include "Strategy.h"
#include "Player.h"
#include "Enemy.h"

class Follow: public Strategy {
public:
    Follow()= default;;
    ~Follow()= default;;
    void move(Enemy &enemy, Player &player) override ;

};


#endif //GAME_FOLLOW_H
