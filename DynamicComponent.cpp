//
// Created by camut on 24/05/19.
//

#include "DynamicComponent.h"


DynamicComponent:: DynamicComponent(float s):   colMap(new TileMap("colMap.txt", true)),
                                                speed(s),
                                                destroyed(false),
                                                colIter(0)
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

    int tileToCheck=findTile();

    switch (direction){

        case down:
            tileToCheck+=110;
            break;

        case up:

            break;

        case left:

            break;

        case right:
            tileToCheck+=1;
            break;
    }

    std::list<int>::iterator it =std::find(colMap->colTiles.begin(),colMap->colTiles.end(), tileToCheck);
    if (it != colMap->colTiles.end())
        return false;
    else
        return true;
}

int DynamicComponent::findTile() {

    //Riconosce il tile per la collisione

    bottom =rect.getPosition().y+rect.getSize().y-20;
    sx =rect.getPosition().x;
    dx=rect.getPosition().x+rect.getSize().x;
    top =rect.getPosition().y;

    int tileX=int(dx)/(16*2.5);
    int tileY=int(bottom)/(16*2.5);
    return tileX+(tileY*110);

}

void DynamicComponent::setSpeed(float s) {
    speed=s;
}

void DynamicComponent::changeColMap(){
    switch (colIter)
    {
        case 0:
            colMap=new TileMap("colMap2.txt",true);
            break;
        case 1:
            colMap=new TileMap("colMap3.txt",true);
            break;
    }
    if(colIter==0)
        colIter=1;
}





