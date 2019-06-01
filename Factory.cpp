//
// Created by camut on 31/05/19.
//

#include "Factory.h"
#include "Enemy.h"

std::unique_ptr<Weapon> Factory::createEnemyWeapon(std::list<CollisionObserver*>& targetList, sf::Vector2f targetDir, sf::Vector2f position) {

    std::unique_ptr<Weapon> weapon;
    weapon= std::unique_ptr<Weapon>(new Weapon(targetList,targetDir, position));
    return weapon;
}

std::unique_ptr<PlayerWeapon> Factory::createPlayerWeapon(Player* player){
    std::unique_ptr<PlayerWeapon> weapon;

    weapon= std::unique_ptr<PlayerWeapon>(new PlayerWeapon(player));
    return weapon;

}

std::unique_ptr<Enemy> Factory::createEnemy(Player *player) {
    std::unique_ptr<Enemy> enemy;
    enemy= std::unique_ptr<Enemy>(new Enemy(player));
    return enemy;
}
