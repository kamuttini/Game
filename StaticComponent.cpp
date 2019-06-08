//
// Created by camut on 24/05/19.
//

#include "StaticComponent.h"
#include "Sprite.h"

StaticComponent:: StaticComponent(orientation dir): direction(dir){

    rect.setSize(sf::Vector2f(30.f,51.f));
}

void StaticComponent::draw(sf::RenderWindow &window)
{
    sprite->draw(window);
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
StaticComponent::orientation StaticComponent::getDirection() const {
    return direction;
}
void StaticComponent::setDirection(StaticComponent::orientation direction) {
    StaticComponent::direction = direction;
}

Sprite *StaticComponent::getSprite() const {
    return sprite;
}

