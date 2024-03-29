//
// Created by camut on 02/06/19.
//

#include "MenuState.h"
#include "SplashState.h"


MenuState::MenuState(GameDataRef data1): titleText("UNIVERSITY SURVIVAL",150, sf::Color::Blue),
                                        enterText("press ENTER to start",80, sf::Color::Blue),
                                        data(data1){}

void MenuState::Init() {
    sf::Vector2u TextureSize;
    sf::Vector2u WindowSize;
    texture.loadFromFile("assets/sprites/morgagni.jpg");
    background.setTexture(texture);
    TextureSize = texture.getSize(); //Get size of texture.
    WindowSize = this->data->window.getSize();             //Get size of window.
    float ScaleX = (float) (WindowSize.x )/ TextureSize.x;
    float ScaleY = (float) (WindowSize.y )/ TextureSize.y;     //Calculate scale.

    background.setTexture(texture);
    background.setScale(ScaleX, ScaleY);
    titleText.setPosition((this->data->window.getSize().x/2)-(titleText.text.getGlobalBounds().width/2),(this->data->window.getSize().y/2)-(titleText.text.getGlobalBounds().height/2));
    enterText.setPosition((this->data->window.getSize().x/2)-(enterText.text.getGlobalBounds().width/2),(this->data->window.getSize().y/2)-(titleText.text.getGlobalBounds().height/2)+200);

    rect.setSize(sf::Vector2f(1200,150));
    rect.setFillColor(sf::Color::White);
    rect2.setSize(sf::Vector2f(600,90));
    rect2.setFillColor(sf::Color::White);
    rect.setPosition((this->data->window.getSize().x/2)-(rect.getGlobalBounds().width/2),(this->data->window.getSize().y/2)-(rect.getGlobalBounds().height/2)+50);
    rect2.setPosition((this->data->window.getSize().x/2)-(rect2.getGlobalBounds().width/2),(this->data->window.getSize().y/2)-(rect2.getGlobalBounds().height/2)+200);
}



void MenuState::HandleInput() {
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
                    case sf::Keyboard::Return:
                        this->data->machine.AddState(StateRef(new SplashState(data)), true);
                        break;
                    default:
                        break;
                }
            default:
                break;
        }
    }
}

void MenuState::Update() {

}



void MenuState::Draw() {
    this->data->window.clear();
    this->data->window.draw(background);
    this->data->window.draw(rect);
    this->data->window.draw(rect2);
    titleText.draw(this->data->window);
    enterText.draw(this->data->window);
    this->data->window.display();
}


