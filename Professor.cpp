//
// Created by camut on 19/06/19.
//

#include "Professor.h"

Professor::Professor(std::string filename, sf::Vector2f position) {
    rect.setSize(sf::Vector2f(32,64));
    rect.setPosition(position);
    sprite = new Sprite(filename,*this,0,0,0,0,0,32,64);
    sprite->setScale(sf::Vector2f(2,2));
}
