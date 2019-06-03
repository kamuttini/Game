//
// Created by camut on 03/06/19.
//

#include "GameOver.h"
#include <string>

GameOver::GameOver(sf::RenderWindow& window1, int score):  window(window1),
                                                title("GAME OVER",150,sf::Color::Red),
                                                enterText("press ENTER to replay",80, sf::Color::White),
                                                scoreText("score: "+ std::to_string(score),70)
{
    WindowSize = window.getSize();
    title.setPosition((window.getSize().x/2)-(title.text.getGlobalBounds().width/2),(window.getSize().y/2)-(title.text.getGlobalBounds().height/2));
    enterText.setPosition((window.getSize().x/2)-(enterText.text.getGlobalBounds().width/2),(window.getSize().y/2)-((title.text.getGlobalBounds().height/2)-200));
    scoreText.setPosition((window.getSize().x/2)-(scoreText.text.getGlobalBounds().width/2),(window.getSize().y/2)-((title.text.getGlobalBounds().height/2)+200));
}

void GameOver::draw(sf::RenderWindow &window) {
    title.draw(window);
    enterText.draw(window);
    scoreText.draw(window);
}
