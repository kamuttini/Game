//
// Created by Filippo Paolini on 2019-06-19.
//

#include "Token.h"

Token::Token(std::string filename, sf::Vector2f position) {
    rect.setSize(sf::Vector2f(32,32));
    rect.setPosition(position);
    sprite = new Sprite(filename,*this,0,0,0,0,0,32,32);
    sprite->setScale(sf::Vector2f(2,2));
}