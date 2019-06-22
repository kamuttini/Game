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
    void updateHp() ;
    void updateWeapons(int weapons);
    void updateScore(int bonus);
    int getScore();

private:
    int score;
    int hp;
    Text text[4];
    sf::Texture rHeart;
    sf::Texture bHeart;
    sf::Sprite hearts[3];
    sf::RectangleShape sxRect;
};


#endif //GAME_HUD_H
