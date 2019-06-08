//
// Created by camut on 24/05/19.
//
#include <typeinfo>
#include "GameCharacter.h"
#include "Factory.h"
sf::Time woundedTime=sf::seconds(0.3f);

GameCharacter::GameCharacter(int s, int h): DynamicComponent(s),
                                            hp(h),
                                            isFighting(false),
                                            wounded(false)
                                            {
    walkingDelay=sf::seconds(.1f);
                                            }


void GameCharacter::updateState() {
    fight();
    if(wounded){
        rect.setFillColor(sf::Color(192,192,192));
        wounded= false;
    }

    else
        if (woundedClock.getElapsedTime()>woundedTime)
        rect.setFillColor(sf::Color::Transparent);
}


