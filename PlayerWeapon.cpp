//
// Created by camut on 01/06/19.
//

#include "PlayerWeapon.h"
#include "Player.h"

PlayerWeapon::PlayerWeapon(Player *player): Weapon(), targetList(player->targetList), caught(false)
{
    randomPosition();
    CollisionObserver* target= player;
    addObserver(target);
    displayTime=sf::seconds(6);
}

void PlayerWeapon::updateState() {

    if(displayClock.getElapsedTime()>= displayTime && caught==false)
        isDestroyed=true;
}

void PlayerWeapon::destroy(std::vector<std::unique_ptr<PlayerWeapon>>& weapon,std::vector<std::unique_ptr<PlayerWeapon>>::const_iterator iter) {

    weapon.erase(iter);
}


