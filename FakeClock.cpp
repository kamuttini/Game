//
// Created by Filippo Paolini on 2019-06-15.
//

#include "FakeClock.h"

sf::Time FakeClock::restart() {
    current = sf::Time::Zero;
    return current;
}

sf::Time FakeClock::getElapsedTime() {
    return current;
}

void FakeClock::setCurrent(sf::Time) {
    this->current = current;
}
