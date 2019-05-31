//
// Created by camut on 24/05/19.
//

#ifndef GAME_DYNAMICCOMPONENT_H
#define GAME_DYNAMICCOMPONENT_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "StaticComponent.h"



class DynamicComponent: public StaticComponent {

public:
    enum orientation { down, up,left,right};

    DynamicComponent(int s, orientation dir=down);
    orientation getDirection() const;
    void setDirection(orientation direction);
    bool isDestroyed1() const;
    void setIsDestroyed(bool isDestroyed);
    int getSpeed() const;
    void setSpeed(int speed);

protected:
    float speed;
    orientation direction;
    bool isDestroyed;

};


#endif //GAME_DYNAMICCOMPONENT_H
