//
// Created by camut on 24/05/19.
//

#include <list>
#include "Weapon.h"

Weapon:: Weapon(std::list<CollisionObserver*>& targetList,sf::Color color1, sf::Vector2f targetDir, sf::Vector2f position, float s): DynamicComponent (s, color1),
                                                                                                                    targetDir(targetDir*speed)
{
    for (std::list<CollisionObserver*>::iterator iter = targetList.begin(); iter != targetList.end(); ++iter)
    {
        addObserver(*iter);
    }
    rect.setSize(sf::Vector2f(15.f,15.f));
    rect.setPosition(position);
}

Weapon::Weapon( sf::Color color1,float s ): DynamicComponent(s, color1){
}

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
    rect.move(targetDir);
    notify();
}

void Weapon::destroy(std::vector<std::unique_ptr<Weapon>>& weapon,std::vector<std::unique_ptr<Weapon>>::const_iterator iter) {

    weapon.erase(iter);
}

std::unique_ptr<Weapon> Weapon::clone() const {

    return std::unique_ptr<Weapon>( new Weapon(*this));
}




