//
// Created by camut on 01/06/19.
//

#include <deque>
#include "Inventory.h"

Inventory::Inventory():alert("Weapon inventory is empty!")
{
    alert.setPosition(WEAPONALER_POSITION);
}


void Inventory::addToCollection(Weapon& weaponCaught) {
    weaponCollection.push_back(weaponCaught.getId());
}


void Inventory::useWeapon(std::list<CollisionObserver*>& targetList, sf::Vector2f targetDir, sf::Vector2f position) {
    if(!weaponCollection.empty()) {
        Weapon::type ID=weaponCollection[0];
        weaponVec.push_back(weaponFactory.createPlayerWeapon(ID,targetList, targetDir, position));
        removeFromCollection();
    }
    else
        alert.startDisplaying();
}

void Inventory::removeFromCollection() {

    weaponCollection.erase(weaponCollection.begin());
}

int Inventory::collectionSize() {
    return weaponCollection.size();
}

void Inventory::updateState() {
    std::vector<std::unique_ptr<Weapon>>::const_iterator iter2;
    int i=0;
    for (iter2=weaponVec.begin(); iter2!=weaponVec.end(); iter2++)      //delete weapon if collision detected
    {
        if (weaponVec[i]->isDestroyed())
        {
            weaponVec[i]->destroy(weaponVec,iter2);
            break;
        }
        i++;
    }
}


