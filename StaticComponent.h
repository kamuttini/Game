//
// Created by camut on 24/05/19.
//

#ifndef GAME_STATICCOMPONENT_H
#define GAME_STATICCOMPONENT_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Sprite.h"

class StaticComponent {
public:
    enum orientation {
        down, up, left, right
    };

    explicit StaticComponent(orientation dir = down);

    ~StaticComponent() = default;

    void draw(sf::RenderWindow &window);

    void randomPosition(sf::Vector2f range, sf::Vector2f origin);

    orientation getDirection() const;

    void setDirection(orientation direction);

    sf::RectangleShape &getRect();

    Sprite *getSprite() const;

    sf::Vector2f getPosition();


protected:
    int posX, posY;
    sf::RectangleShape rect;
    orientation direction;
    Sprite *sprite;
};


#endif //GAME_STATICCOMPONENT_H
