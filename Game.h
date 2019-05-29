//
// Created by camut on 25/05/19.
//

#ifndef GAME_GAME_H
#define GAME_GAME_H


#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
typedef std::unique_ptr<Enemy>  enemyPtr;

class Game {
public:
    void run(sf::RenderWindow& window);
    void processEvents(sf::RenderWindow& window);
    void update();
    void render(sf::RenderWindow& window);
    std::vector<enemyPtr> enemyVec;

protected:
    Player player;
};


#endif //GAME_GAME_H
