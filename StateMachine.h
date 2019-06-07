//
// Created by camut on 04/06/19.
//

#ifndef GAME_STATEMACHINE_H
#define GAME_STATEMACHINE_H

#include <memory>
#include <stack>
#include "State.h"

typedef std::unique_ptr<State> StateRef;

class StateMachine
{
public:

    StateMachine() { }
    ~StateMachine() { }

    void AddState(StateRef newState, bool isReplacing = true);
    void RemoveState();

    // Run at start of each loop in Game.cpp
    void ProcessStateChanges();

    StateRef &GetActiveState();

private:
    std::stack<StateRef> states;
    StateRef newState;

    bool isRemoving;
    bool isAdding, isReplacing;
};

#endif //GAME_STATEMACHINE_H
