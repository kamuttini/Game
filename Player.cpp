//
// Created by camut on 24/05/19.
//

#include <unistd.h>
#include <iostream>
#include "Player.h"
#include "Game.h"


Player::Player() :  GameCharacter(MIN_SPEED, PLAYER_HP),
                    speed2(MAX_SPEED),
                    kills(0),
                    levelkills(0),
                    pacifista(false)
{
    rect.setPosition(PLAYER_START_POSITION);
    rect.setSize(sf::Vector2f(30,60));
    sprite= std::make_unique<Sprite> ("sprite8.png", *this, 2, 0, 3, 1, 9, 64, 65.25);
    sprite->setScale(sf::Vector2f(1.6, 1.6));
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

        walkingClock.restart();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && attackClock.getElapsedTime() > attackDelay) {
        isFighting = true;
        attackClock.restart();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
        hp +=1 ;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
        std::swap(speed,speed2);
    }

}

void Player::move() {
    if(checkBorders(direction)) {
        GameCharacter::move();
        movement /= speed;
        notifyPosition();
    }
}

void Player::fight() {

    if (isFighting) {
        inventory.useWeapon(targetList, movement, rect.getPosition());
        isFighting = false;
    }

    for (int i = 0; i < inventory.weaponVec.size(); i++) {
        inventory.weaponVec[i]->attack();
        notify();
    }
}


void Player::updateTarget(CollisionObserver *enemy) {
    targetList.push_back(enemy);
}

void Player::update(Weapon &weapon) {
    if (weapon.getRect().getGlobalBounds().intersects(rect.getGlobalBounds())) {
        const std::type_info &type_info = typeid(weapon);
        if (type_info == typeid(PlayerWeapon)) {
            sound.setBuffer(token);
            sound.play();
            inventory.addToCollection(weapon);
            weapon.setIsDestroyed(true);
            notify();
        } else {
            sound.setBuffer(damage);
            sound.play();
            if (hp > 1) {
                hp--;
                weapon.setIsDestroyed(true);
                notify();

            } else {
                hp--;
                destroyed = true;
                weapon.setIsDestroyed(true);
                notify();
                sf::sleep(sf::seconds(1));
            }
        }
    }
}


void Player::updateState() {
    GameCharacter::updateState();
    inventory.updateState();
    if(moveClock.getElapsedTime()<sf::seconds(0.5))
    {
        if (walkingClock.getElapsedTime() >= walkingDelay)
        {
            move();
            walkingClock.restart();
        }

    }
}

void Player::addObserver(PlayerObserver *o) {
    stats=o;
}

void Player::notify() {
    stats->update(kills, inventory.collectionSize(), hp, pacifista);
}

void Player::removeObserver(PlayerObserver *o) {
    delete(o);
}

void Player::setKilled(bool val) {
    if(!val) {
        kills += 1;
        levelkills += 1;
        notify();
    }
    else
    levelkills=0;
}

int Player::getLevelKills() {
    return levelkills;
}

void Player::Pacifista() {
    pacifista=true;
}

void Player::addPositionObserver(PositionObserver *o) {
    map=o;
}

void Player::notifyPosition() {
    map->update(rect,0, true);
}



