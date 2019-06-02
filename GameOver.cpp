//
// Created by camut on 03/06/19.
//

#include "GameOver.h"

GameOver::GameOver(sf::RenderWindow& window1): window(window1) {

    WindowSize = window.getSize();

    font.loadFromFile("/home/camut/CLionProjects/game/assets/fonts/sf-atarian-system/Atarian/SFAtarianSystem.ttf");
    text.setFont(font);
    text.setString("GAME OVER");
    text.setCharacterSize(150);
    text.setFillColor(sf::Color::Red);
    text.setPosition((window.getSize().x/2)-(text.getGlobalBounds().width/2),(window.getSize().y/2)-(text.getGlobalBounds().height/2));

    enterText.setFont(font);
    enterText.setString("press ENTER to replay");
    enterText.setCharacterSize(80);
    enterText.setFillColor(sf::Color::White);
    enterText.setPosition((window.getSize().x/2)-(enterText.getGlobalBounds().width/2),(window.getSize().y/2)-(text.getGlobalBounds().height/2)+200);
}

void GameOver::draw(sf::RenderWindow &window) {
    window.draw(text);
    window.draw(enterText);
}
