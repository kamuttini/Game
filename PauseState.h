//
// Created by Filippo Paolini on 2019-06-05.
//

#ifndef GAME_PAUSESTATE_H
#define GAME_PAUSESTATE_H

#include <SFML/Graphics.hpp>
#include "Text.h"
#include "State.h"
#include "Game.h"




#endif //GAME_PAUSESTATE_H


class PauseState: public State {

public:
    explicit PauseState(GameDataRef data);
    ~PauseState()= default;;
    void Init() override ;
    void HandleInput() override ;
    void Update()  override;
    void Draw() override ;
    void MoveUp();
    void MoveDown();
    void SwapColor();
    void SwapSize();

protected:
    sf::View view;
    GameDataRef data;
    Text title;
    Text resumeText;
    Text replayText;
};