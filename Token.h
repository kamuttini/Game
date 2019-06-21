//
// Created by Filippo Paolini on 2019-06-19.
//

#ifndef GAME_TOKEN_H
#define GAME_TOKEN_H

#include <SFML/Graphics.hpp>
#include "StaticComponent.h"

class Token: public StaticComponent {
public:
    enum type{token1,token2,token3};
    explicit Token(type id);
    ~Token(){};


private:
    type ID;

};


#endif //GAME_TOKEN_H
