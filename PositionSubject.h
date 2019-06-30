//
// Created by camut on 30/06/19.
//

#ifndef GAME_POSITIONSUBJECT_H
#define GAME_POSITIONSUBJECT_H

class PositionObserver;
class PositionSubject {
public:
    PositionSubject()= default;;
    virtual ~PositionSubject()= default;;
    virtual void addPositionObserver (PositionObserver* o) = 0;
    virtual void removePositionObserver(PositionObserver* o) = 0;
    virtual void notifyPosition() =0;

};
#endif //GAME_POSITIONSUBJECT_H
