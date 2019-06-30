//
// Created by camut on 28/06/19.
//

#include "Badge.h"
#include "Def.h"

Badge::Badge(type ID): active(false) {

    switch(ID)
    {
        case killer:
            badgeText=new Text("Killer achieved");
            texture.loadFromFile("assets/sprites/killer.png");
            badgeSprite.setTexture(texture);
            badgeSprite.setPosition(140,30);
            break;

        case pacifista:
            badgeText=new Text("Pacifista achieved");
            texture.loadFromFile("assets/sprites/pace.png");
            badgeSprite.setTexture(texture);
            badgeSprite.setPosition(280,30);
            break;

        case secchione:
            badgeText=new Text("Secchione achieved");
            texture.loadFromFile("assets/sprites/secchione.png");
            badgeSprite.setTexture(texture);
            badgeSprite.setPosition(420,30);
            break;
    }
    badgeText->setPosition(BADGE_TEXT_POSITION);
    badgeSprite.setScale(0.6,0.6);
}

void Badge::draw(sf::RenderWindow &window) {
    if(active)
    {
        window.draw(badgeSprite);
        if(badgeText->isDisplay()) {
            badgeText->draw(window);
            badgeText->stopDisplaying();
        }
    }
}

void Badge::setActive(bool val) {
    active=val;
    badgeText->startDisplaying();
}

bool Badge::isActive() const {
    return active;
}