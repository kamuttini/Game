//
// Created by camut on 24/05/19.
//

#ifndef GAME_GAMECHARACTER_H
#define GAME_GAMECHARACTER_H

#include "DynamicComponent.h"
#include "Weapon.h"

class GameCharacter: public DynamicComponent,public CollisionObserver{

public:
     GameCharacter(int s=10 ,int h=ENEMY_HP);
    typedef std::unique_ptr<Weapon>  weaponPtr;
    void update(Weapon* weapon) override =0;
    virtual void updateState();
    void setHp(int hp);
    int getHp();

    std::list<CollisionObserver*> targetList;

protected:
    virtual void fight()=0;
    virtual void move();
    void setWalkingDelay(int val);

    int hp;
    bool isFighting;

    sf::Vector2f movement;
    sf::Clock attackClock;
    sf::Time attackDelay;
    sf::Clock walkingClock;
    sf::Time walkingDelay;
};
#endif //GAME_GAMECHARACTER_H
