//
// Created by Filippo Paolini on 2019-06-19.
//

#include "Token.h"
#include "Def.h"

Token::Token(type id) : ID(id), active(false) {
    rect.setSize(sf::Vector2f(32, 32));
    std::string filename;

    switch (ID) {
        case calculator:
            randomPosition(HALL_DIMENSION,HALL_ORIGIN);
            filename = "token1.png";
            break;
        case license:
            randomPosition(CANTEEN_DIMENSION, CANTEEN_ORIGIN);
            filename = "token2.png";
            break;
        case computer:
            randomPosition(BAR_DIMENSION,BAR_ORIGIN);
            filename = "token3.png";
            break;
    }

    sprite = new Sprite(filename, *this);
}

bool Token::isActive() const {
    return active;
}

void Token::setActive(bool active) {
    Token::active = active;
}
