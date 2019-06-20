//
// Created by camut on 24/05/19.
//

#ifndef GAME_DYNAMICCOMPONENT_H
#define GAME_DYNAMICCOMPONENT_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "StaticComponent.h"
#include "TileMap.h"


class DynamicComponent: public StaticComponent {

public:
    explicit DynamicComponent(float s);
    ~DynamicComponent(){};
    bool checkBorders(orientation direction);
    int findTile();
    bool isDestroyed() const;
    void setIsDestroyed(bool isDestroyed);
    float getSpeed() const;
    void setSpeed(float s);
    void changeColMap();

protected:
    float sx,dx,top,bottom;
    float speed;
    bool destroyed;
    TileMap* colMap;
    int colIter;
};


#endif //GAME_DYNAMICCOMPONENT_H
