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
    sf::View HUDview;
    TileMap layer[4];
    std::vector<Room*> room;
    Room* activeRoom;
    std::vector<Token> tok;
    GameDataRef data;
    HUD* hud;
    Player* player;
    int mapLevel;
};


#endif //GAME_GAMESTATE_H
