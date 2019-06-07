//
// Created by camut on 07/06/19.
//

#include <SFML/Graphics.hpp>

#include "Follow.h"
#include <cmath>


void Follow::move(Enemy &enemy, Player &player) {
    float distance;
    distance= sqrt(pow(enemy.getRect().getPosition().x- player.getRect().getPosition().x, 2) + pow(enemy.getRect().getPosition().y- player.getRect().getPosition().y, 2));
    sf::Vector2f playerDir;
    playerDir.x=(player.getRect().getPosition().x-enemy.getRect().getPosition().x)/distance;
    playerDir.y=(player.getRect().getPosition().y-enemy.getRect().getPosition().y)/ distance;
    sf::RectangleShape& rect = enemy.getRect();
    rect.move(playerDir);
}