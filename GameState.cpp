//
// Created by camut on 04/06/19.
//

#include "GameState.h"
#include "GameOverState.h"
#include "PauseState.h"
#include <iostream>
#include "Def.h"
class Enemy;
GameState::GameState(GameDataRef data1) :   data(data1),
                                            layer{TileMap("map1.txt"),TileMap("map2.txt"),TileMap("map3.txt"), TileMap("map4.txt")},
                                            room{Room(Room::type::canteen),Room(Room::type::hall),Room(Room::type::classroom1),Room(Room::type::bar),Room(Room::type::classroom2)}
                                           {}

void GameState::Init()
{
    view.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
    HUDview.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
    sidebar= new HUD();
    player=new Player(*sidebar);
    data->soundTrack.play();
    view.setCenter(player->getRect().getPosition());
    this->data->window.setView(view);
}

void GameState::HandleInput()
{
    sf::Event event;

    while (this->data->window.pollEvent(event))
    {
        switch(event.type)
        {
            case sf::Event::KeyPressed:

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)){
                    this->data->machine.AddState(StateRef(new PauseState(data)));
                } else
                    player->getInput();
                break;

            case sf::Event::Closed:
                this->data->window.close();
                break;
        }
    }
}

void GameState::Update()
{

    checkRoom();
    player->updateState();

    activeRoom->update(player);

    if(player->isDestroyed()){                                                                                         //end game
        this->data->machine.AddState(StateRef(new GameOverState(sidebar->getScore(), this->data)), true);
    }
}

void GameState::Draw()
{
    this->data->window.clear();
    sf::Vector2f movement = player->getRect().getPosition() - view.getCenter();
    view.move(movement.x*0.2,movement.y*0.2);
    this->data->window.setView(view);

    for(int i=0;  i<4;i++)
        this->data->window.draw(layer[i]);

    this->data->window.draw(activeRoom->rect);
    int i,j;
    for (i = 0; i < activeRoom->enemyVec.size(); i++){
        activeRoom->enemyVec[i]->draw(this->data->window);
        for (j = 0; j < activeRoom->enemyVec[i]->weaponVec.size(); j++)
            activeRoom->enemyVec[i]->weaponVec[j]->draw(this->data->window);
    }

    for (i = 0; i < activeRoom->weaponToCollect.size(); i++)
        activeRoom->weaponToCollect[i]->draw(this->data->window);

    for (i = 0; i < player->inventory.weaponVec.size(); i++)
        player->inventory.weaponVec[i]->draw(this->data->window);

    if(player->inventory.alert.isDisplay())
    {
        player->inventory.alert.draw(this->data->window);
        player->inventory.alert.stopDisplaying();
    }

    player->draw(this->data->window);
    this->data->window.setView(HUDview);

    sidebar->draw(this->data->window);

    this->data->window.display();

}

void GameState::checkRoom() {
    for(int i=0;  i<5;i++)
       if(room[i].rect.getGlobalBounds().intersects(player->getRect().getGlobalBounds()))
           activeRoom=&room[i];

}

