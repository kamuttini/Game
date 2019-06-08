//
// Created by camut on 24/05/19.
//

#include "DynamicComponent.h"


DynamicComponent:: DynamicComponent(float s):   speed(s),
                                                isDestroyed(false)
                                                {}

bool DynamicComponent::isDestroyed1() const {
    return isDestroyed;
}

void DynamicComponent::setIsDestroyed(bool isDestroyed) {
    DynamicComponent::isDestroyed = isDestroyed;
}

float DynamicComponent::getSpeed() const {
    return speed;
}






