//
// Created by camut on 24/05/19.
//

#include <unistd.h>
#include "Player.h"
#include "Game.h"


Player::Player(Sidebar& sidebar):   GameCharacter(16,3),
                                    stats(sidebar),
                                    movement(1.f, 0.f)
{
    rect.setPosition(600,600);
    sprite= new Sprite("girl.png", *this, 2, 1, 3, 0,6, 65, 80);
}

void Player::getInput() {
    if(walkingClock.getElapsedTime()>=walkingDelay)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            direction = up;
            move();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            direction = down;
            move();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            direction = right;
            move();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            direction = left;
            move();
        }
        walkingClock.restart();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && attackClock.getElapsedTime()>attackDelay){
        isFighting= true;
        attackClock.restart();
    }
}

void Player::move() {
    movement.x=0.f;
    movement.y=0.f;
    switch(direction)
    {
        case left:
            movement.x -= speed;
            break;

        case right:
            movement.x += speed;
            break;

        case down:
            movement.y += speed;
            break;
        case up:
            movement.y -= speed;
            break;
    }

        rect.move(movement);
    sprite->animate();
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
        stats.updateWeapons(inventory.collectionSize());
    }
}


void Player::updateTarget(CollisionObserver *enemy) {
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
            stats.updateWeapons(inventory.collectionSize());
            stats.updateScore(5);
        }
        else
        {
            wounded=true;
            woundedClock.restart();

            if(hp>1){
                hp--;
                weapon->setIsDestroyed(true);
                stats.updateHp(hp);

            }
            else{
                hp--;
                isDestroyed=true;
                weapon->setIsDestroyed(true);
                stats.updateHp(hp);
                sf::sleep(sf::seconds(1));
            }
        }
    }
}


void Player::updateState() {
    GameCharacter::updateState();
    inventory.updateState();
}


