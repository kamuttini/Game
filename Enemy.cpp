#include <memory>

//
// Created by camut on 26/05/19.
//

#include "Enemy.h"
#include "Follow.h"
#include "RandomMove.h"
#include "Static.h"
#include "Def.h"
#include <cmath>

Enemy::Enemy(Player *player1, type &ID1, sf::Vector2f origin, sf::Vector2f bound) : player(player1),
                                                                                    ID(ID1){
    randomPosition(bound, origin);
    sprite = new Sprite(setSprite(), *this, 2, 1, 3, 0);
    sprite->setScale(sf::Vector2f(1.9, 1.9));
    CollisionObserver *target = player1;
    targetList.push_back(target);
    player1->updateTarget(this);
    attackDelay = ATTACK_DELAY;
    rect.setSize(sf::Vector2f(40,45));
}

void Enemy::fight() {
    float distance;
    distance = sqrt(pow(getPosition().x - player->getPosition().x, 2) +
                    pow(getPosition().y - player->getPosition().y, 2));


    if (attackClock.getElapsedTime() > attackDelay && distance < ATTACK_RANGE) {
        isFighting = true;
        attackClock.restart();
    }

    if (isFighting) {
        weaponVec.push_back(std::unique_ptr<Weapon>(
                weaponFactory.createEnemyWeapon(targetList, calculateDirection(distance), getPosition(), this)));
        isFighting = false;
    }

    for (int i = 0; i < weaponVec.size(); i++) {
        weaponVec[i]->attack();
    }
}

sf::Vector2f Enemy::calculateDirection(int distance) {
    sf::Vector2f playerDir;
    playerDir.x = (player->getPosition().x - getPosition().x) / distance;
    playerDir.y = (player->getPosition().y - getPosition().y) / distance;
    return playerDir;
}


void Enemy::update(Weapon *weapon) {
    if (weapon->getRect().getGlobalBounds().intersects(
            rect.getGlobalBounds()))         //controllo collisioni in base alla posizione di Weapon
    {
        const std::type_info &type_info = typeid(*weapon);                               //verifica il tipo di arma (se è da prendere o si tratta di una collisione con armi nemiche)
        if (type_info == typeid(PlayerWeapon))
            weapon->setIsDestroyed(true);

        else {

            if (hp > 1) {
                hp--;
                weapon->setIsDestroyed(true);
                player->stats.updateScore(WOUNDED_ENEMY);
            } else {
                destroyed = true;
                weapon->setIsDestroyed(true);
            }
        }
    }
}

void Enemy::updateState() {
    GameCharacter::updateState();
    move();
    std::vector<std::unique_ptr<Weapon>>::const_iterator iter2;
    for (int j = 0; j != weaponVec.size(); j++) {
        iter2 = weaponVec.begin();
        if (weaponVec[j]->isDestroyed()) {
            weaponVec[j]->destroy(weaponVec, iter2);
            break;
        }
        iter2++;
    }
}


void
Enemy::destroy(std::vector<std::unique_ptr<Enemy>> &enemy, std::vector<std::unique_ptr<Enemy>>::const_iterator iter1) {
    player->targetList.remove(this);
    for (int i = 0; i < player->inventory.weaponVec.size(); i++) {
        player->inventory.weaponVec[i]->removeObserver(this);
    }
    player->stats.updateScore(DEAD_ENEMY);
    enemy.erase(iter1);
}

Enemy::type Enemy::getId() const {
    return ID;
}

void Enemy::move() {
    float distance;
    distance = sqrt(pow(getPosition().x - player->getPosition().x, 2) +
                    pow(getPosition().y - player->getPosition().y, 2));

    if (hp > 1 && distance < FOLLOW_RANGE) {
        strategy = new Follow;
    } else {
        if (hp > 1) {
            strategy = new RandomMove();
        } else {
            strategy = new Static;
        }
    }
    strategy->setDirection(*this, *player);
    orientation fakeDirection = swapDirection();
    if (checkBorders(fakeDirection)) {
        if (walkingClock.getElapsedTime() >= walkingDelay) {
            walkingClock.restart();
            movement.x = 0.f;
            movement.y = 0.f;
            switch (direction) {
                case up:
                    movement.x -= speed;
                    break;

                case down:
                    movement.x += speed;
                    break;

                case left:
                    movement.y += speed;
                    break;
                case right:
                    movement.y -= speed;
                    break;
                case null:
                    movement=sf::Vector2f(0,0);
            }
            rect.move(movement);
            sprite->animate();
        }
    }
    else {
        srand(clock());
        direction=orientation(rand() % 4);
    }
}


std::string Enemy::setSprite() {
    std::string filename;

    switch (ID) {
        case Enemy::type::student:
            filename = "sprite3-0.png";
            break;

        case Enemy::type::chef:
            filename = "sprite3-7.png";
            break;

        case Enemy::type::barMan:
            filename = "sprite4-0.png";
            break;
    }

    return filename;
}


Strategy *Enemy::getStrategy() const {
    return strategy;
}


DynamicComponent::orientation Enemy::swapDirection() {
    orientation fakeDirection;

    switch (direction) {
        case up:
            fakeDirection=left;
            break;

        case down:
            fakeDirection=right;
            break;

        case left:
            fakeDirection=down;
            break;
        case right:
            fakeDirection=up;
            break;
    }
    return fakeDirection;
}



