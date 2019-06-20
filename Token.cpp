//
// Created by Filippo Paolini on 2019-06-19.
//

#include "Token.h"
#include "Def.h"
Token::Token(std::string filename) {
    rect.setSize(sf::Vector2f(32,32));
    randomPosition(HALL_DIMENSION,HALL_ORIGIN);

    sprite = new Sprite(filename,*this);
}