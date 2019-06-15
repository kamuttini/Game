//
// Created by camut on 07/06/19.
//

#include <SFML/Graphics/RectangleShape.hpp>
#include "RandomMove.h"
#include "Enemy.h"
#include "SimpleClock.h"

//RandomMove::RandomMove() {
//    changeDirectionTime = sf::seconds(3);
//}


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

    if (enemy.getRect().getPosition().x < 1350 && enemy.getRect().getPosition().x > 0 &&
        enemy.getRect().getPosition().y < 950 && enemy.getRect().getPosition().y > 0) {
        enemy.getRect().move(movement);
    } else {

        enemy.getRect().move(-movement);
        srand(clock());
        enemy.setDirection(DynamicComponent::orientation(rand() % 4));
        changeDirectionClock->restart();
    }

    if (changeDirectionClock->getElapsedTime() > changeDirectionTime) {
        srand(clock());
        enemy.setDirection(DynamicComponent::orientation(rand() % 4));
        changeDirectionClock->restart();
    }
    enemy.getSprite()->animate();

}

RandomMove::RandomMove() : changeDirectionClock(std::unique_ptr<BaseClock>(new SimpleClock)) {}

RandomMove::RandomMove(std::unique_ptr<BaseClock> &clock) : changeDirectionClock(
        std::move(clock)) {}
