//
// Created by camut on 02/06/19.
//

#include "HUD.h"
#include <string>
#include "Player.h"

HUD::HUD ():  text{Text("HP"),Text("Weapons: 0"),Text("CFU: 0"),Text("Kills: 0"),Text("PRESS P TO PAUSE",30)},
              badge{Badge(Badge::type::killer),Badge(Badge::type::secchione),Badge(Badge::type::pacifista)},
              score(0)
{
    hp=4;
    pacifista=false;
    for(int i=0; i<4;i++)
        text[i].setPosition(-150,30+i*50);

    text[4].setPosition(950,30);

    bHeart.loadFromFile("assets/sprites/heartBlack.png");
    rHeart.loadFromFile("assets/sprites/heart.png");
    for(int i=0; i<3;i++)
    {
        hearts[i].setTexture(rHeart);
        hearts[i].setPosition(text[0].getPosition().x+45+(60*i),30);
        hearts[i].setScale(0.12,0.12);
    }

    sf::Color color(135,206,235,200);
    sxRect.setSize(sf::Vector2f(280,250));
    sxRect.setFillColor(color);
    sxRect.setPosition(sf::Vector2f(-200,0));
}

void HUD::draw(sf::RenderWindow& window) {
    window.draw(sxRect);
    for(auto & i : text)
        i.draw(window);
    for(auto & i : badge)
        i.draw(window);
    for(const auto & heart : hearts)
        window.draw(heart);
}

void HUD::update(int kills1, int weapon1, int hp1, bool pacifista) {
    if (kills != kills1) {
        kills = kills1;
        text[3].text.setString("Kills: " + std::to_string(kills));
        updateScore(DEAD_ENEMY);
        if(kills==KILLS && !badge[0].isActive())
        {
            badge[0].setActive(true);
            updateScore(BADGE_ACHIEVED);
        }
    }
    if (weaponCaught != weapon1) {
        weaponCaught = weapon1;
        text[1].text.setString("Weapons: " + std::to_string(weaponCaught));
        updateScore(WEAPON_CAUGHT);
        if(!badge[1].isActive() && weaponCaught>SECCHIONE )
        {
            badge[1].setActive(true);
            updateScore(BADGE_ACHIEVED);
        }
    }
    if (hp1 != hp) {
        hp = hp1;
        if (hp >= 1)
            hearts[hp - 1].setTexture(bHeart);
    }
    if(pacifista && !badge[2].isActive())
    {
        badge[2].setActive(true);
        updateScore(BADGE_ACHIEVED);
    }
}


void HUD::updateScore(int bonus) {
    text[2].text.setString("CFU: "+ std::to_string(score=score+bonus));

}

int HUD::getScore(){
    return score;
}

const Badge *HUD::getBadge() const {
    return badge;
}
