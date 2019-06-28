//
// Created by camut on 07/06/19.
//

#include <SFML/Graphics/RectangleShape.hpp>
#include "RandomMove.h"
#include "Enemy.h"

void RandomMove::setDirection(Enemy &enemy, Player &player) {
    if (changeDirectionClock.getElapsedTime() > CHANGE_DIRECTION_TIME) {
        srand(clock());
        enemy.setOrientation(DynamicComponent::orientation(rand() % 4));
        changeDirectionClock.restart();
    }
    enemy.setSpeed(RANDOMMOVE_SPEED);
}

