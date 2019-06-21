//
// Created by camut on 19/06/19.
//

#ifndef GAME_PROFESSOR_H
#define GAME_PROFESSOR_H


#include "StaticComponent.h"
#include "Token.h"

class Professor: public StaticComponent {
public:
    enum type {prof1,prof2,prof3};

    explicit Professor(type id);
    ~Professor(){};


    bool checkToken();
    void talk();

private:
    type ID;
   // Token& token;
};


#endif //GAME_PROFESSOR_H
