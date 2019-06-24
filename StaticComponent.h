//
// Created by camut on 24/05/19.
//

#ifndef GAME_STATICCOMPONENT_H
#define GAME_STATICCOMPONENT_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Sprite.h"
#include "TileMap.h"


class StaticComponent {
public:
    enum orientation { down, up,left,right, null};

    explicit StaticComponent(orientation dir = down);
    ~StaticComponent() = default;
    void draw(sf::RenderWindow &window);
    int findTile();
    bool checkPosition(int tileToCheck);
    void randomPosition(sf::Vector2f range, sf::Vector2f origin);

    orientation getDirection() const;
    void setOrientation(orientation direction);
    sf::RectangleShape &getRect();
    Sprite *getSprite() const;
    sf::Vector2f getPosition();
    void setPosition(float x, float y);

protected:
    int posX, posY;
    float sx,dx,top,bottom;
    sf::RectangleShape rect;
    orientation direction;
    Sprite *sprite;
    TileMap* colMap;

};


#endif //GAME_STATICCOMPONENT_H
