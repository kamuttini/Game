//
// Created by camut on 02/06/19.
//

#include "HUD.h"
#include <string>


HUD::HUD ():text{Text("HP"),Text("Weapons: 0"),Text("CFU: 0"),Text("PRESS P TO PAUSE",30)},
            score(0),
            hp(2)

{
    text[0].setPosition(-150,30);
    text[1].setPosition(-150,80);
    text[2].setPosition(-150,130);
    text[3].setPosition(950,30);

    bHeart.loadFromFile("assets/sprites/heartBlack.png");
    rHeart.loadFromFile("assets/sprites/heart.png");
    for(int i=0; i<3;i++)
    {
        hearts[i].setTexture(rHeart);
        hearts[i].setPosition(text[0].getPosition().x+45+(60*i),30);
        hearts[i].setScale(0.12,0.12);
    }

    sf::Color color(135,206,235,200);
    sxRect.setSize(sf::Vector2f(280,200));
    sxRect.setFillColor(color);
    sxRect.setPosition(sf::Vector2f(-200,0));
}

void HUD::draw(sf::RenderWindow& window) {
    window.draw(sxRect);
    for(int i=0; i<4; i++)
        text[i].draw(window);
    for(int i=0; i<3; i++)
        window.draw(hearts[i]);
}

void HUD::updateHp() {
    if(hp>=0)
    { hearts[hp].setTexture(bHeart);
    hp--;}
}

void HUD::updateWeapons(int weapons) {
    text[1].text.setString("Weapons: "+ std::to_string(weapons));
}

void HUD::updateScore(int bonus) {
    text[2].text.setString("CFU: "+ std::to_string(score=score+bonus));

}

int HUD::getScore() {
    return score;
}


