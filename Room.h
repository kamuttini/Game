//
// Created by camut on 17/06/19.
//

#ifndef GAME_ROOM_H
#define GAME_ROOM_H

#include "SFML/Graphics.hpp"
#include "Factory.h"
#include "Player.h"
#include "Enemy.h"

typedef std::unique_ptr<Enemy>  enemyPtr;
typedef std::unique_ptr<PlayerWeapon> playerWeaponPtr;

class Room{
public:
    enum type{canteen, hall, classroom1, classroom2, bar};
    Room( type ID);
    void update(Player* player);
    std::vector<enemyPtr> enemyVec;
    std::vector<playerWeaponPtr> weaponToCollect;

    sf::RectangleShape rect;
    Factory factory;

    sf::Clock enemyClock;
    sf::Time enemyDelay=sf::seconds(4.f);
    sf::Clock playerWeaponClock;
    sf::Time playerWeaponDelay=sf::seconds(2.5f);

    sf::Vector2f origin;
    sf::Vector2f dimension;
    type ID;
};


#endif //GAME_ROOM_H
