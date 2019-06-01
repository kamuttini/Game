//
// Created by camut on 31/05/19.
//

#ifndef GAME_FACTORY_H
#define GAME_FACTORY_H

#include "PlayerWeapon.h"
class Enemy;
class Factory {
public:
    std::unique_ptr<Weapon> createEnemyWeapon(std::list<CollisionObserver*>& targetList, sf::Vector2f targetDir, sf::Vector2f position);
    std::unique_ptr<PlayerWeapon> createPlayerWeapon(Player* player);
    std::unique_ptr<Enemy> createEnemy(Player* player);
};


#endif //GAME_FACTORY_H
