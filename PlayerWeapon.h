//
// Created by camut on 01/06/19.
//

#ifndef GAME_PLAYERWEAPON_H
#define GAME_PLAYERWEAPON_H


#include "Weapon.h"
class Player;

class PlayerWeapon: public Weapon {
public:
    explicit PlayerWeapon(Player& player,type id,sf::Vector2f origin, sf::Vector2f bound);
    ~PlayerWeapon()= default;
    void updateState();
    void destroy(std::vector<std::unique_ptr<PlayerWeapon>>& enemy,std::vector<std::unique_ptr<PlayerWeapon>>::const_iterator iter);

private:
    bool caught;
    std::list<CollisionObserver*>& targetList;
    sf::Time displayTime;
    sf::Clock displayClock;
};


#endif //GAME_PLAYERWEAPON_H
