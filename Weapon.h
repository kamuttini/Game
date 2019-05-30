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

    Weapon (std::list<CollisionObserver*>& targetList, orientation targetDir, sf::Vector2f vector, int s=7);
    void attack();
    void addObserver(CollisionObserver* o) override ;
    void removeObserver(CollisionObserver* o) override;
    void notify() const override;

protected:
    std::list<CollisionObserver*> characters;
};


#endif //GAME_WEAPON_H
