//
// Created by camut on 07/06/19.
//

#ifndef GAME_RANDOMMOVE_H
#define GAME_RANDOMMOVE_H


#include "Strategy.h"

class RandomMove: public Strategy {
public:

    RandomMove()= default;
    ~RandomMove()=default;
    void setDirection(Enemy &enemy, Player &player) override;

private:
    sf::Clock changeDirectionClock;
};


#endif //GAME_RANDOMMOVE_H
