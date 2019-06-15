//
// Created by Filippo Paolini on 2019-06-15.
//

#ifndef GAME_SIMPLECLOCK_H
#define GAME_SIMPLECLOCK_H

#include "BaseClock.h"
#include <SFML/System/Clock.hpp>

class SimpleClock : public BaseClock {

public:
    sf::Time restart() override;

    sf::Time getElapsedTime() override;

private:
    sf::Clock clock;
};


#endif //GAME_SIMPLECLOCK_H
