//
// Created by camut on 24/05/19.
//

#include <unistd.h>
#include "Player.h"

Player::Player(Sidebar* sidebar): movement(1.f, 0.f), stats(sidebar)
{
    attackDelay=sf::seconds(0.5);
    addObserver(sidebar);
    rect.setPosition(600,600);
    rect.setFillColor(sf::Color::Red);
}

void Player::getInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        direction = up;
        move();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        direction = down;
        move();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) ){
        direction = right;
        move();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        direction = left;
        move();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && attackClock.getElapsedTime()>attackDelay){
        isFighting= true;
        attackClock.restart();
    }
}

void Player::move() {
    movement.x=0.f;
    movement.y=0.f;

    if (direction == left)
        movement.x -= speed;

    if (direction == right)
        movement.x += speed;;

    if (direction == down)
        movement.y += speed;

    if (direction == up)
        movement.y -= speed;

    rect.move(movement);
    movement/=speed;
}

void Player::fight() {

    if( isFighting) {
        inventory.useWeapon(targetList, movement, rect.getPosition());
        isFighting = false;
    }

    for (int i = 0; i < inventory.weaponVec.size(); i++)
    {
        inventory.weaponVec[i]->attack();
        stats->updateWeapons(inventory.collectionSize());
    }
}

bool Player::dead() {
    if(isDestroyed) {
        delete(this);
        return true;
    }
    return false;
}

void Player::updateSituation(CollisionObserver* enemy) {
    targetList.push_back(enemy);
}

void Player::update(Weapon *weapon) {
    if (weapon->getRect().getGlobalBounds().intersects( rect.getGlobalBounds()))
    {
        const std::type_info& type_info = typeid(*weapon);
        if( type_info== typeid(PlayerWeapon))
        {
            inventory.addToCollection(*weapon);
            weapon->setIsDestroyed(true);
            stats->updateWeapons(inventory.collectionSize());
        }
        else
        {
            if(hp>1){
                hp--;
                weapon->setIsDestroyed(true);
                stats->updateHp(hp);
            }
            else{
                hp--;
                isDestroyed=true;
                weapon->setIsDestroyed(true);
                stats->updateHp(hp);
                sf::sleep(sf::seconds(1));
            }
        }
    }
}

void Player::addObserver(Sidebar* o){
    stats =o;
}



