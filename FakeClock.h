//
// Created by Filippo Paolini on 2019-06-15.
//

#ifndef GAME_FAKECLOCK_H
#define GAME_FAKECLOCK_H

#include <SFML/System/Clock.hpp>
#include "BaseClock.h"

class FakeClock : public BaseClock {

public:
    sf::Time restart() override;
    sf::Time getElapsedTime() override;
    void setCurrent(sf::Time);

private:
    sf::Time current;
};


#endif //GAME_FAKECLOCK_H
