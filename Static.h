//
// Created by camut on 07/06/19.
//

#ifndef GAME_STATIC_H
#define GAME_STATIC_H


#include "Strategy.h"

class Static: public Strategy {
public:
    Static()= default;
    ~Static()= default;
    void move(Enemy& enemy, Player &player) override{} ;
};


#endif //GAME_STATIC_H
