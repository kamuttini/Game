//
// Created by camut on 25/05/19.
//

#include "Game.h"
#include "MenuState.h"
#include "Def.h"


Game::Game(int width, int height, std::string title)

{
    data=std::make_shared<GameData>();
    data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
    data->window.setFramerateLimit(FRAME);
    data->machine.AddState(StateRef(new MenuState(this->data)));

    data->soundTrack.openFromFile("assets/music/Gerudo_Valley-The_Legend_of_Zelda-Ocarina_of_Time.wav");
    data->soundTrack.setVolume(SOUNDTRACK_VOLUME);
    data->soundTrack.setLoop(true);

    this->Run();
}

void Game::Run()
{
    while (this->data->window.isOpen())
    {
        this->data->machine.ProcessStateChanges();
        this->data->machine.GetActiveState()->HandleInput();
        this->data->machine.GetActiveState()->Update();
        this->data->machine.GetActiveState()->Draw();
    }
}


