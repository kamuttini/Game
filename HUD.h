//
// Created by camut on 02/06/19.
//

#ifndef GAME_HUD_H
#define GAME_HUD_H


#include <SFML/Graphics.hpp>
#include "Text.h"
#include "PlayerObserver.h"
#include "Badge.h"

class Player;
class HUD: public PlayerObserver{
public:
    HUD();
    ~HUD()= default;;
    void draw(sf::RenderWindow& window);
    void update(int kills, int weapon, int hp, bool pacifista)override ;
    void updateScore(int bonus) override ;
    int getScore();
    const Badge *getBadge() const;

private:
    int score;
    Text text[5];
    Badge badge[3];
    sf::Texture rHeart;
    sf::Texture bHeart;
    sf::Sprite hearts[3];
    sf::RectangleShape sxRect;
};


#endif //GAME_HUD_H
