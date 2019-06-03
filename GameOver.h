//
// Created by camut on 03/06/19.
//

#ifndef GAME_GAMEOVER_H
#define GAME_GAMEOVER_H

#include <SFML/Graphics.hpp>
#include "Text.h"

class GameOver {
public:
    GameOver(sf::RenderWindow& window, int score);
    void draw(sf::RenderWindow& window);

protected:
    sf::RenderWindow& window;
    Text title;
    Text enterText;
    Text scoreText;
    sf::Vector2u WindowSize;

};


#endif //GAME_GAMEOVER_H
