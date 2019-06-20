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
    void setDirection(Enemy &enemy, Player &player) override;
};

void Static::setDirection(Enemy &enemy, Player &player) {
 enemy.setDirection(StaticComponent::orientation::null);
}


#endif //GAME_STATIC_H
