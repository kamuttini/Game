//
// Created by camut on 01/06/19.
//

#include "PlayerWeapon.h"
#include "Player.h"

PlayerWeapon::PlayerWeapon(Player *player): Weapon(sf::Color::Yellow),
                                            targetList(player->targetList),
                                            caught(false)
{
    rect.setSize(sf::Vector2f(25.f,25.f));
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


