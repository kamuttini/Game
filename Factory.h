//
// Created by camut on 31/05/19.
//

#ifndef GAME_FACTORY_H
#define GAME_FACTORY_H

#include "PlayerWeapon.h"

class Enemy;
class Room;
class Factory {
public:
    static std::unique_ptr<Weapon> createEnemyWeapon(std::list<CollisionObserver *> &targetList, sf::Vector2f targetDir,sf::Vector2f position, Enemy *refEnemy);
    static std::unique_ptr<Weapon> createPlayerWeapon(Weapon::type ID,std::list<CollisionObserver *> &targetList, sf::Vector2f targetDir,sf::Vector2f position);
    static std::unique_ptr<PlayerWeapon> createWeaponToCollect(Player *player,Room& room);
    static std::unique_ptr<Enemy> createEnemy(Player* player, Room& room);
};


#endif //GAME_FACTORY_H
