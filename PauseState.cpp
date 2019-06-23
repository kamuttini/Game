//
// Created by Filippo Paolini on 2019-06-05.
//

#include "PauseState.h"
#include "GameState.h"
#include <string>
#include <fstream>

PauseState::PauseState(GameDataRef data) : title("Pause", 100, sf::Color::White),
                                           resumeText("Resume",60,sf::Color::Red),
                                           replayText("Restart",50),
                                           data(data) {}


void PauseState::Init() {
    this->data->soundTrack.setVolume(0);
    sf::Vector2u WindowSize = this->data->window.getSize();
    title.setPosition((this->data->window.getSize().x / 2) - (title.text.getGlobalBounds().width / 2),
                      (this->data->window.getSize().y / 2) - (title.text.getGlobalBounds().height / 2) -400);
    resumeText.setPosition((this->data->window.getSize().x / 2) - (resumeText.text.getGlobalBounds().width / 2),
                          (this->data->window.getSize().y / 2) - (title.text.getGlobalBounds().height / 2));
    replayText.setPosition((this->data->window.getSize().x / 2) - (replayText.text.getGlobalBounds().width / 2),
                          (this->data->window.getSize().y / 2) - ((title.text.getGlobalBounds().height / 2) - 100));
    view.setSize(sf::Vector2f(WINDOW_WIDTH,WINDOW_HEIGHT));
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
                    case sf::Keyboard::Down:
                        MoveDown();

                        break;
                    case sf::Keyboard::Up:
                        MoveUp();
                        break;
                    case sf::Keyboard::Return:
                        if(resumeText.text.getFillColor()==sf::Color::Red)
                        {
                            this->data->machine.RemoveState(true);
                            this->data->soundTrack.setVolume(SOUNDTRACK_VOLUME);
                        }
                        else
                        {
                            this->data->machine.AddState(StateRef(new GameState(data)), true);
                            this->data->soundTrack.setVolume(SOUNDTRACK_VOLUME);
                        }
                        break;

                }
        }
    }
}

void PauseState::Update() {

    }


void PauseState::Draw() {

    this->data->window.clear();
    view.setCenter(sf::Vector2f(WINDOW_WIDTH /2.0f, WINDOW_HEIGHT/2.0f));
    this->data->window.setView(view);
    title.draw(this->data->window);
    resumeText.draw(this->data->window);
    replayText.draw(this->data->window);
    this->data->window.display();
}

void PauseState::MoveUp() {
    SwapColor();
    SwapSize();
}

void PauseState::MoveDown() {
    SwapColor();
    SwapSize();
}

void PauseState::SwapColor(){
    sf::Color color1=resumeText.text.getFillColor();
    sf::Color color2=replayText.text.getFillColor();
    resumeText.text.setFillColor(color2);
    replayText.text.setFillColor(color1);
}

void PauseState::SwapSize() {
     int size1 =resumeText.text.getCharacterSize();
     int size2 =replayText.text.getCharacterSize();
     resumeText.text.setCharacterSize(size2);
     replayText.text.setCharacterSize(size1);
}
