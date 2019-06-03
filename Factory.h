//
// Created by camut on 31/05/19.
//

#ifndef GAME_FACTORY_H
#define GAME_FACTORY_H

#include "PlayerWeapon.h"

class Enemy;
class Factory {
public:
    static std::unique_ptr<Weapon> createWeapon(std::list<CollisionObserver *> &targetList, sf::Vector2f targetDir,sf::Vector2f position,Enemy* refEnemy=nullptr);
    static std::unique_ptr<PlayerWeapon> createPlayerWeapon(Player* player);
    static std::unique_ptr<Enemy> createEnemy(Player* player);
};


#endif //GAME_FACTORY_H
