//
// Created by camut on 24/05/19.
//
#include <typeinfo>
#include "GameCharacter.h"
#include "Factory.h"


GameCharacter::GameCharacter(int s, int h): DynamicComponent (s), hp(h), isFighting(false){}

void GameCharacter::update(Weapon* weapon) {
    if (weapon->getRect().getGlobalBounds().intersects( rect.getGlobalBounds()))       //controllo collisioni in base alla posizione di Weapon
    {
        const std::type_info& type_info = typeid(*weapon);                          //verifica il tipo di arma
        if( type_info== typeid(PlayerWeapon))
        {
            weapon->setIsDestroyed(true);
        }
        else
        {
            if(hp>1){
                hp--;
                weapon->setIsDestroyed(true);
            }
            else{
                isDestroyed=true;
                weapon->setIsDestroyed(true);
            }
        }
    }
}

int GameCharacter::getHp() const {
    return hp;
}

void GameCharacter::setHp(int hp) {
    GameCharacter::hp = hp;
}


