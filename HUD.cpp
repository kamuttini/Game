//
// Created by camut on 02/06/19.
//

#include "HUD.h"
#include <string>


HUD::HUD ():text{Text("HP: 3/3"),
                                            Text("Weapons: 0"),
                                            Text("CFU: 0"),
                                            Text("PRESS P TO PAUSE",30)}

{
    text[0].setPosition(-150,30);
    text[1].setPosition(-150,80);
    text[2].setPosition(-150,130);
    text[3].setPosition(950,30);
    score=0;

    sf::Color color(135,206,235,200);
    sxRect.setSize(sf::Vector2f(280,200));
    sxRect.setFillColor(color);
    dxRect.setSize(sf::Vector2f(600,90));
    dxRect.setFillColor(sf::Color::White);
    sxRect.setPosition(sf::Vector2f(-200,0));
    //dxRect.setPosition();
}

void HUD::draw(sf::RenderWindow& window) {
    window.draw(sxRect);
    for(int i=0; i<4; i++)
        text[i].draw(window);

}

void HUD::updateHp(int hp) {
    text[0].text.setString("HP:"+ std::to_string(hp)+"/3");
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


