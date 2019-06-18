//
// Created by camut on 24/05/19.
//
#include <typeinfo>
#include "GameCharacter.h"
#include "Factory.h"


GameCharacter::GameCharacter(int s, int h) : DynamicComponent(s),
                                             hp(h),
                                             isFighting(false)
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


