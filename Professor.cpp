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
            break;
        case prof2:
            position=PROF2_POSITION;
            filename="prof2.png";
            mfilename="assets/sprites/message2.png";
            break;
        case prof3:
            position=PROF3_POSITION;
            filename="prof3.png";
            mfilename="assets/sprites/message3.png";
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
        disaplyClock.restart();
    }
}

void Professor::stopTalking() {
    if(talking && disaplyClock.getElapsedTime()>displayTime)
        talking=false;
}

bool Professor::isTalking() {
    return talking;
}


