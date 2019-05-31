//
// Created by camut on 29/05/19.
//

#ifndef GAME_SUBJECT_H
#define GAME_SUBJECT_H

#include <list>
#include "CollisionObserver.h"


class Subject {
public:
    Subject(){};
    virtual ~Subject(){};
    virtual void addObserver (CollisionObserver* o) = 0;
    virtual void removeObserver(CollisionObserver* o) = 0;
    virtual void notify() =0;

};


#endif //GAME_SUBJECT_H
