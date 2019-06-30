//
// Created by camut on 30/06/19.
//

#ifndef GAME_MAP_H
#define GAME_MAP_H


#include "PositionObserver.h"
#include "Professor.h"
struct entity{
    sf::CircleShape circle;
    bool active;
};
class Map: public PositionObserver {
public:
    Map();
    ~Map(){};
    void update(sf::RectangleShape& rect, int i, bool active)override;
    void draw(sf::RenderWindow& window);
    entity point[3];

private:
    sf::Sprite sprite;
    sf::Texture texture;
};


#endif //GAME_MAP_H
