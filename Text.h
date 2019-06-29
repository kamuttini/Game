//
// Created by camut on 03/06/19.
//

#ifndef GAME_TEXT_H
#define GAME_TEXT_H

#include <string>
#include <SFML/Graphics.hpp>

class Text {
public:
    explicit Text(std::string text1, int size=50, sf::Color color=sf::Color::White);
    ~Text()= default;
    void setPosition(float x, float y);
    sf::Vector2f getPosition();
    void draw(sf::RenderWindow& window);
    void startDisplaying();
    void stopDisplaying();
    bool isDisplay() const;

    sf::Text text;

private:
    bool display;
    sf::Font font;
    sf::Clock displayClock;
    sf::Time displayTime;
};


#endif //GAME_TEXT_H
