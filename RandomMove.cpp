//
// Created by camut on 07/06/19.
//

#include <SFML/Graphics/RectangleShape.hpp>
#include "RandomMove.h"
#include "Enemy.h"

RandomMove::RandomMove() {
   changeDirectionTime = sf::seconds(3);
}


void RandomMove::setDirection(Enemy &enemy, Player &player) {
    if (enemy.changeDirectionClock.getElapsedTime() > changeDirectionTime) {
        srand(clock());
        enemy.setOrientation(DynamicComponent::orientation(rand() % 4));
        enemy.changeDirectionClock.restart();
    }
    enemy.setSpeed(RANDOMMOVE_SPEED);
}

