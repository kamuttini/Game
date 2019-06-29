//
// Created by camut on 02/06/19.
//

#ifndef GAME_MENUSTATE_H
#define GAME_MENUSTATE_H

#include <SFML/Graphics.hpp>
#include "Text.h"
#include "State.h"
#include "Game.h"


class MenuState: public State {
public:
    explicit MenuState(GameDataRef data);
    ~MenuState()= default;;
    void Init() override ;
    void HandleInput() override ;
    void Update()  override;
    void Draw() override ;

private:
    GameDataRef data;
    sf::RectangleShape rect;
    sf::RectangleShape rect2;
    sf::Texture texture;
    sf::Sprite background;
    Text titleText;
    Text enterText;
};

#endif //GAME_MENUSTATE_H
