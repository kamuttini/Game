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
    virtual void findTile();
    bool isDestroyed() const;
    void setIsDestroyed(bool isDestroyed);
    float getSpeed() const;
    void setSpeed(float s);

protected:
    float sx,dx,top,bottom;
    int tile;
    float speed;
    bool destroyed;
    TileMap colMap;
};


#endif //GAME_DYNAMICCOMPONENT_H
