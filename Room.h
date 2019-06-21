//
// Created by camut on 17/06/19.
//

#ifndef GAME_ROOM_H
#define GAME_ROOM_H

#include "SFML/Graphics.hpp"
#include "Factory.h"
#include "Player.h"
#include "Enemy.h"
#include "Token.h"


typedef std::unique_ptr<Enemy>  enemyPtr;
typedef std::unique_ptr<PlayerWeapon> playerWeaponPtr;

class Room{
public:
    enum type{canteen, hall, classroom1, classroom2, bar, bossRoom};

    explicit Room( type ID);
    void update();
    virtual bool activeUpdate(Player &player);
    void create(Player& player);
    virtual void draw(sf::RenderWindow& window);

    const sf::Vector2f &getOrigin() const;
    const sf::Vector2f &getDimension() const;
    type getId() const;
    const sf::RectangleShape &getRect() const;

    std::vector<enemyPtr> enemyVec;
    std::vector<playerWeaponPtr> weaponToCollect;

private:
    Factory factory;
    sf::Clock enemyClock;
    sf::Time enemyDelay=sf::seconds(4.f);
    sf::Clock playerWeaponClock;
    sf::Time playerWeaponDelay=sf::seconds(2.5f);
    sf::Vector2f origin;
    sf::Vector2f dimension;
    type ID;
    sf::RectangleShape rect;
    Token *token;
};


#endif //GAME_ROOM_H
