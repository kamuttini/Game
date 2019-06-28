//
// Created by Filippo Paolini on 2019-06-19.
//

#ifndef GAME_TOKEN_H
#define GAME_TOKEN_H

#include <SFML/Graphics.hpp>
#include "StaticComponent.h"
#include "Player.h"

class Token: public StaticComponent {
public:
    enum type{calculator,license,computer};
    explicit Token(type id);
    ~Token()= default;
    bool isActive() const;
    void setActive(bool active, Player* player= nullptr);
    void update();
    bool isCaught() const;

private:
    void attachToPlayer();

    Player* player;
    type ID;
    bool active;
    bool caught;

};


#endif //GAME_TOKEN_H
