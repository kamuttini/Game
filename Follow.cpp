//
// Created by camut on 07/06/19.
//

#include <SFML/Graphics.hpp>

#include "Follow.h"
#include <cmath>


void Follow::setDirection(Enemy &enemy, Player &player) {
    float distance;
    distance= sqrt(pow(enemy.getRect().getPosition().x- player.getRect().getOrigin().x, 2) + pow(enemy.getRect().getPosition().y- player.getRect().getPosition().y, 2));

    sf::Vector2f playerDir;
    playerDir.x=(player.getRect().getPosition().x-enemy.getRect().getPosition().x)/distance;
    playerDir.y=(player.getRect().getPosition().y-enemy.getRect().getPosition().y)/ distance;

    if(playerDir.x>0) {
     if(playerDir.x>playerDir.y)
         enemy.setDirection(DynamicComponent::orientation::down);
     else
         enemy.setDirection(DynamicComponent::orientation::left);
    }
    else {
        if(playerDir.x>playerDir.y)
            enemy.setDirection(DynamicComponent::orientation::right);
        else
            enemy.setDirection(DynamicComponent::orientation::up);
    }

    enemy.setSpeed(8);
}