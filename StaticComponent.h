//
// Created by camut on 24/05/19.
//

#ifndef GAME_STATICCOMPONENT_H
#define GAME_STATICCOMPONENT_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class StaticComponent {

public:
    StaticComponent(sf::Color color);
    ~StaticComponent(){};
    void draw (sf::RenderWindow& window);
    void randomPosition();
    sf::RectangleShape &getRect();

protected:
    int posX, posY;
    sf::RectangleShape rect;
    sf::Color color;
};


#endif //GAME_STATICCOMPONENT_H
