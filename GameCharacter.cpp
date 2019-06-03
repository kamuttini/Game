//
// Created by camut on 24/05/19.
//
#include <typeinfo>
#include "GameCharacter.h"
#include "Factory.h"
sf::Time woundedTime=sf::seconds(0.3f);

GameCharacter::GameCharacter(sf::Color color1, int s, int h):   DynamicComponent (s),
                                                                hp(h),
                                                                isFighting(false),
                                                                wounded(false),
                                                                color(color1){
    rect.setFillColor(color);
}



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


