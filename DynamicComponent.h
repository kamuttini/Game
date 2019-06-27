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
    bool isDestroyed() const;
    void setIsDestroyed(bool isDestroyed);
    void setSpeed(float s);
    void changeColMap();

protected:
    bool checkBorders(orientation direction);

    float speed;
    bool destroyed;
    int colIter;
};


#endif //GAME_DYNAMICCOMPONENT_H
