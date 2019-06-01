//
// Created by camut on 24/05/19.
//

#ifndef GAME_STATICCOMPONENT_H
#define GAME_STATICCOMPONENT_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class StaticComponent {

public:
    StaticComponent();

    void draw (sf::RenderWindow& window);
    void randomPosition();

    int getPosX() const;
    void setPosX(int posX);
    int getPosY() const;
    void setPosY(int posY);
    const sf::RectangleShape &getRect() const;
    void setRect(const sf::RectangleShape &rect);

protected:
    int posX, posY;
    sf::RectangleShape rect;
};


#endif //GAME_STATICCOMPONENT_H
