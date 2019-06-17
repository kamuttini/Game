//
// Created by camut on 03/06/19.
//

#ifndef GAME_GAMEOVERSTATE_H
#define GAME_GAMEOVERSTATE_H

#include <SFML/Graphics.hpp>
#include "Text.h"
#include "State.h"
#include "Game.h"

class GameOverState: public State {
public:
    GameOverState(int score, GameDataRef data);
    ~GameOverState(){};
    void Init() override ;
    void HandleInput() override ;
    void Update()  override;
    void Draw() override ;
    
protected:
    sf::View view;
    GameDataRef data;
    Text title;
    Text enterText;
    Text scoreText;
    Text bestScoreText;
    int score;
    int  highScore;
};


#endif //GAME_GAMEOVERSTATE_H
