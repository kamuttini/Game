//
// Created by camut on 26/05/19.
//

#ifndef GAME_ENEMY_H
#define GAME_ENEMY_H


#include "GameCharacter.h"
#include "Player.h"

class Enemy: public GameCharacter {
public:
    Enemy(Player* player);
    void fight();
    void destroy(std::vector<std::unique_ptr<Enemy>>& enemy,std::vector<std::unique_ptr<Enemy>>::const_iterator iter1);
    void updateState();
    std::vector<weaponPtr> weaponVec;

private:
    Factory weaponFactory;
    Player* player;
};


#endif //GAME_ENEMY_H
