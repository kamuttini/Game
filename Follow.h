//
// Created by camut on 07/06/19.
//

#ifndef GAME_FOLLOW_H
#define GAME_FOLLOW_H


#include "Strategy.h"
#include "Player.h"

class Follow: public Strategy {
public:
    Follow(){};
    ~Follow(){};
    void move(sf::RectangleShape &rect, Player& player ) override ;

private:
};


#endif //GAME_FOLLOW_H
