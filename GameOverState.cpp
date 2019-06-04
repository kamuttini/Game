//
// Created by camut on 03/06/19.
//

#include "GameOverState.h"
#include "GameState.h"
#include <string>

GameOverState::GameOverState(int score, GameDataRef data):  title("GAME OVER",150,sf::Color::Red),
                                                       enterText("press ENTER to replay",80, sf::Color::White),
                                                            scoreText("score: "+ std::to_string(score),70),
                                                       _data(data)

{

}
void GameOverState::Init() {
    WindowSize = this->_data->window.getSize();
    title.setPosition((this->_data->window.getSize().x/2)-(title.text.getGlobalBounds().width/2),(this->_data->window.getSize().y/2)-(title.text.getGlobalBounds().height/2));
    enterText.setPosition((this->_data->window.getSize().x/2)-(enterText.text.getGlobalBounds().width/2),(this->_data->window.getSize().y/2)-((title.text.getGlobalBounds().height/2)-200));
    scoreText.setPosition((this->_data->window.getSize().x/2)-(scoreText.text.getGlobalBounds().width/2),(this->_data->window.getSize().y/2)-((title.text.getGlobalBounds().height/2)+200));
}

void GameOverState::HandleInput() {
    sf::Event event;

    while (this->_data->window.pollEvent(event))
    {
        switch(event.type)
        {
            case sf::Event::Closed:
                this->_data->window.close();
                break;

            case sf::Event::KeyPressed:
                switch(event.key.code) {
                    case sf::Keyboard::Return:
                        this->_data->machine.AddState(StateRef(new GameState(_data)), true);
                        break;
                }
        }
    }
}

void GameOverState::Update() {

}


void GameOverState::Draw() {
    this->_data->window.clear();
    title.draw(this->_data->window);
    enterText.draw(this->_data->window);
    scoreText.draw(this->_data->window);
    this->_data->window.display();
}




//