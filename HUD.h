//
// Created by camut on 02/06/19.
//

#ifndef GAME_HUD_H
#define GAME_HUD_H


#include <SFML/Graphics.hpp>
#include "Text.h"
class Player;
class HUD {

public:
    HUD();
    ~HUD(){};
    void draw(sf::RenderWindow& window);
    void updateHp(int hp) ;
    void updateWeapons(int weapons);
    void updateScore(int bonus);
    int getScore();

private:
    int score;
    Text text[4];
    sf::RectangleShape sxRect;
    sf::RectangleShape dxRect;
};


#endif //GAME_HUD_H
