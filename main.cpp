#include <iostream>
#include "SFML/Graphics.hpp"
#include "Game.h"


int main() {
    sf::RenderWindow window(sf::VideoMode(1400, 1000), "game window");
    Game game(window);
    window.setFramerateLimit(60);
    game.start();

    return 0;
}


