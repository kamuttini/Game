//
// Created by camut on 07/06/19.
//

#ifndef GAME_RANDOMMOVE_H
#define GAME_RANDOMMOVE_H


#include "Strategy.h"

class RandomMove: public Strategy {
public:

    RandomMove();
    ~RandomMove()=default;
    void setDirection(Enemy &enemy, Player &player) override;

private:
    sf::Time changeDirectionTime;
};


#endif //GAME_RANDOMMOVE_H
