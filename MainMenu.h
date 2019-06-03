//
// Created by camut on 02/06/19.
//

#ifndef GAME_MAINMENU_H
#define GAME_MAINMENU_H
#include <SFML/Graphics.hpp>
#include "Text.h"


class MainMenu {
public:
    MainMenu(sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);

protected:
    sf::RectangleShape rect;
    sf::RectangleShape rect2;
    sf::RenderWindow& window;
    sf::Texture texture;
    sf::Sprite background;
    Text titleText;
    Text enterText;
    sf::Vector2u TextureSize;
    sf::Vector2u WindowSize;
};


#endif //GAME_MAINMENU_H
