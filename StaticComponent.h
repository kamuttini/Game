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
    virtual ~StaticComponent()= default;
    void draw(sf::RenderWindow &window);

    orientation getDirection() const;
    void setOrientation(orientation direction);
    sf::RectangleShape &getRect();
    sf::Vector2f getPosition();
    void setPosition(float x, float y);
    const std::unique_ptr<TileMap> &getColMap() const;

protected:
    int findTile();
    void randomPosition(sf::Vector2f range, sf::Vector2f origin);

    sf::RectangleShape rect;
    orientation direction;
    std::unique_ptr<Sprite> sprite;
    std::unique_ptr<TileMap> colMap;

    bool checkPosition(int tileToCheck);
    int posX, posY;
    float sx,dx,top,bottom;

};


#endif //GAME_STATICCOMPONENT_H
