//
// Created by camut on 30/06/19.
//

#include "Map.h"
#include "SFML/Graphics.hpp"
Map::Map() {
    texture.loadFromFile("assets/sprites/hudMap.png");
    sprite.setTexture(texture);
    sprite.setPosition(810,750);
    point[0].circle.setRadius(3);
    point[0].circle.setFillColor(sf::Color::White);
    point[0].active=true;
    point[1].circle.setRadius(5);
    point[1].circle.setFillColor(sf::Color::Green);
    point[2].circle.setRadius(5);
    point[2].circle.setFillColor(sf::Color::Red);
    point[2].active=false;
}

void Map::update(sf::RectangleShape &rect, int i, bool active1) {
    point[i].circle.setPosition((rect.getPosition().x/(5.03*2.5))+810,(rect.getPosition().y/(5.03*2.5))+750);
    point[i].active=active1;
}

void Map::draw(sf::RenderWindow &window) {
    window.draw(sprite);
    for(auto & i : point)
    {
        if(i.active)
            window.draw(i.circle);
    }
}


