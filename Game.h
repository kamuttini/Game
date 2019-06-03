//
// Created by camut on 25/05/19.
//

#ifndef GAME_GAME_H
#define GAME_GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Enemy.h"
#include "Player.h"
#include "MainMenu.h"
#include "GameOver.h"

class Game {
public:
    typedef std::unique_ptr<Enemy>  enemyPtr;
    typedef std::unique_ptr<PlayerWeapon> playerWeaponPtr;

    explicit Game(sf::RenderWindow& window);
    void start();
    void run();
    void stop();
    void playProcessEvent();
    void ProcessEvent();
    void update();
    void render();
    std::vector<enemyPtr> enemyVec;

private:
    MainMenu menu;
    GameOver* gameOver;
    Sidebar* sidebar;
    Player* player;
    sf::Music soundTrack;
    Factory factory;
    std::vector<playerWeaponPtr> weaponToCollect;
    sf::RenderWindow& window;
};


#endif //GAME_GAME_H
