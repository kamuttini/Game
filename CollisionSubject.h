//
// Created by camut on 29/05/19.
//

#ifndef GAME_COLLISIONSUBJECT_H
#define GAME_COLLISIONSUBJECT_H

#include <list>
#include "CollisionObserver.h"


class CollisionSubject {
public:
    CollisionSubject()= default;
    virtual ~CollisionSubject(){};
    virtual void addObserver (CollisionObserver* o) = 0;
    virtual void removeObserver(CollisionObserver* o) = 0;
    virtual void notify() =0;

};


#endif //GAME_COLLISIONSUBJECT_H
