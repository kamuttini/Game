//
// Created by camut on 24/05/19.
//

#include "Player.h"

Player::Player(): movement(1.f, 0.f)
{
    attackDelay=sf::seconds(0.5);
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
    }
}

void Player::dead() {
    if(isDestroyed) {
        rect.setFillColor(sf::Color::Black);
        // game.stop()
    }
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
        }
        else
        {
            if(hp>1)
            {
                hp--;
                weapon->setIsDestroyed(true);
            }
            else{
                isDestroyed=true;
                weapon->setIsDestroyed(true);
            }
        }
    }
}
