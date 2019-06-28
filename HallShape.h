//
// Created by camut on 21/06/19.
//

#ifndef GAME_HALLSHAPE_H
#define GAME_HALLSHAPE_H

#include "SFML/Graphics.hpp"
#include "Def.h"

class HallShape {
public:
    HallShape();
    ~HallShape(){};
    void draw(sf::RenderWindow& window) ;
    sf::RectangleShape rect[nHALLRECT];
    int i;
};


#endif //GAME_HALLSHAPE_H
