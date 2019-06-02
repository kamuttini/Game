//
// Created by camut on 01/06/19.
//

#ifndef GAME_INVENTORY_H
#define GAME_INVENTORY_H


#include "Weapon.h"
#include "Factory.h"

class Inventory {
public:
    typedef std::unique_ptr<Weapon>  weaponPtr;
    void addToCollection(Weapon weapon);
    void removeWeapon();
    void useWeapon(std::list<CollisionObserver*>& targetList, sf::Vector2f targetDir, sf::Vector2f position);
    int collectionSize();
    void updateState();
    std::vector<weaponPtr> weaponVec;

private:
    Factory weaponFactory;
    std::vector<weaponPtr> weaponCollection;
};


#endif //GAME_INVENTORY_H
