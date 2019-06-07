//
// Created by camut on 07/06/19.
//

#include "SplashState.h"
#include "GameState.h"

SplashState::SplashState(GameDataRef data1):    titleText("player moves with",60),
                                                skipText("press spacebar to skip",30),
                                                data(data1){}

void SplashState::Init() {
    splashTime= sf::seconds(2.5);
    texture.loadFromFile("assets/sprites/wasd.png");
    img.setTexture(texture);

    img.setTexture(texture);
    img.setScale(0.6,0.6);
    img.setPosition((this->data->window.getSize().x/2)-(img.getGlobalBounds().width/2),(this->data->window.getSize().y/2)-(img.getGlobalBounds().height/2));
    titleText.setPosition((this->data->window.getSize().x/2)-(titleText.text.getGlobalBounds().width/2),(img.getPosition().y-110));
    skipText.setPosition((this->data->window.getSize().x/2)-(skipText.text.getGlobalBounds().width/2)+400,(this->data->window.getSize().y/2)-(skipText.text.getGlobalBounds().height/2)+300);

}

void SplashState::HandleInput() {
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
                    case sf::Keyboard::Space:
                        this->data->machine.AddState(StateRef(new GameState(data)), true);
                        break;
                }
        }
    }
}

void SplashState::Update() {
    if(clock.getElapsedTime()>splashTime)
        this->data->machine.AddState(StateRef(new GameState(data)), true);
}



void SplashState::Draw() {
    this->data->window.clear();
    this->data->window.draw(img);
    titleText.draw(this->data->window);
    skipText.draw(this->data->window);
    this->data->window.display();
}