//
// Created by camut on 24/05/19.
//

#include "StaticComponent.h"
#include "Sprite.h"

StaticComponent:: StaticComponent(orientation dir): colMap(new TileMap("colMap.txt", true)),
                                                    direction(dir){

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

    int tileToCheck=findTile();
    std::list<int>::iterator it =std::find(colMap->colTiles.begin(),colMap->colTiles.end(), tileToCheck);
    if (it != colMap->colTiles.end())
        randomPosition(range,origin);
}
int StaticComponent::findTile() {

    //Riconosce il tile per la collisione

    bottom =rect.getPosition().y+rect.getSize().y-20;
    sx =rect.getPosition().x;
    dx=rect.getPosition().x+rect.getSize().x;
    top =rect.getPosition().y;

    int tileX=int(dx)/(16*2.5);
    int tileY=int(bottom)/(16*2.5);
    return tileX+(tileY*110);

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

