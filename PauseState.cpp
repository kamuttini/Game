//
// Created by Filippo Paolini on 2019-06-05.
//

#include "PauseState.h"
#include "GameState.h"
#include <string>
#include <fstream>

PauseState::PauseState(GameDataRef data) : data(data)
{

}


void PauseState::Init() {
    sf::Vector2u WindowSize = this->data->window.getSize();
}

void PauseState::HandleInput() {
    sf::Event event;

    while (this->data->window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                this->data->window.close();
                break;
            case sf::Event::KeyPressed:
                this->data->machine.RemoveState();

        }
    }
}

void PauseState::Update() {

    }


void PauseState::Draw() {

    this->data->window.clear();
    this->data->window.display();
}
