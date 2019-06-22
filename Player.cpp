//
// Created by camut on 24/05/19.
//

#include <unistd.h>
#include <iostream>
#include "Player.h"
#include "Game.h"


Player::Player(HUD &hud1) : GameCharacter(20, 4),
                                   stats(hud1)
                                   {
    rect.setPosition(PLAYER_START_POSITION);
    rect.setSize(sf::Vector2f(30,60));
    sprite = new Sprite("sprite8.png", *this, 2, 0, 3, 1, 9, 64, 65.25);
    sprite->setScale(sf::Vector2f(1.6, 1.6));
    walkingDelay = sf::seconds(.13f);
    token.loadFromFile("assets/music/token.flac");
    damage.loadFromFile("assets/music/damage.ogg");
                                   }

void Player::getInput() {
    if (walkingClock.getElapsedTime() >= walkingDelay) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            direction = up;
            moveClock.restart();
            move();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            direction = down;
            moveClock.restart();
            move();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            direction = right;
            moveClock.restart();
            move();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            direction = left;
            moveClock.restart();
            move();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
            hp +=1 ;
        }

        walkingClock.restart();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && attackClock.getElapsedTime() > attackDelay) {
        isFighting = true;
        attackClock.restart();
    }
}

void Player::move() {
    if(checkBorders(direction)) {
        GameCharacter::move();
        movement /= speed;
    }
}

void Player::fight() {

    if (isFighting) {
        inventory.useWeapon(targetList, movement, rect.getPosition());
        isFighting = false;
    }

    for (int i = 0; i < inventory.weaponVec.size(); i++) {
        inventory.weaponVec[i]->attack();
        stats.updateWeapons(inventory.collectionSize());
    }
}


void Player::updateTarget(CollisionObserver *enemy) {
    targetList.push_back(enemy);
}

void Player::update(Weapon *weapon) {
    if (weapon->getRect().getGlobalBounds().intersects(rect.getGlobalBounds())) {
        const std::type_info &type_info = typeid(*weapon);
        if (type_info == typeid(PlayerWeapon)) {
            sound.setBuffer(token);
            sound.play();
            inventory.addToCollection(*weapon);
            weapon->setIsDestroyed(true);
            stats.updateWeapons(inventory.collectionSize());
            stats.updateScore(5);
        } else {
            sound.setBuffer(damage);
            sound.play();
            if (hp > 1) {
                hp--;
                weapon->setIsDestroyed(true);
                stats.updateHp();

            } else {
                hp--;
                destroyed = true;
                weapon->setIsDestroyed(true);
                stats.updateHp();
                sf::sleep(sf::seconds(1));
            }
        }
    }
}


void Player::updateState() {
    GameCharacter::updateState();
    inventory.updateState();
    if(moveClock.getElapsedTime()<sf::seconds(0.4))
    {
        if (walkingClock.getElapsedTime() >= walkingDelay)
        {
            move();
            walkingClock.restart();
        }

    }
}



