//
// Created by camut on 04/06/19.
//

#ifndef GAME_STATE_H
#define GAME_STATE_H

class State {
public:
    virtual void Init() = 0;

    virtual void HandleInput() = 0;

    virtual void Update() = 0;

    virtual void Draw() = 0;

    virtual void Pause() {}

    virtual void Resume() {}
};


#endif //GAME_STATE_H
