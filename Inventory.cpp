//
// Created by camut on 01/06/19.
//

#include <deque>
#include "Inventory.h"



void Inventory::addToCollection(Weapon weaponCaught) {
    weaponCollection.push_back(weaponCaught.clone());
}


void Inventory::useWeapon(std::list<CollisionObserver*>& targetList, sf::Vector2f targetDir, sf::Vector2f position) {
    if(!weaponCollection.empty()) {
        weaponVec.push_back(weaponFactory.createWeapon(targetList, targetDir, position));
        removeWeapon();
    }
}

void Inventory::removeWeapon() {
    std::vector<std::unique_ptr<Weapon>>::const_iterator iter = weaponCollection.begin();
    weaponCollection[0]->destroy(weaponCollection, iter);
}

