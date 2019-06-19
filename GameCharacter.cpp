//
// Created by camut on 24/05/19.
//
#include <typeinfo>
#include "GameCharacter.h"
#include "Factory.h"


GameCharacter::GameCharacter(int s, int h) : DynamicComponent(s),
                                             hp(h),
                                             isFighting(false),
                                             movement(1.f, 0.f)
                                             {
    walkingDelay = sf::seconds(.1f);
}

void GameCharacter::updateState() {

    fight();

}

void GameCharacter::setHp(int h) {
    hp = h;
}

int GameCharacter::getHp() {
    return hp;
}

void GameCharacter::setWalkingDelay(int val) {
    walkingDelay=sf::seconds(val);
}

void GameCharacter::move() {
    movement.x = 0.f;
    movement.y = 0.f;
    switch (direction) {
        case left:
            movement.x -= speed;
            break;

        case right:
            movement.x += speed;
            break;

        case down:
            movement.y += speed;
            break;
        case up:
            movement.y -= speed;
            break;
    }

    rect.move(movement);
    sprite->animate();
}


