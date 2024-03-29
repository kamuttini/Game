//
// Created by camut on 04/06/19.
//

#include "GameState.h"
#include "GameOverState.h"
#include "PauseState.h"
#include <iostream>
#include "Def.h"
#include "ClassRoom.h"
#include "WinGameOverState.h"

class Enemy;
GameState::GameState(GameDataRef data1) :   data(data1),
                                            layer{TileMap("map1.txt"),TileMap("map2.txt"),TileMap("map3.txt"), TileMap("map4.txt")},
                                            mapLevel(0)
                                           {}

void GameState::Init()
{
    hud=std::make_unique<HUD> ();
    player=std::make_unique<Player>();
    player->addPositionObserver(&map);
    player->addObserver(hud.get());
    view.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
    HUDview.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
    data->soundTrack.play();
    view.setCenter(player->getPosition());
    this->data->window.setView(view);
    room.push_back(std::make_unique<Room>(Room::type::hall));
    room.push_back(std::make_unique<Room>(Room::type::canteen));
    room.push_back(std::make_unique<Room>(Room::type::bar));
    room.push_back(std::make_unique<ClassRoom>(Room::type::classroom1, map));
    room.push_back(std::make_unique<ClassRoom>(Room::type::classroom2, map));
    room.push_back(std::make_unique<ClassRoom>(Room::type::classRoom3, map));
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

            default:
                break;
        }
    }
}

void GameState::Update()
{

    checkRoom();
    player->updateState();

    if(activeRoom->activeUpdate(*player)) {
        switch (mapLevel) {
            case 0:
                layer[1] = TileMap("map2_v2.txt");
                dynamic_cast<ClassRoom *>(room[4].get())->getProfessor()->notifyPosition();
                break;
            case 1:
                layer[1] = TileMap("map2_v3.txt");
                dynamic_cast<ClassRoom *>(room[5].get())->getProfessor()->notifyPosition();
                break;
            case 2:
                Draw();
                sf::sleep(sf::seconds(2));
                this->data->machine.AddState(StateRef(new WinGameOverState(hud->getScore(), this->data)), true);
                break;
        }
        mapLevel+=1;
    }


    for(auto & i : room)
        if(activeRoom!=i.get())
            i.get()->update();

    if(player->isDestroyed()){                                                                                         //end game
        this->data->machine.AddState(StateRef(new GameOverState(hud->getScore(), this->data)), true);
    }
}

void GameState::Draw() {
    this->data->window.clear(BACKGROUNDCOLOR);
    sf::Vector2f movement = player->getPosition() - view.getCenter();
    view.move(movement.x * 0.1, movement.y * 0.1);
    this->data->window.setView(view);

    for (const auto & i : layer)
        this->data->window.draw(i);

    for(auto & i : room)
    {
        i->draw(this->data->window);
    }
    for (auto & i : player->inventory.weaponVec)
        i->draw(this->data->window);


    player->draw(this->data->window);
    for(auto & i : room)
    {
        i->draw(this->data->window);
    }
    this->data->window.setView(HUDview);

    hud->draw(this->data->window);
    if (player->inventory.alert.isDisplay()) {
        player->inventory.alert.draw(this->data->window);
        player->inventory.alert.stopDisplaying();
    }
    map.draw(this->data->window);

    this->data->window.display();
}


void GameState::checkRoom() {
    bool find=false;
    for(int i=1;  i<room.size();i++)
        if (room[i]->getRect().getGlobalBounds().intersects(player->getRect().getGlobalBounds())) {
            activeRoom =room[i].get();
            find=true;
        }
        if(!find)
        activeRoom = room[0].get();
}


