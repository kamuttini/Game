//
// Created by camut on 03/06/19.
//

#ifndef GAME_GAMEOVER_H
#define GAME_GAMEOVER_H

#include <SFML/Graphics.hpp>

class GameOver {
public:
    GameOver(sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);

protected:
    sf::RenderWindow& window;
    sf::Text text;
    sf::Text enterText;
    sf::Font font;
    sf::Vector2u WindowSize;

};


#endif //GAME_GAMEOVER_H
