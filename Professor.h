//
// Created by camut on 19/06/19.
//

#ifndef GAME_PROFESSOR_H
#define GAME_PROFESSOR_H


#include "StaticComponent.h"
#include "Token.h"
#include "Text.h"
#include "Player.h"

class Professor: public StaticComponent {
public:
    enum type {prof1,prof2,prof3};

    explicit Professor(type id);
    ~Professor(){};


    bool checkToken(Player& player);
    void talk();
    bool isTalking();
    void stopTalking();
    sf::Sprite message;
    Token *getToken() const;

private:
    type ID;
    bool talking;
    sf::Texture mTexture;
    sf::Clock displayClock;
    sf::Time displayTime;
    Token* token;
};


#endif //GAME_PROFESSOR_H
