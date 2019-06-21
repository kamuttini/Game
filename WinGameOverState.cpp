//
// Created by camut on 21/06/19.
//

#include "WinGameOverState.h"
#include "Def.h"

WinGameOverState::WinGameOverState(int score, GameDataRef data):    GameOverState(score, data),
                                                                    reward("INSERISCA VOTO ESAME:",60, sf::Color::Red),
                                                                    playerText("_",60),
                                                                    change(false),
                                                                    active(true)
{}

void WinGameOverState::Init() {
    title.text.setString("You Win!");
    reward.setPosition(450,300);
    playerText.setPosition(700,400);
    GameOverState::Init();
}


void WinGameOverState::Draw() {
    if(change)
    GameOverState::Draw();
    else
    {
        this->data->window.clear();
        view.setCenter(sf::Vector2f(WINDOW_WIDTH /2.0f, WINDOW_HEIGHT/2.0f));
        this->data->window.setView(view);
        if(display.getElapsedTime()<sf::seconds(0.5) && active)
            playerText.draw(this->data->window);
        else
            { if (active) {
                displayNot.restart();
                active = false;
            }
            else
                if(displayNot.getElapsedTime()>sf::seconds(0.5))
                {
                    active=true;
                    display.restart();
                }
        }
        reward.draw(this->data->window);
        this->data->window.display();
    }
}

void WinGameOverState::HandleInput() {
    if(change)
    GameOverState::HandleInput();
    else{
        sf::Event event;

        while (this->data->window.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                    this->data->window.close();
                    break;
                case sf::Event::TextEntered:
                        playerInput +=event.text.unicode;
                        playerText.text.setString(playerInput+"_");
                        break;
                case sf::Event::KeyPressed:
                    switch(event.key.code) {
                        case sf::Keyboard::Return:
                            change=true;
                            break;
                    }
            }
        }

    }

}
