//
// Created by camut on 24/05/19.
//

#ifndef GAME_GAMECHARACTER_H
#define GAME_GAMECHARACTER_H

#include "DynamicComponent.h"
#include "Weapon.h"
#include "CollisionObserver.h"
#include "Factory.h"


class GameCharacter: public DynamicComponent,public CollisionObserver{

public:
    GameCharacter(int s=15);
    typedef std::unique_ptr<Weapon>  weaponPtr;

    virtual void fight(sf::Vector2f targetDir);
    virtual void update(Weapon* weapon);

    std::vector<weaponPtr> weaponVec;
    std::list<CollisionObserver*> targetList;

protected:
    Factory weaponFactory;
    bool isFighting;
    sf::Clock attackClock;
    sf::Time attackDelay;
};
#endif //GAME_GAMECHARACTER_H
