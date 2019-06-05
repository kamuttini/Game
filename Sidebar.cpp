//
// Created by camut on 02/06/19.
//

#include "Sidebar.h"
#include <string>


Sidebar::Sidebar ():    hpText("HP: 3/3"),
                        weaponsText("Weapons: 0"),
                        scoreText("Score: 0")

{
    hpText.setPosition(80,50);
    weaponsText.setPosition(80,100);
    scoreText.setPosition(80,150);
    score=0;
}

void Sidebar::draw(sf::RenderWindow& window) {
    hpText.draw(window);
    weaponsText.draw(window);
    scoreText.draw(window);
}

void Sidebar::updateHp(int hp) {
    hpText.text.setString("HP:"+ std::to_string(hp)+"/3");
}

void Sidebar::updateWeapons(int weapons) {
    weaponsText.text.setString("Weapons: "+ std::to_string(weapons));
}

void Sidebar::updateScore(int bonus) {
    scoreText.text.setString("Score: "+ std::to_string(score=score+bonus));

}

int Sidebar::getScore() {
    return score;
}
