//
// Created by camut on 24/05/19.
//

#include "GameCharacter.h"

GameCharacter::GameCharacter(int s): DynamicComponent (s), isFighting(false){}

void GameCharacter::fight() {

    if( isFighting) {
        weaponVec.push_back(std::unique_ptr<Weapon>(new Weapon(targetList, direction, rect.getPosition())));
        isFighting = false;
    }

    for (int i = 0; i < weaponVec.size(); i++)
    {
        weaponVec[i]->attack();
    }
}

void GameCharacter::update(sf::FloatRect weapon) {
    if (weapon.intersects( rect.getGlobalBounds()))
    {
        isDestroyed=true;
    }
}