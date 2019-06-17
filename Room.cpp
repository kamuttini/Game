//
// Created by camut on 17/06/19.
//

#include "Room.h"
#include "Def.h"

Room::Room(type ID1) : ID(ID1) {
    switch (ID) {
        case canteen:
            origin = CANTEEN_ORIGIN;
            dimension = CANTEEN_DIMENSION;
            break;

        case hall:
            origin = HALL_ORIGIN;
            dimension = HALL_DIMENSION;
            break;

        case bar:
            origin = BAR_ORIGIN;
            dimension = BAR_DIMENSION;
            break;

        case classroom1:
            origin = CLASSROOM1_ORIGIN;
            dimension = CLASSROOM1_DIMENSION;
            break;

        case classroom2:
            origin = CLASSROOM2_ORIGIN;
            dimension = CLASSROOM2_DIMENSION;
            break;
    }

    rect.setPosition(origin);
    rect.setSize(dimension);
    rect.setFillColor(sf::Color::Blue);

}

void Room::update(Player *player) {

    if (enemyVec.size() <= 1 &&
        enemyClock.getElapsedTime() >=
        enemyDelay)                                                                        //generate enemy
    {
        enemyVec.push_back(factory.createEnemy(player, *this));
        enemyClock.restart();
    }
    int i = 0;
    for (i = 0; i < weaponToCollect.size(); i++) {
        weaponToCollect[i]->notify();
        weaponToCollect[i]->updateState();
    }

    if (playerWeaponClock.getElapsedTime() >=
        playerWeaponDelay)                                                        //generate playerWeapon
    {
        weaponToCollect.push_back(factory.createWeaponToCollect(player, *this));
        playerWeaponClock.restart();
    }

    for (i = 0; i <
                enemyVec.size(); i++)                                                                               //generate enemyWeapon
        enemyVec[i]->updateState();

    std::vector<std::unique_ptr<Enemy>>::const_iterator iter1;                                                          //delete enemy if collision detected
    i = 0;
    for (iter1 = enemyVec.begin(); iter1 != enemyVec.end(); iter1++) {
        if (enemyVec[i]->isDestroyed()) {
            enemyVec[i]->destroy(enemyVec, iter1);
            break;
        }
        i++;
    }


    std::vector<std::unique_ptr<PlayerWeapon>>::const_iterator iter3 = weaponToCollect.begin();                         //delete weapon if collision detected
    for (i = 0; i < weaponToCollect.size(); i++) {
        if (weaponToCollect[i]->isDestroyed())
            weaponToCollect[i]->destroy(weaponToCollect, iter3);
        iter3++;
    }
}


