//
// Created by camut on 24/05/19.
//

#include "DynamicComponent.h"


DynamicComponent:: DynamicComponent(float s, sf::Color color1, orientation dir): StaticComponent(color1),  speed(s),
                                                                isDestroyed(false),
                                                                direction(dir){}

DynamicComponent::orientation DynamicComponent::getDirection() const {
    return direction;
}

void DynamicComponent::setDirection(orientation direction) {
    DynamicComponent::direction = direction;
}

bool DynamicComponent::isDestroyed1() const {
    return isDestroyed;
}

void DynamicComponent::setIsDestroyed(bool isDestroyed) {
    DynamicComponent::isDestroyed = isDestroyed;
}

int DynamicComponent::getSpeed() const {
    return speed;
}

void DynamicComponent::setSpeed(int speed) {
    DynamicComponent::speed = speed;
}


