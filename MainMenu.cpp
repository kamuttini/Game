//
// Created by camut on 02/06/19.
//

#include "MainMenu.h"
MainMenu::MainMenu(sf::RenderWindow& window1):  window(window1),
                                                titleText("UNIVERSITY SURVIVAL",150, sf::Color::Blue),
                                                enterText("press ENTER to start",80, sf::Color::Blue)
{
    texture.loadFromFile("assets/morgagni.jpg");
    background.setTexture(texture);
    TextureSize = texture.getSize(); //Get size of texture.
    WindowSize = window.getSize();             //Get size of window.
    float ScaleX = (float) (WindowSize.x )/ TextureSize.x;
    float ScaleY = (float) (WindowSize.y )/ TextureSize.y;     //Calculate scale.

    background.setTexture(texture);
    background.setScale(ScaleX, ScaleY);
    titleText.setPosition((window.getSize().x/2)-(titleText.text.getGlobalBounds().width/2),(window.getSize().y/2)-(titleText.text.getGlobalBounds().height/2));
    enterText.setPosition((window.getSize().x/2)-(enterText.text.getGlobalBounds().width/2),(window.getSize().y/2)-(titleText.text.getGlobalBounds().height/2)+200);

    rect.setSize(sf::Vector2f(1200,150));
    rect.setFillColor(sf::Color::White);
    rect2.setSize(sf::Vector2f(600,90));
    rect2.setFillColor(sf::Color::White);
    rect.setPosition((window.getSize().x/2)-(rect.getGlobalBounds().width/2),(window.getSize().y/2)-(rect.getGlobalBounds().height/2)+50);
    rect2.setPosition((window.getSize().x/2)-(rect2.getGlobalBounds().width/2),(window.getSize().y/2)-(rect2.getGlobalBounds().height/2)+200);

}

void MainMenu::draw(sf::RenderWindow &window) {
    window.draw(background);
    window.draw(rect);
    window.draw(rect2);
    titleText.draw(window);
    enterText.draw(window);
}

