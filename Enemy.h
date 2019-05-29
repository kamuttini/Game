//
// Created by camut on 26/05/19.
//

#ifndef GAME_ENEMY_H
#define GAME_ENEMY_H


#include "GameCharacter.h"
#include "Player.h"

class Enemy: public GameCharacter {
public:
    Enemy(Player* player1);
    void setPosition();
    void destroy(std::vector<std::unique_ptr<Enemy>>& enemy,std::vector<std::unique_ptr<Enemy>>::const_iterator iter1);
    void fight() override ;

private:
    Player* player;
    sf::Clock attackClock;
};


#endif //GAME_ENEMY_H
