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
    explicit DynamicComponent(float s);
    ~DynamicComponent(){};
    bool isDestroyed1() const;
    void setIsDestroyed(bool isDestroyed);
    float getSpeed() const;

protected:
    float speed;
    bool isDestroyed;
};


#endif //GAME_DYNAMICCOMPONENT_H
