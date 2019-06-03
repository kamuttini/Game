//
// Created by camut on 03/06/19.
//

#ifndef GAME_TEXT_H
#define GAME_TEXT_H

#include <string>
#include <SFML/Graphics.hpp>

class Text {
public:
    Text(std::string text1, int size=50, sf::Color color=sf::Color::White);
    void setPosition(float x, float y);
    void draw(sf::RenderWindow& window);
    sf::Text text;

private:
    sf::Font font;
};


#endif //GAME_TEXT_H
