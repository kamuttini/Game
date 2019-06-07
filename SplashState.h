//
// Created by camut on 07/06/19.
//

#ifndef GAME_SPLASHSTATE_H
#define GAME_SPLASHSTATE_H


#include "State.h"
#include "Game.h"
#include "Text.h"

class SplashState: public State {
public:
    SplashState(GameDataRef data);
    ~SplashState(){};
    void Init() override ;
    void HandleInput() override ;
    void Update()  override;
    void Draw() override ;

private:
    GameDataRef data;
    sf::Texture texture;
    sf::Sprite img;
    Text titleText;
    Text skipText;
    sf::Clock clock;
    sf::Time splashTime;
};


#endif //GAME_SPLASHSTATE_H
