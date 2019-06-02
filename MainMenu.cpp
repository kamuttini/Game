//
// Created by camut on 02/06/19.
//

#include "MainMenu.h"

MainMenu::MainMenu(sf::RenderWindow& window1): window(window1) {
    texture.loadFromFile("/home/camut/CLionProjects/game/assets/morgagni.jpg");
    background.setTexture(texture);
    TextureSize = texture.getSize(); //Get size of texture.
    WindowSize = window.getSize();             //Get size of window.
    float ScaleX = (float) (WindowSize.x )/ TextureSize.x;
    float ScaleY = (float) (WindowSize.y )/ TextureSize.y;     //Calculate scale.

    background.setTexture(texture);
    background.setScale(ScaleX, ScaleY);
    font.loadFromFile("/home/camut/CLionProjects/game/assets/fonts/sf-atarian-system/Atarian/SFAtarianSystem.ttf");
    startText.setFont(font);
    startText.setString("UNIVERISTY SURVIVAL");
    startText.setCharacterSize(150);
    startText.setFillColor(sf::Color::Blue);
    startText.setPosition((window.getSize().x/2)-(startText.getGlobalBounds().width/2),(window.getSize().y/2)-(startText.getGlobalBounds().height/2));

    enterText.setFont(font);
    enterText.setString("press ENTER to start");
    enterText.setCharacterSize(80);
    enterText.setFillColor(sf::Color::Blue);
    enterText.setPosition((window.getSize().x/2)-(enterText.getGlobalBounds().width/2),(window.getSize().y/2)-(startText.getGlobalBounds().height/2)+200);

    rect.setSize(sf::Vector2f(1200,150));
    rect.setFillColor(sf::Color::White);
    rect.setPosition((window.getSize().x/2)-(rect.getGlobalBounds().width/2),(window.getSize().y/2)-(rect.getGlobalBounds().height/2)+50);
}

void MainMenu::draw(sf::RenderWindow &window) {
    window.draw(background);
    window.draw(rect);
    window.draw(startText);
    window.draw(enterText);
}

