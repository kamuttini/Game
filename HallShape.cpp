//
// Created by camut on 21/06/19.
//

#include "HallShape.h"
#include "Def.h"

HallShape::HallShape() {
    rect[0].setPosition(HALL_ORIGIN);
    rect[0].setSize(HALL_DIMENSION);
    rect[1].setPosition(sf::Vector2f(1360,1900));
    rect[1].setSize(sf::Vector2f(360,100));
    rect[2].setPosition(sf::Vector2f(2350,1730));
    rect[2].setSize(sf::Vector2f(700,250));
    rect[3].setPosition(sf::Vector2f(2460,700));
    rect[3].setSize(sf::Vector2f(290,1000));
    rect[4].setPosition(1700,520);
    rect[4].setSize(sf::Vector2f(1700,180));
}

void HallShape::draw(sf::RenderWindow &window) {
    for(int i=0;i<5; i++)
    {
        window.draw(rect[i]);
    }
}