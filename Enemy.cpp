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

Enemy::Enemy(Player *player1, type &ID1,sf::Vector2f origin, sf::Vector2f bound) : player(player1),
                                            GameCharacter(10),
                                            ID(ID1) {
    randomPosition(bound,origin);
    sprite = new Sprite(setSprite(), *this, 2, 1, 3, 0);
    sprite->setScale(sf::Vector2f(1.9, 1.9));
    CollisionObserver *target = player1;
    targetList.push_back(target);
    player1->updateTarget(this);
    attackDelay = sf::seconds(4.f);
    rect.setSize(sf::Vector2f(40.f,40.f));
}

void Enemy::fight() {
    float distance;
    distance = sqrt(pow(rect.getPosition().x - player->getRect().getPosition().x, 2) +
                    pow(rect.getPosition().y - player->getRect().getPosition().y, 2));

    sf::Vector2f playerDir;
    playerDir.x = (player->getRect().getPosition().x - rect.getPosition().x) / distance;
    playerDir.y = (player->getRect().getPosition().y - rect.getPosition().y) / distance;

    if (attackClock.getElapsedTime() > attackDelay && distance < 600) {
        isFighting = true;
        attackClock.restart();
    }

    if( isFighting) {
        weaponVec.push_back(std::unique_ptr<Weapon>(weaponFactory.createEnemyWeapon(targetList, playerDir, rect.getPosition(), this)));
        isFighting = false;
    }

    for (int i = 0; i < weaponVec.size(); i++) {
        weaponVec[i]->attack();
    }
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
                player->stats.updateScore(10);
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
    enemy.erase(iter1);
    player->stats.updateScore(25);
}

Enemy::type Enemy::getId() const {
    return ID;
}

void Enemy::move() {
    float distance;
    distance= sqrt(pow(rect.getPosition().x- player->getRect().getPosition().x, 2) + pow(rect.getPosition().y- player->getRect().getPosition().y, 2));

    if(hp>1 && distance <300) {
        strategy = new Follow;
    }
    else {
        if (hp > 1) {
            strategy = new RandomMove();
        } else {
            strategy = new Static;
        }
    }
    if (walkingClock.getElapsedTime() >= walkingDelay && checkBorders(direction)) {
        strategy->move(*this, *player);
        walkingClock.restart();
    }

    if(!checkBorders(direction))
    {
        srand(clock());
        setDirection(orientation(rand() % 4));
        strategy=new Follow;
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

Strategy* Enemy::getStrategy() const {
    return  strategy;
}

void Enemy::findTile() {


    bottom =rect.getPosition().y+rect.getSize().y+25;
    sx =rect.getPosition().x+20;
    dx=rect.getPosition().x+rect.getSize().x;
    top =rect.getPosition().y;

    int tileX=int(sx)/(16*2.5);
    int tileY=int(bottom)/(16*2.5);
    tile=(tileX+tileY*110);
    DynamicComponent::findTile();
}
