//
// Created by camut on 01/06/19.
//

#include "PlayerWeapon.h"
#include "Player.h"
#include "Def.h"

PlayerWeapon::PlayerWeapon(Player &player,type id,sf::Vector2f origin, sf::Vector2f bound):      Weapon(id),
                                                                                                 targetList(player.targetList),
                                                                                                 caught(false)
{
    randomPosition(bound,origin);
    rect.setSize(sf::Vector2f(25.f,25.f));
    CollisionObserver* target= &player;
    addObserver(target);
    displayTime=sf::seconds(12);
    sprite= new Sprite(setSprite(), *this);
    sprite->setScale(sf::Vector2f(0.8,0.8));
}

void PlayerWeapon::updateState() {

    if(displayClock.getElapsedTime()>= displayTime && !caught)
        destroyed=true;
}

void PlayerWeapon::destroy(std::vector<std::unique_ptr<PlayerWeapon>>& weapon,std::vector<std::unique_ptr<PlayerWeapon>>::const_iterator iter) {
    weapon.erase(iter);
}


