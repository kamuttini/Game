//
// Created by camut on 07/06/19.
//

#include <SFML/Graphics/RectangleShape.hpp>
#include "RandomMove.h"
#include "Enemy.h"

RandomMove::RandomMove() {
   changeDirectionTime = sf::seconds(3);
}


void RandomMove::move(Enemy &enemy, Player &player) {

    sf::Vector2f movement;
    movement.x = 0.f;
    movement.y = 0.f;
    switch (enemy.getDirection()) {
        case DynamicComponent::up:
            movement.x -= enemy.getSpeed();
            break;

        case DynamicComponent::down:
            movement.x += enemy.getSpeed();
            break;

        case DynamicComponent::left:
            movement.y += enemy.getSpeed();
            break;
        case DynamicComponent::right:
            movement.y -= enemy.getSpeed();
            break;
    }


        enemy.getRect().move(movement);


    if (enemy.changeDirectionClock.getElapsedTime() > changeDirectionTime) {
        srand(clock());
        enemy.setDirection(DynamicComponent::orientation(rand() % 4));
        enemy.changeDirectionClock.restart();
    }
    enemy.getSprite()->animate();

}

