//
// Created by Filippo Paolini on 2019-06-19.
//

#ifndef GAME_TOKEN_H
#define GAME_TOKEN_H

#include <SFML/Graphics.hpp>
#include "StaticComponent.h"

class Token: public StaticComponent {
public:
    Token(std::string filename, sf::Vector2f position);
    ~Token(){};
};


#endif //GAME_TOKEN_H
