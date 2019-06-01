//
// Created by camut on 24/05/19.
//
#include <typeinfo>
#include "GameCharacter.h"
#include "Factory.h"


GameCharacter::GameCharacter(int s): DynamicComponent (s), isFighting(false){}



void GameCharacter::update(Weapon* weapon) {
    if (weapon->getRect().getGlobalBounds().intersects( rect.getGlobalBounds()))
    {
        const std::type_info& type_info = typeid(*weapon);
        if( type_info== typeid(PlayerWeapon))
        {
            weapon->setIsDestroyed(true);
        }
        else
        {
            isDestroyed=true;
            weapon->setIsDestroyed(true);
        }
    }
}


