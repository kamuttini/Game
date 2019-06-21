//
// Created by camut on 21/06/19.
//

#ifndef GAME_WINGAMEOVERSTATE_H
#define GAME_WINGAMEOVERSTATE_H


#include "GameOverState.h"

class WinGameOverState: public GameOverState {
public:
    WinGameOverState(int score, GameDataRef data);
    ~WinGameOverState(){};
    void Init() override ;
    void HandleInput() override ;
    void Draw() override ;

private:
    bool change;
    bool active;
    Text playerText;
    Text reward;
    sf::String playerInput;
    sf::Clock displayNot;
    sf::Clock display;

};


#endif //GAME_WINGAMEOVERSTATE_H
