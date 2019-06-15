//
// Created by camut on 07/06/19.
//

#ifndef GAME_RANDOMMOVE_H
#define GAME_RANDOMMOVE_H


#include "Strategy.h"
#include "BaseClock.h"

class RandomMove: public Strategy {
public:

    RandomMove();
    RandomMove(std::unique_ptr<BaseClock> &changeDirectionClock);

    ~RandomMove()=default;
    void move(Enemy &enemy, Player &player) override;

private:
    std::unique_ptr<BaseClock> changeDirectionClock;
    sf::Time changeDirectionTime;
};


#endif //GAME_RANDOMMOVE_H
