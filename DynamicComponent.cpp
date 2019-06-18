//
// Created by camut on 24/05/19.
//

#include "DynamicComponent.h"


DynamicComponent:: DynamicComponent(float s):   colMap("colMap.txt", true),
                                                speed(s),
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


bool DynamicComponent::checkBorders( orientation direction) {
    findTile();
    int tileToCheck=tile;

    switch (direction){

        case down:
            tileToCheck+=110;
            break;

        case up:
            tileToCheck-=110;
            break;

        case left:
            tileToCheck-=1;
            break;

        case right:
            tileToCheck+=1;
            break;
    }

    std::vector<int>::iterator it =std::find(colMap.colTiles.begin(),colMap.colTiles.end(), tileToCheck);
    if (it != colMap.colTiles.end())
        return false;
    else
        return true;
}

void DynamicComponent::findTile() {

    //Riconosce il tile per la collisione

    bottom =rect.getPosition().y+rect.getSize().y-20;
    sx =rect.getPosition().x+15;
    dx=rect.getPosition().x+rect.getSize().x;
    top =rect.getPosition().y;

    int tileX=int(sx)/(16*2.5);
    int tileY=int(bottom)/(16*2.5);
    tile=(tileX+tileY*110);
}




