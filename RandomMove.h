//
// Created by camut on 07/06/19.
//

#ifndef GAME_RANDOMMOVE_H
#define GAME_RANDOMMOVE_H


#include "Strategy.h"

class RandomMove: public Strategy {
public:
    RandomMove(){};
    ~RandomMove(){};
    void move(sf::RectangleShape &rect, Player& player) override;
};


#endif //GAME_RANDOMMOVE_H
