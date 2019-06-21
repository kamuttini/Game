//
// Created by Filippo Paolini on 2019-06-19.
//

#include "Token.h"
#include "Def.h"

Token::Token(type id) : ID(id) {
    rect.setSize(sf::Vector2f(32, 32));
    std::string filename;




    switch (ID) {
        case token1:
            randomPosition(HALL_DIMENSION,HALL_ORIGIN);
            filename = "token1.png";
            break;
        case token2:
            randomPosition(CLASSROOM1_DIMENSION,CLASSROOM1_ORIGIN);
            //position = TOKEN2_POSITION;
            filename = "token2.png";
            break;
        case token3:
            randomPosition(CLASSROOM2_DIMENSION,CLASSROOM2_ORIGIN);

            //position = TOKEN3_POSITION;
            filename = "token3.png";
            break;

    }

    sprite = new Sprite(filename, *this);
    sprite->setScale(sf::Vector2f(2, 2));

}