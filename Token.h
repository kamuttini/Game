//
// Created by Filippo Paolini on 2019-06-19.
//

#ifndef GAME_TOKEN_H
#define GAME_TOKEN_H

#include <SFML/Graphics.hpp>
#include "StaticComponent.h"

class Token: public StaticComponent {
public:
    enum type{calculator,license,computer};
    explicit Token(type id);
    ~Token(){};
    bool isActive() const;
    void setActive(bool active);

private:
    type ID;
    bool active;
};


#endif //GAME_TOKEN_H
