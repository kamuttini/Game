//
// Created by camut on 31/05/19.
//

#include "Factory.h"
#include "Enemy.h"
#include "RandomMove.h"
#include "Room.h"

std::unique_ptr<Weapon> Factory::createEnemyWeapon(std::list<CollisionObserver *> &targetList, sf::Vector2f targetDir,
                                                   sf::Vector2f position, Enemy *refEnemy) {
    std::unique_ptr<Weapon> weapon;

    Enemy::type enemyID = refEnemy->getId();
    switch (enemyID) {
        case Enemy::type::student:
            weapon = std::unique_ptr<Weapon>(new Weapon(targetList, targetDir, position, Weapon::type::book));
            break;

        case Enemy::type::chef:
            weapon = std::unique_ptr<Weapon>(new Weapon(targetList, targetDir, position, Weapon::type::pizza));
            break;

        case Enemy::type::barMan:
            weapon = std::unique_ptr<Weapon>(new Weapon(targetList, targetDir, position, Weapon::type::coffee));
            break;
    }

    return weapon;
}

std::unique_ptr<Weapon>
Factory::createPlayerWeapon(Weapon::type ID, std::list<CollisionObserver *> &targetList, sf::Vector2f targetDir,
                            sf::Vector2f position) {
    std::unique_ptr<Weapon> weapon;
    weapon = std::unique_ptr<Weapon>(new Weapon(targetList, targetDir, position, ID));
    return weapon;
}

std::unique_ptr<PlayerWeapon> Factory::createWeaponToCollect(Player *player,Room& room) {
    Weapon::type ID;
    switch (room.getId())
    {
        case Room::type ::canteen:
            ID = Weapon::type::pizza;
            break;

        case Room::type ::hall:
            ID = Weapon::type::book;
            break;

        case Room::type ::bar:
            ID = Weapon::type::coffee;
            break;

        case Room::type::classroom1:
            ID = Weapon::type::book;
            break;

        case Room::type::classroom2:
            ID = Weapon::type::book;
            break;
        case Room::type::classRoom3:
            ID = Weapon::type::book;
            break;
    }
    std::unique_ptr<PlayerWeapon> weapon;
    weapon = std::unique_ptr<PlayerWeapon>(new PlayerWeapon(player, ID,room.getOrigin(),room.getDimension()));
    return weapon;
}


std::unique_ptr<Enemy> Factory::createEnemy(Player *player, Room& room) {
    Enemy::type ID;
    switch (room.getId())
    {
        case Room::type ::canteen:
            ID = Enemy::type::chef;
            break;

        case Room::type ::hall:
            ID = Enemy::type::student;
            break;
        case Room::type ::bar:
            ID = Enemy::type::barMan;
            break;
        case Room::type::classroom1:
            ID = Enemy::type::student;
            break;
        case Room::type::classroom2:
            ID = Enemy::type::student;
            break;
        case Room::type::classRoom3:
            ID = Enemy::type::student;
            break;

    }
    std::unique_ptr<Enemy> enemy;
    enemy = std::make_unique<Enemy>(player, ID, room.getOrigin(),room.getDimension());
    return enemy;
}


