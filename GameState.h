//
// Created by camut on 04/06/19.
//

#ifndef GAME_GAMESTATE_H
#define GAME_GAMESTATE_H

#include "Def.h"
#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include "TileMap.h"
#include "Def.h"
#include "Room.h"
#include <SFML/Graphics.hpp>


class GameState: public State {
public:

    GameState(GameDataRef data);
    ~GameState(){};
    void Init() override ;
    void HandleInput() override ;
    void Update()  override;
    void Draw() override ;
    void checkRoom();

private:
    sf::View view;
    TileMap layer[4];
    Room room[4];
    Room* activeRoom;
    GameDataRef data;
    Sidebar* sidebar;
    Player* player;

};


#endif //GAME_GAMESTATE_H
