//
// Created by camut on 28/06/19.
//

#include "Badge.h"
#include "Def.h"

Badge::Badge(type ID): active(false) {

    rect.setSize(sf::Vector2f(50,50));
    switch(ID)
    {
        case killer:
            rect.setFillColor(sf::Color::Blue);
            text=new Text("Killer achieved");
            rect.setPosition(150,30);
            break;

        case pacifista:
            rect.setFillColor(sf::Color::Green);
            text=new Text("Secchione achieved");
            rect.setPosition(200,30);
            break;

        case secchione:
            rect.setFillColor(sf::Color::Red);
            text=new Text("Pacifista achieved");
            rect.setPosition(250,30);
            break;
    }
    text->setPosition(BADGE_TEXT_POSITION);

}

void Badge::draw(sf::RenderWindow &window) {
    if(active)
    {
        window.draw(rect);
        if(text->isDisplay()) {
            text->draw(window);
            text->stopDisplaying();
        }
    }
}

void Badge::setActive(bool val) {
    active=val;
    text->startDisplaying();
}

bool Badge::isActive() const {
    return active;
}