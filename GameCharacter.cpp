//
// Created by camut on 24/05/19.
//

#include "GameCharacter.h"

GameCharacter::GameCharacter(int s): DynamicComponent (s), isFighting(false){}

/*int GameCharacter::getHp() const {
    return hp;
}

void GameCharacter::setHp(int hp) {
    GameCharacter::hp = hp;
}

*/

void GameCharacter::fight() {
    if( isFighting) {
        weaponVec.push_back(std::unique_ptr<Weapon>(new Weapon(direction, rect.getPosition())));
        isFighting = false;
    }
}

void GameCharacter::update(sf::FloatRect weapon) {
    if (weapon.intersects( rect.getGlobalBounds()))
    {
        isDestroyed=true;

    }
}