//
// Created by Filippo Paolini on 2019-06-19.
//

#include "Token.h"
#include "Def.h"

Token::Token(type id) : ID(id), active(false), caught(false) {
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

void Token::setActive(bool active1, Player* player1) {
    active = active1;
    player=player1;
}

void Token::update() {
    if(!caught)
        if(player->getRect().getGlobalBounds().intersects(rect.getGlobalBounds())) {
            attachToPlayer();
            caught=true;
            sprite->setScale(sf::Vector2f(0.7,0.7));
        }
    if(caught)
        attachToPlayer();
}

void Token::attachToPlayer() {

    rect.setPosition(player->getPosition().x+10,player->getPosition().y+40);
    sprite->update();
}

bool Token::isCaught() const {
    return caught;
}



