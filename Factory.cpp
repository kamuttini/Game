//
// Created by camut on 31/05/19.
//

#include "Factory.h"
#include "Enemy.h"

std::unique_ptr<Weapon> Factory::createWeapon(std::list<CollisionObserver *> &targetList, sf::Vector2f targetDir, sf::Vector2f position, Enemy* refEnemy)
{
    std::unique_ptr<Weapon> weapon;

    if(refEnemy!= nullptr) {
        Enemy::type enemyID=refEnemy->getId();
        switch(enemyID)
        {
            case Enemy::type::student:
                weapon= std::unique_ptr<Weapon>(new Weapon(targetList,sf::Color::Cyan,targetDir, position));
                break;

            case Enemy::type::chef:
                weapon= std::unique_ptr<Weapon>(new Weapon(targetList,sf::Color::Blue,targetDir, position));
                break;

            case Enemy::type::barMan:
                weapon= std::unique_ptr<Weapon>(new Weapon(targetList,sf::Color::Green,targetDir, position));
                break;
        }
    }

    else
        weapon= std::unique_ptr<Weapon>(new Weapon(targetList,sf::Color::White,targetDir, position));

    return weapon;
}


std::unique_ptr<PlayerWeapon> Factory::createPlayerWeapon(Player* player){
    std::unique_ptr<PlayerWeapon> weapon;

    weapon= std::unique_ptr<PlayerWeapon>(new PlayerWeapon(player));
    return weapon;
}


std::unique_ptr<Enemy> Factory::createEnemy(Player *player) {
    sf::Color color;
    Enemy::type ID;
    srand(clock());
    int x=rand()%3;
    switch(x)
    {
        case 0:
            ID=Enemy::type::student;
            color=sf::Color::Cyan;
            break;

        case 1:
            ID=Enemy::type::chef;
            color=sf::Color::Blue;
            break;

        case 2:
            ID=Enemy::type::barMan;
            color=sf::Color::Green;
            break;
    }
    std::unique_ptr<Enemy> enemy;
    enemy= std::unique_ptr<Enemy>(new Enemy(player,ID, color));
    return enemy;
}
