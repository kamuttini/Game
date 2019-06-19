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
                                            room{Room(Room::type::hall),Room(Room::type::canteen),Room(Room::type::classroom1),Room(Room::type::bar),Room(Room::type::classroom2)}
                                           {}

void GameState::Init()
{
    view.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
    HUDview.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
    hud= new HUD();
    player=new Player(*hud);
    data->soundTrack.play();
    view.setCenter(player->getRect().getPosition());
    this->data->window.setView(view);
    profs.push_back(Professor("prof1.png", PROF1_POSITION));
    profs.push_back(Professor("prof2.png", PROF2_POSITION));
    profs.push_back(Professor("prof3.png", PROF3_POSITION));
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
    for(int i=0; i<5; i++)
        for(int j=0; j<room[i].enemyVec.size(); j++)
            for(int k=0; k< room[i].enemyVec[j]->weaponVec.size(); k++)
                if(activeRoom!=&room[i])
                    room[i].enemyVec[j]->weaponVec[k]->attack();

    if(player->isDestroyed()){                                                                                         //end game
        this->data->machine.AddState(StateRef(new GameOverState(hud->getScore(), this->data)), true);
    }
}

void GameState::Draw()
{
    this->data->window.clear(sf::Color (123, 173, 44));
    sf::Vector2f movement = player->getRect().getPosition() - view.getCenter();
    view.move(movement.x*0.2,movement.y*0.2);
    this->data->window.setView(view);

    for(int i=0;  i<4;i++)
        this->data->window.draw(layer[i]);

    this->data->window.draw(activeRoom->rect);
    for(int k=0; k<5; k++)
    {
        int i, j;
        for (i = 0; i < room[k].enemyVec.size(); i++) {
            room[k].enemyVec[i]->draw(this->data->window);
            for (j = 0; j < room[k].enemyVec[i]->weaponVec.size(); j++)
                room[k].enemyVec[i]->weaponVec[j]->draw(this->data->window);
        }

        for (i = 0; i < room[k].weaponToCollect.size(); i++)
            room[k].weaponToCollect[i]->draw(this->data->window);
    }
    for (int i = 0; i < player->inventory.weaponVec.size(); i++)
        player->inventory.weaponVec[i]->draw(this->data->window);

    for(int i=0; i<profs.size(); i++)
    profs[i].draw(this->data->window);

    player->draw(this->data->window);


    this->data->window.setView(HUDview);

    hud->draw(this->data->window);
    if(player->inventory.alert.isDisplay())
    {
        player->inventory.alert.draw(this->data->window);
        player->inventory.alert.stopDisplaying();
    }

    this->data->window.display();

}

void GameState::checkRoom() {
    bool find=false;
    for(int i=1;  i<5;i++)
        if (room[i].rect.getGlobalBounds().intersects(player->getRect().getGlobalBounds())) {
            activeRoom = &room[i];
            find=true;
        }
        if(!find)
        activeRoom = &room[0];

}


