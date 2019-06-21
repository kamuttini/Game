//
// Created by camut on 20/06/19.
//

#ifndef GAME_CLASSROOM_H
#define GAME_CLASSROOM_H


#include "Room.h"
#include "Professor.h"
#include "Token.h"

class ClassRoom: public Room {
public:
    explicit ClassRoom(type ID);
    ~ClassRoom() {};
    bool activeUpdate(Player &player) override;
    void draw(sf::RenderWindow &window) override;

private:
    Professor *professor;
    Token *token;
    bool completed;
};

#endif //GAME_CLASSROOM_H
