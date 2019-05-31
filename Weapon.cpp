//
// Created by camut on 24/05/19.
//

#include <list>
#include "Weapon.h"

Weapon:: Weapon(std::list<CollisionObserver*>& targetList, sf::Vector2f targetDir, sf::Vector2f position, int s): DynamicComponent (s), targetDir(targetDir*speed)
{
    for (std::list<CollisionObserver*>::iterator iter = targetList.begin(); iter != targetList.end(); ++iter)
    {
        addObserver(*iter);
    }

    rect.setFillColor(sf::Color::White);
    rect.setPosition(position);
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
    rect.move(targetDir);
    notify();
}





