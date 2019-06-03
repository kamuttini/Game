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
    GameCharacter(sf::Color color=sf::Color::Green, int s=15, int h=2);
    typedef std::unique_ptr<Weapon>  weaponPtr;

    virtual void update(Weapon* weapon)=0;
    virtual void fight()=0;
    virtual void updateState();
    std::list<CollisionObserver*> targetList;

    int getHp() const;
    void setHp(int hp);

protected:
    int hp;
    bool wounded;
    bool isFighting;
    sf::Clock attackClock;
    sf::Time attackDelay;
    sf::Color color;
    sf::Clock woundedClock;
};
#endif //GAME_GAMECHARACTER_H
