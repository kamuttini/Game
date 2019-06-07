//
// Created by Filippo Paolini on 2019-06-05.
//

#include "PauseState.h"
#include "GameState.h"
#include <string>
#include <fstream>

PauseState::PauseState(GameDataRef data) : title("Pause", 100, sf::Color::White),
                                           enterText("press P to Return",50,sf::Color::Red),
                                           data(data)
{

}


void PauseState::Init() {
    sf::Vector2u WindowSize = this->data->window.getSize();
    title.setPosition((this->data->window.getSize().x/2)-(title.text.getGlobalBounds().width/2),(this->data->window.getSize().y/2)-(title.text.getGlobalBounds().height/2));
    enterText.setPosition((this->data->window.getSize().x/2)-(enterText.text.getGlobalBounds().width/2),(this->data->window.getSize().y/2)-((title.text.getGlobalBounds().height/2)-200));
}

void PauseState::HandleInput() {
    sf::Event event;


    while (this->data->window.pollEvent(event))
    {
        switch(event.type)
        {
            case sf::Event::Closed:
                this->data->window.close();
                break;

            case sf::Event::KeyPressed:
                switch(event.key.code) {
                    case sf::Keyboard::P:
                        this->data->machine.RemoveState();
                        break;
                    case sf::Keyboard::R:
                        this->data->machine.AddState(StateRef(new GameState(data)), true);
                        break;

                }
        }
    }
}

void PauseState::Update() {

    }


void PauseState::Draw() {

    this->data->window.clear();
    title.draw(this->data->window);
    enterText.draw(this->data->window);
    this->data->window.display();
}
