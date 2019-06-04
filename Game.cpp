//
// Created by camut on 25/05/19.
//

#include "Game.h"
#include "MenuState.h"



Game::Game(int width, int height, std::string title)

{
    _data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
    _data->window.setFramerateLimit(60);
    _data->machine.AddState(StateRef(new MenuState(this->_data)));

    _data->soundTrack.openFromFile("assets/music/mario.wav");
    _data->soundTrack.setVolume(10);

    this->Run();
}

void Game::Run()
{

    while (this->_data->window.isOpen())
    {
        this->_data->machine.ProcessStateChanges();
        this->_data->machine.GetActiveState()->HandleInput();
        this->_data->machine.GetActiveState()->Update();
        this->_data->machine.GetActiveState()->Draw();
    }
}

/*void Game::stop() {
    gameOver=new GameOverState(window,sidebar->getScore());

    for(int i=0; i<enemyVec.size(); i++)
    {
        for(int j=0; j< enemyVec[i]->weaponVec.size(); j++)
        {
            enemyVec[i]->weaponVec.clear();
        }
    }
    enemyVec.clear();
    weaponToCollect.clear();
    delete(player);
    delete(sidebar);
    player= nullptr;
    sidebar=nullptr;

    while (window.isOpen())
    {
        ProcessEvent();
        window.clear();
        gameOver->draw(window);
        window.display();
    }

}*/
