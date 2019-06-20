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
    rect.setFillColor(sf::Color::Transparent);
}

void Room::update() {
    std::vector<std::unique_ptr<Enemy>>::const_iterator iter1;                                                          //delete enemy if collision detected
    int i = 0;
    for (iter1 = enemyVec.begin(); iter1 != enemyVec.end(); iter1++) {
        if (enemyVec[i]->isDestroyed()) {
            enemyVec[i]->destroy(enemyVec, iter1);
        }
        else {

            for (int k = 0; k < enemyVec[i]->weaponVec.size(); k++)
                enemyVec[i]->weaponVec[k]->attack();

            std::vector<std::unique_ptr<Weapon>>::const_iterator iter2;
            for (int j = 0; j != enemyVec[i]->weaponVec.size(); j++) {
                iter2 = enemyVec[i]->weaponVec.begin();
                if (enemyVec[i]->weaponVec[j]->isDestroyed()) {
                    enemyVec[i]->weaponVec[j]->destroy(enemyVec[i]->weaponVec, iter2);
                    break;
                }
                iter2++;
            }
        }
        i++;
    }
}

bool Room::activeUpdate(Player &player) {
    create(player);

    int i = 0;
    for (i = 0; i < weaponToCollect.size(); i++) {
        weaponToCollect[i]->notify();
        weaponToCollect[i]->updateState();
    }

    for (i = 0; i <enemyVec.size(); i++)                                                                               //generate enemyWeapon
        enemyVec[i]->updateState();

    std::vector<std::unique_ptr<PlayerWeapon>>::const_iterator iter3 = weaponToCollect.begin();                         //delete weapon if collision detected
    for (i = 0; i < weaponToCollect.size(); i++) {
        if (weaponToCollect[i]->isDestroyed())
            weaponToCollect[i]->destroy(weaponToCollect, iter3);
        iter3++;
    }
    return false;
}

void Room::create(Player& player) {
    if (ID == hall) {
        if (enemyVec.size() <= 2 && enemyClock.getElapsedTime() >= enemyDelay)                                                                        //generate enemy
        {
            enemyVec.push_back(factory.createEnemy(&player, *this));
            enemyClock.restart();
        }
    }
    else
        if (enemyVec.size() <= 1 && enemyClock.getElapsedTime() >= enemyDelay)                                                                        //generate enemy
    {
        enemyVec.push_back(factory.createEnemy(&player, *this));
        enemyClock.restart();
    }

    if (playerWeaponClock.getElapsedTime() >= playerWeaponDelay)                                                        //generate playerWeapon
    {
        weaponToCollect.push_back(factory.createWeaponToCollect(&player, *this));
        playerWeaponClock.restart();
    }
}

void Room::draw(sf::RenderWindow &window) {
    int i, j;
    for (i = 0; i <enemyVec.size(); i++) {
        enemyVec[i]->draw(window);
        for (j = 0; j < enemyVec[i]->weaponVec.size(); j++)
            enemyVec[i]->weaponVec[j]->draw(window);
    }

    for (i = 0; i < weaponToCollect.size(); i++)
        weaponToCollect[i]->draw(window);
}

const sf::Vector2f &Room::getOrigin() const {
    return origin;
}

const sf::Vector2f &Room::getDimension() const {
    return dimension;
}

Room::type Room::getId() const {
    return ID;
}

const sf::RectangleShape &Room::getRect() const {
    return rect;
}

