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

void StaticComponent::randomPosition(sf::Vector2f range, sf::Vector2f origin)
{
    int minx=origin.x;
    int miny=origin.y;
    int x=origin.x+range.x;
    int y=origin.y+range.y;

    srand(clock());
    posX=rand()%(x- minx+ 1) + minx;
    posY=rand()%(y- miny+ 1) + miny;
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

sf::Vector2f StaticComponent::getPosition() {
    return rect.getPosition();
}

