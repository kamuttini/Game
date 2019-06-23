//
// Created by camut on 24/05/19.
//

#include <list>
#include "Weapon.h"

Weapon::Weapon(std::list<CollisionObserver *> &targetList, sf::Vector2f playerDir, sf::Vector2f position, type ID,
               float s) : DynamicComponent (s),
                          targetDir(playerDir),
                          exploded(false),
                          explosionTime(EXPLOSION_TIME),
                          ID(ID)
{
    for (std::list<CollisionObserver*>::iterator iter = targetList.begin(); iter != targetList.end(); ++iter)
    {
        addObserver(*iter);
    }
    rect.setSize(sf::Vector2f(15.f,15.f));
    rect.setPosition(position);
    sprite= new Sprite(setSprite(), *this);
}

Weapon::Weapon(type ID1,float s ): DynamicComponent(s), ID(ID1){}

void Weapon::addObserver(CollisionObserver* o){
    characters.push_back(o);
}

void Weapon::removeObserver(CollisionObserver *o){
    characters.remove(o);
}

void Weapon::notify() {
    std::list<CollisionObserver *, std::allocator<CollisionObserver *>>::const_iterator itr;
    for(itr = characters.begin(); characters.end() != itr; itr++){
        (*itr)->update(this);
    }
}

void Weapon::attack() {
    if(targetDir.x>0) {
        if(targetDir.x>targetDir.y)
            direction=down;
        else
            direction=left;
    }
    else {
        if(targetDir.x>targetDir.y)
            direction=right;
        else
        direction=up;
    }
    if(!checkBorders(direction))
        destroyed=true;
    if(!destroyed) {
        rect.move(targetDir*speed);
        notify();
        sprite->update();
    }
}

void Weapon::destroy(std::vector<std::unique_ptr<Weapon>>& weapon,std::vector<std::unique_ptr<Weapon>>::const_iterator iter) {
    if(!exploded)
    {
        sprite->setExplodeTexture();
        exploded=true;
        explosionClock.restart();
    }

    sprite->explode();
    if(explosionClock.getElapsedTime()>explosionTime)
        weapon.erase(iter);
}

std::unique_ptr<Weapon> Weapon::clone() const {

    return std::unique_ptr<Weapon>( new Weapon(*this));
}

Weapon::type Weapon::getId() const {
    return ID;
}

std::string Weapon::setSprite() {
 std::string filename;
    switch(ID)
    {
        case book:
            filename="book1.png";
            break;
        case pizza:
            filename="pizza1.png";
            break;
        case coffee:
            filename="caffe1.png";
            break;
    }
    return filename;
}
