//
// Created by camut on 19/06/19.
//

#ifndef GAME_PROFESSOR_H
#define GAME_PROFESSOR_H


#include "StaticComponent.h"

class Professor: public StaticComponent {
public:
    Professor(std::string filename, sf::Vector2f position);
    ~Professor(){};
};


#endif //GAME_PROFESSOR_H
