//
// Created by camut on 07/06/19.
//

#include <SFML/Graphics.hpp>

#include "Follow.h"
#include <cmath>


void Follow::setDirection(Enemy &enemy, Player &player) {
    float distance;
    distance= sqrt(pow(enemy.getPosition().x- player.getRect().getOrigin().x, 2) + pow(enemy.getPosition().y- player.getPosition().y, 2));

    sf::Vector2f playerDir;
    playerDir.x=(player.getPosition().x-enemy.getPosition().x)/distance;
    playerDir.y=(player.getPosition().y-enemy.getPosition().y)/ distance;

    if(playerDir.x>0) {
     if(playerDir.x>playerDir.y)
         enemy.setOrientation(DynamicComponent::orientation::down);
     else
         enemy.setOrientation(DynamicComponent::orientation::left);
    }
    else {
        if(playerDir.x>playerDir.y)
            enemy.setOrientation(DynamicComponent::orientation::right);
        else
            enemy.setOrientation(DynamicComponent::orientation::up);
    }

    enemy.setSpeed(FOLLOW_SPEED);
}