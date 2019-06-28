//
// Created by camut on 03/06/19.
//

#include "Text.h"

Text::Text(const std::string text1,int size,sf::Color color): display(false) {
    font.loadFromFile("assets/fonts/sf-atarian-system/Atarian/SFAtarianSystem.ttf");
    text.setFont(font);
    text.setString(text1);
    text.setFillColor(color);
    text.setCharacterSize(size);
    displayTime=sf::seconds(1);
}

void Text::setPosition(float x, float y) {
    text.setPosition(x,y);
}

sf::Vector2f Text::getPosition() {
    return text.getPosition();
}

void Text::draw(sf::RenderWindow &window) {
    window.draw(text);
}

void Text::startDisplaying() {
    display=true;
    displayClock.restart();
}


void Text::stopDisplaying(){
    if(display && displayClock.getElapsedTime()> displayTime)
        display=false;
}
bool Text::isDisplay() const {
    return display;
}

