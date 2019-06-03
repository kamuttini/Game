//
// Created by camut on 24/05/19.
//
#include <typeinfo>
#include "GameCharacter.h"
#include "Factory.h"
sf::Time woundedTime=sf::seconds(0.3f);

GameCharacter::GameCharacter(int s,sf::Color color1, int h):   DynamicComponent (s, color1),
                                                                hp(h),
                                                                isFighting(false),
                                                                wounded(false)
                                                                {}



int GameCharacter::getHp() const {
    return hp;
}

void GameCharacter::setHp(int hp) {
    GameCharacter::hp = hp;
}

void GameCharacter::updateState() {
    fight();
    if(wounded==true){
        rect.setFillColor(sf::Color(192,192,192));
        wounded= false;
    }

    else
        if (woundedClock.getElapsedTime()>woundedTime)
        rect.setFillColor(color);
}


