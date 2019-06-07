//
// Created by camut on 07/06/19.
//

#include <SFML/Graphics.hpp>

#include "Follow.h"
#include <cmath>


void Follow::move(sf::RectangleShape &rect, Player& player) {
   float distance;
    distance= sqrt(pow(rect.getPosition().x- player.getRect().getPosition().x, 2) + pow(rect.getPosition().y- player.getRect().getPosition().y, 2));
    sf::Vector2f playerDir;
    playerDir.x=(player.getRect().getPosition().x-rect.getPosition().x)/distance;
    playerDir.y=(player.getRect().getPosition().y-rect.getPosition().y)/ distance;
    rect.move(playerDir);

}