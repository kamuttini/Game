//
// Created by camut on 02/06/19.
//

#ifndef GAME_SIDEBAR_H
#define GAME_SIDEBAR_H


#include <SFML/Graphics.hpp>
class Player;
class Sidebar {

public:
    Sidebar();
    void draw(sf::RenderWindow& window);
    void updateHp(int hp) ;
    void updateWeapons(int weapons);
private:
    sf::Text hpText;
    sf::Text weaponsText;
    sf::Font font;
};


#endif //GAME_SIDEBAR_H
