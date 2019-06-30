//
// Created by camut on 30/06/19.
//

#ifndef GAME_POSITIONOBSERVER_H
#define GAME_POSITIONOBSERVER_H

#include <SFML/Graphics.hpp>
#include "StaticComponent.h"

class PositionObserver {
public:
    PositionObserver()= default;
    virtual ~PositionObserver()= default;
    virtual void update(sf::RectangleShape& rect, int i, bool active=true)=0;
};
#endif //GAME_POSITIONOBSERVER_H
