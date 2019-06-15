//
// Created by Filippo Paolini on 2019-06-15.
//

#include "SimpleClock.h"

sf::Time SimpleClock::restart() {
    return clock.restart();
}

sf::Time SimpleClock::getElapsedTime() {
    return clock.getElapsedTime();
}
