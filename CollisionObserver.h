//
// Created by camut on 29/05/19.
//

#ifndef GAME_COLLISIONOBSERVER_H
#define GAME_COLLISIONOBSERVER_H


#include "Weapon.h"

class Weapon;

class CollisionObserver {
public:
    CollisionObserver()= default;;
    virtual ~CollisionObserver()= default;;
    virtual void update(Weapon* weapon)=0;

};


#endif //GAME_COLLISIONOBSERVER_H
