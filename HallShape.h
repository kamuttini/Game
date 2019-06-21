//
// Created by camut on 21/06/19.
//

#ifndef GAME_HALLSHAPE_H
#define GAME_HALLSHAPE_H

#include "SFML/Graphics.hpp"

class HallShape {
public:
    HallShape();
    void draw(sf::RenderWindow& window) ;
    sf::RectangleShape rect[5];
};


#endif //GAME_HALLSHAPE_H
