//
// Created by camut on 07/06/19.
//

#ifndef GAME_STRATEGY_H
#define GAME_STRATEGY_H

#include "Player.h"


class Strategy {
public:
    Strategy(){};
    ~Strategy(){};
    virtual void move(sf::RectangleShape& rect, Player& player)=0;
};


#endif //GAME_STRATEGY_H
