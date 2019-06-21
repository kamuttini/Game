//
// Created by camut on 17/06/19.
//

#ifndef GAME_ROOM_H
#define GAME_ROOM_H

#include "SFML/Graphics.hpp"
#include "Factory.h"
#include "Player.h"
#include "Enemy.h"
#include "HallShape.h"

typedef std::unique_ptr<Enemy>  enemyPtr;
typedef std::unique_ptr<PlayerWeapon> playerWeaponPtr;

class Room{
public:
    enum type{canteen, hall, classroom1, classroom2, bar, classRoom3};

    explicit Room( type ID);

    virtual void update();
    virtual bool activeUpdate(Player &player);
    void create(Player& player);
    void destroy();
    virtual void draw(sf::RenderWindow& window);

    const sf::Vector2f &getOrigin() const;
    const sf::Vector2f &getDimension() const;
    type getId() const;
    const sf::RectangleShape &getRect() const;

    std::vector<enemyPtr> enemyVec;
    std::vector<playerWeaponPtr> weaponToCollect;

protected:
    Factory factory;
    sf::Clock enemyClock;
    sf::Time enemyDelay=sf::seconds(4.f);
    sf::Clock playerWeaponClock;
    sf::Time playerWeaponDelay=sf::seconds(2.5f);
    sf::Vector2f origin;
    sf::Vector2f dimension;
    type ID;
    sf::RectangleShape* rect;
    HallShape* hallShape;
    int maxEnemyN;
};


#endif //GAME_ROOM_H
