//
// Created by camut on 19/06/19.
//

#include "Professor.h"
#include "Def.h"

Professor::Professor(type id) : ID(id) {

    rect.setSize(sf::Vector2f(32, 64));
    sf::Vector2f position;
    std::string filename;

    switch (ID) {
        case prof1:
            position = PROF1_POSITION;
            filename = "prof1.png";
            break;
        case prof2:
            position = PROF2_POSITION;
            filename = "prof2.png";
            break;
        case prof3:
            position = PROF3_POSITION;
            filename = "prof3.png";
            break;

    }

    rect.setPosition(position);
    sprite = new Sprite(filename, *this, 0, 0, 0, 0, 0, 32, 64);
    sprite->setScale(sf::Vector2f(2, 2));
}
