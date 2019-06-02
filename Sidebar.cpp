//
// Created by camut on 02/06/19.
//

#include "Sidebar.h"
#include <string>
#include <iostream>


Sidebar::Sidebar (){
    font.loadFromFile("/home/camut/CLionProjects/game/assets/fonts/sf-atarian-system/Atarian/SFAtarianSystem.ttf");
    hpText.setFont(font);
    hpText.setString("HP: 2/2");
    hpText.setCharacterSize(50);
    hpText.setFillColor(sf::Color::White);
    hpText.setPosition(80,50);
    weaponsText.setFont(font);
    weaponsText.setString("Weapons: 0");
    weaponsText.setCharacterSize(50);
    weaponsText.setFillColor(sf::Color::White);
    weaponsText.setPosition(80,100);

}

void Sidebar::draw(sf::RenderWindow& window) {
window.draw(hpText);
window.draw(weaponsText);
}

void Sidebar::updateHp(int hp) {
    hpText.setString("HP:"+ std::to_string(hp)+"/2");
}

void Sidebar::updateWeapons(int weapons) {
    weaponsText.setString("Weapons: "+ std::to_string(weapons));
}
