//
// Created by camut on 01/06/19.
//

#ifndef GAME_INVENTORY_H
#define GAME_INVENTORY_H


#include "Weapon.h"
#include "Factory.h"
#include "Text.h"

typedef std::unique_ptr<Weapon>  weaponPtr;

class Inventory {
public:
    Inventory();
    ~Inventory(){};
    void addToCollection(Weapon& weapon);
    void removeFromCollection();
    void useWeapon(std::list<CollisionObserver*>& targetList, sf::Vector2f targetDir, sf::Vector2f position);
    int collectionSize();
    void updateState();
    std::vector<weaponPtr> weaponVec;
    Text alert;

private:
    Factory weaponFactory;
    std::vector<Weapon::type> weaponCollection;
};


#endif //GAME_INVENTORY_H
