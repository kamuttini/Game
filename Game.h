//
// Created by camut on 25/05/19.
//

#ifndef GAME_GAME_H
#define GAME_GAME_H

#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "StateMachine.h"


    struct GameData
    {
        StateMachine machine;
        sf::RenderWindow window;
        sf::Music soundTrack;
    };


    typedef std::shared_ptr<GameData> GameDataRef;

class Game {
public:
    Game(int width, int height, std::string title);
    ~Game(){};

private:
    void Run();
    GameDataRef data;

};


#endif //GAME_GAME_H
