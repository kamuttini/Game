//
// Created by camut on 28/06/19.
//

#include "PlayerObserver.h"

#ifndef GAME_BADGESUBJECT_H
#define GAME_BADGESUBJECT_H

#endif //GAME_BADGESUBJECT_H

class Subject {
public:
    Subject()= default;
    virtual ~Subject(){};
    virtual void addObserver (PlayerObserver* o) = 0;
    virtual void removeObserver(PlayerObserver* o) = 0;
    virtual void notify() =0;

};
