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
#include "Professor.h"
#include "Token.h"
#include "HUD.h"
#include "Map.h"
#include <SFML/Graphics.hpp>


class GameState: public State {
public:
    GameState(GameDataRef data);
    ~GameState(){};
    void Init() override ;
    void HandleInput() override ;
    void Update()  override;
    void Draw() override ;

private:
    void checkRoom();

    sf::View view;
    sf::View HUDview;
    TileMap layer[nLAYERS];
    Map map;
    std::vector<std::unique_ptr<Room>> room;
    Room* activeRoom;
    GameDataRef data;
    std::unique_ptr<Player> player;
    std::unique_ptr<HUD> hud;
    int mapLevel;
};


#endif //GAME_GAMESTATE_H
