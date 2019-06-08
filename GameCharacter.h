//
// Created by camut on 24/05/19.
//

#ifndef GAME_GAMECHARACTER_H
#define GAME_GAMECHARACTER_H

#include "DynamicComponent.h"
#include "Weapon.h"
#include "Factory.h"


class GameCharacter: public DynamicComponent,public CollisionObserver{

public:
     GameCharacter(int s=15 ,int h=2);
    typedef std::unique_ptr<Weapon>  weaponPtr;

    void update(Weapon* weapon) override =0;
    virtual void fight()=0;
    virtual void move()=0;
    virtual void updateState();
    std::list<CollisionObserver*> targetList;


protected:
    int hp;
    bool wounded;
    bool isFighting;
    sf::Clock attackClock;
    sf::Time attackDelay;
    sf::Clock woundedClock;
    sf::Clock walkingClock;
    sf::Time walkingDelay;
};
#endif //GAME_GAMECHARACTER_H
