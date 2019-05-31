//
// Created by camut on 24/05/19.
//

#ifndef GAME_GAMECHARACTER_H
#define GAME_GAMECHARACTER_H

#include "DynamicComponent.h"
#include "Weapon.h"
#include "Subject.h"


class GameCharacter: public DynamicComponent,public CollisionObserver{

public:
    GameCharacter(int s=5);
    typedef std::unique_ptr<Weapon>  weaponPtr;

    virtual void fight(sf::Vector2f targetDir);
    void update(sf::FloatRect weapon);

    std::vector<weaponPtr> weaponVec;
    std::list<CollisionObserver*> targetList;

protected:
    bool isFighting;
    sf::Clock attackClock;
    sf::Time attackDelay;
};
#endif //GAME_GAMECHARACTER_H
