//
// Created by camut on 03/06/19.
//

#include "Text.h"

Text::Text(std::string text1,int size,sf::Color color) {
    font.loadFromFile("/home/camut/CLionProjects/game/assets/fonts/sf-atarian-system/Atarian/SFAtarianSystem.ttf");
    text.setFont(font);
    text.setString(text1);
    text.setFillColor(color);
    text.setCharacterSize(size);

}

void Text::setPosition(float x, float y) {
    text.setPosition(x,y);
}

void Text::draw(sf::RenderWindow &window) {
    window.draw(text);
}
