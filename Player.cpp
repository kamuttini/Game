//
// Created by camut on 24/05/19.
//

#include "Player.h"

Player::Player(): movement(0.f, 0.f)
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

    GameCharacter::fight(movement);
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
