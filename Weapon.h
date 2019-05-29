//
// Created by camut on 24/05/19.
//

#ifndef GAME_WEAPON_H
#define GAME_WEAPON_H

#include "DynamicComponent.h"
#include "Subject.h"


class Weapon: public DynamicComponent, public Subject  {
    enum id {cafe, pasta, book};

public:
    Weapon (orientation targetDir, sf::Vector2f vector, int s=7);
    void attack();
    void addObserver(collisionObserver* o) override ;
    void removeObserver(collisionObserver* o) override;
    void notify() const override;

    // void makeSound();

protected:
    std::list<collisionObserver*> characters;
    // int damage;
    //id ID;
};


#endif //GAME_WEAPON_H
