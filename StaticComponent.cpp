//
// Created by camut on 24/05/19.
//

#include "StaticComponent.h"


StaticComponent:: StaticComponent(){
    rect.setSize(sf::Vector2f(30.f,51.f));

}

void StaticComponent::draw(sf::RenderWindow &window)
{
    window.draw(rect);
}

int StaticComponent::getPosX() const {
    return posX;
}

void StaticComponent::setPosX(int posX) {
    StaticComponent::posX = posX;
}

int StaticComponent::getPosY() const {
    return posY;
}

void StaticComponent::setPosY(int posY) {
    StaticComponent::posY = posY;
}

const sf::RectangleShape &StaticComponent::getRect() const {
    return rect;
}

void StaticComponent::setRect(const sf::RectangleShape &rect) {
    StaticComponent::rect = rect;
}
