//
// Created by camut on 29/05/19.
//

#ifndef GAME_SUBJECT_H
#define GAME_SUBJECT_H

#include <list>
#include "collisionObserver.h"


class Subject {
public:
    Subject(){};
    virtual ~Subject(){};
    virtual void addObserver (collisionObserver* o) = 0;
    virtual void removeObserver(collisionObserver* o) = 0;
    virtual void notify() const=0;

};


#endif //GAME_SUBJECT_H
