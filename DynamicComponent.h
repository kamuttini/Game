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

    explicit DynamicComponent(float s,sf::Color color1, orientation dir=down);
    bool isDestroyed1() const;
    void setIsDestroyed(bool isDestroyed);

protected:
    float speed;
    orientation direction;
    bool isDestroyed;

};


#endif //GAME_DYNAMICCOMPONENT_H
