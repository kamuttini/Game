//
// Created by camut on 24/05/19.
//

#ifndef GAME_GAMECHARACTER_H
#define GAME_GAMECHARACTER_H

#include "DynamicComponent.h"
#include "Weapon.h"
typedef std::unique_ptr<Weapon>  weaponPtr;

class GameCharacter: public DynamicComponent,public CollisionObserver{

public:
     explicit GameCharacter(int s=10 ,int h=ENEMY_HP);
     ~GameCharacter()= default;
    void update(Weapon& weapon) override =0;
    virtual void updateState();

    void setHp(int hp);
    int getHp();
    void setWalkingDelay(int val);

    std::list<CollisionObserver*> targetList;

protected:
    virtual void fight()=0;
    virtual void move();

    int hp;
    bool isFighting;

    sf::Vector2f movement;
    sf::Clock attackClock;
    sf::Time attackDelay;
    sf::Clock walkingClock;
    sf::Time walkingDelay;
};
#endif //GAME_GAMECHARACTER_H
