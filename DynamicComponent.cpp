//
// Created by camut on 24/05/19.
//

#include "DynamicComponent.h"


DynamicComponent:: DynamicComponent(float s):   speed(s),
                                                destroyed(false)
                                                {}

bool DynamicComponent::isDestroyed() const {
    return destroyed;
}

void DynamicComponent::setIsDestroyed(bool isDestroyed) {
    DynamicComponent::destroyed = isDestroyed;
}

float DynamicComponent::getSpeed() const {
    return speed;
}






