//
// Created by camut on 24/05/19.
//

#include "StaticComponent.h"


StaticComponent:: StaticComponent(sf::Color color1){
    color=color1;
    rect.setSize(sf::Vector2f(30.f,51.f));
    rect.setFillColor(color);
}

void StaticComponent::draw(sf::RenderWindow &window)
{
    window.draw(rect);
}

void StaticComponent::randomPosition()
{
    srand(clock());
    posX=rand()%1350;
    posY=rand()%950;
    rect.setPosition(posX,posY);
}


sf::RectangleShape &StaticComponent::getRect()  {
    return rect;
}

