//
// Created by camut on 25/05/19.
//

#ifndef GAME_GAME_H
#define GAME_GAME_H

#include <SFML/Graphics.hpp>
#include "Enemy.h"

class Game {
public:
    typedef std::unique_ptr<Enemy>  enemyPtr;
    typedef std::unique_ptr<PlayerWeapon> playerWeaponPtr;
    void run(sf::RenderWindow& window);
    void processEvents(sf::RenderWindow& window);
    void update();
    void render(sf::RenderWindow& window);
    std::vector<enemyPtr> enemyVec;

private:
    Factory factory;
    std::vector<playerWeaponPtr> weaponToCollect;

    Player player;
};


#endif //GAME_GAME_H
