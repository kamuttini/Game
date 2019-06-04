//
// Created by camut on 02/06/19.
//

#ifndef GAME_SIDEBAR_H
#define GAME_SIDEBAR_H


#include <SFML/Graphics.hpp>
#include "Text.h"
class Player;
class Sidebar {

public:
    Sidebar();
    ~Sidebar(){};
    void draw(sf::RenderWindow& window);
    void updateHp(int hp) ;
    void updateWeapons(int weapons);
    void updateScore(int bonus);
    int getScore();
private:
    int score;
    Text hpText;
    Text weaponsText;
    Text scoreText;
};


#endif //GAME_SIDEBAR_H
