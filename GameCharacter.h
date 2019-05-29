//
// Created by camut on 24/05/19.
//

#ifndef GAME_GAMECHARACTER_H
#define GAME_GAMECHARACTER_H

#include "DynamicComponent.h"
#include "Weapon.h"
#include "Subject.h"


class GameCharacter: public DynamicComponent,public collisionObserver{

public:
    GameCharacter(int s=5);
    typedef std::unique_ptr<Weapon>  weaponPtr;
    virtual void fight();
    std::vector<weaponPtr> weaponVec;
    void update(sf::FloatRect weapon);

    //int getHp() const;
    //void setHp(int hp);

protected:
    Subject* enemyWeapons;
    bool isFighting;
    //int hp;

};
#endif //GAME_GAMECHARACTER_H
