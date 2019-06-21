//
// Created by camut on 19/06/19.
//

#include "Professor.h"
#include "Def.h"

Professor::Professor(type id): ID(id), talking(false) {

    rect.setSize(sf::Vector2f(32, 64));
    sf::Vector2f position;
    std::string filename, mfilename;
    switch (ID)
    {
        case prof1:
            position=PROF1_POSITION;
            filename="prof1.png";
            mfilename="assets/sprites/message1.png";
            token= new Token(Token::type::calculator);
            break;
        case prof2:
            position=PROF2_POSITION;
            filename="prof2.png";
            mfilename="assets/sprites/message2.png";
            token= new Token(Token::type::license);
            break;
        case prof3:
            position=PROF3_POSITION;
            filename="prof3.png";
            mfilename="assets/sprites/message3.png";
            token= new Token(Token::type::computer);
            break;

    }

    rect.setPosition(position);
    sprite = new Sprite(filename,*this,0,0,0,0,0,32,64);
    sprite->setScale(sf::Vector2f(2,2));
    mTexture.loadFromFile(mfilename);
    message.setTexture(mTexture);
    message.setPosition(rect.getPosition().x,rect.getPosition().y-90);
    displayTime=sf::seconds(2);
}

void Professor::talk() {
    if(!talking) {
        talking = true;
        displayClock.restart();
    }
}

void Professor::stopTalking() {
    if(talking && displayClock.getElapsedTime()>displayTime)
        talking=false;
}

bool Professor::isTalking() {
    return talking;
}

bool Professor::checkToken(Player &player) {

       return false;
}

Token *Professor::getToken() const {
    return token;
}


