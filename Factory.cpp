//
// Created by camut on 31/05/19.
//

#include "Factory.h"
#include "Enemy.h"

std::unique_ptr<Weapon> Factory::createEnemyWeapon(std::list<CollisionObserver *> &targetList, sf::Vector2f targetDir,
                                                   sf::Vector2f position, Enemy *refEnemy)
{
    std::unique_ptr<Weapon> weapon;

    Enemy::type enemyID=refEnemy->getId();
    switch(enemyID)
    {
        case Enemy::type::student:
            weapon= std::unique_ptr<Weapon>(new Weapon(targetList, targetDir, position, Weapon::type::book));
            break;

            case Enemy::type::chef:
                weapon= std::unique_ptr<Weapon>(new Weapon(targetList, targetDir, position, Weapon::type::pizza));
                break;

                case Enemy::type::barMan:
                weapon= std::unique_ptr<Weapon>(new Weapon(targetList, targetDir, position, Weapon::type::coffee));
                break;
    }

    return weapon;
}


std::unique_ptr<PlayerWeapon> Factory::createWeaponToCollect(Player *player){
    std::unique_ptr<PlayerWeapon> weapon;
    Weapon::type ID= Weapon::type (rand() % 3);
    weapon= std::unique_ptr<PlayerWeapon>(new PlayerWeapon(player, ID));
    return weapon;
}


std::unique_ptr<Enemy> Factory::createEnemy(Player *player) {
    Enemy::type ID= Enemy::type (rand() % 3);
    std::unique_ptr<Enemy> enemy;
    enemy= std::unique_ptr<Enemy>(new Enemy(player,ID));
    return enemy;
}

std::unique_ptr<Weapon> Factory::createPlayerWeapon(Weapon::type ID, std::list<CollisionObserver *> &targetList, sf::Vector2f targetDir,sf::Vector2f position) {
    std::unique_ptr<Weapon> weapon;
    weapon= std::unique_ptr<Weapon>(new Weapon(targetList, targetDir, position, ID));
    return weapon;
}
