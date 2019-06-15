//
// Created by Filippo Paolini on 2019-06-15.
//

#ifndef GAME_BASECLOCK_H
#define GAME_BASECLOCK_H


#include <SFML/System/Time.hpp>

class BaseClock {

public:
    virtual ~BaseClock() = default;
    virtual sf::Time restart() = 0;
    virtual sf::Time getElapsedTime() = 0;
};


#endif //GAME_BASECLOCK_H
