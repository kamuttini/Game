//
// Created by camut on 24/05/19.
//

#include <list>
#include "Weapon.h"

Weapon:: Weapon(std::list<CollisionObserver*>& targetList, orientation targetDir, sf::Vector2f vector, int s): DynamicComponent (s, targetDir){
    for (std::list<CollisionObserver*>::iterator iter = targetList.begin(); iter != targetList.end(); ++iter)
    {
        addObserver(*iter);
    }

    rect.setFillColor(sf::Color::White);
    rect.setPosition(vector);
}

void Weapon::addObserver(CollisionObserver* o){
    characters.push_back(o);
}

void Weapon::removeObserver(CollisionObserver *o){
    characters.remove(o);
}

void Weapon::notify() const{
    std::list<CollisionObserver *, std::allocator<CollisionObserver *>>::const_iterator itr;
    for(itr = characters.begin(); characters.end() != itr; itr++){
        (*itr)->update(rect.getGlobalBounds());
    }
}

void Weapon::attack() {
    sf::Vector2f movement(0.f,0.f);

    if(direction==right)
        movement.x+=speed;
    if(direction==down)
        movement.y+=speed;
    if(direction==left)
        movement.x-= speed;
    if(direction==up)
        movement.y-=speed;

    rect.move(movement);
    notify();
}





