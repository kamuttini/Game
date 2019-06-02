//
// Created by camut on 25/05/19.
//

#ifndef GAME_GAME_H
#define GAME_GAME_H

#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "Player.h"
#include "MainMenu.h"
#include "GameOver.h"

class Game {
public:
    typedef std::unique_ptr<Enemy>  enemyPtr;
    typedef std::unique_ptr<PlayerWeapon> playerWeaponPtr;

    Game(sf::RenderWindow& window);
    void start();
    void run();
    void stop();
    void processEvents();
    void update();
    void render();
    std::vector<enemyPtr> enemyVec;

private:
    MainMenu menu;
    GameOver gameOver;
    Factory factory;
    std::vector<playerWeaponPtr> weaponToCollect;
    sf::RenderWindow& window;
    Player* player;
    Sidebar* sidebar;
};


#endif //GAME_GAME_H
