//
// Created by camut on 26/05/19.
//

#include "Enemy.h"
#include "Follow.h"
#include "RandomMove.h"
#include "Static.h"
#include <cmath>

Enemy:: Enemy(Player* player1,type& ID1, sf::Color color1): player (player1),
                                                            GameCharacter(5,color1),
                                                            ID(ID1){
    strategy=new RandomMove;
    CollisionObserver* target=player1;
    targetList.push_back(target);
    player1->updateTarget(this);
    attackDelay=sf::seconds(2.f);
    randomPosition();
}


void Enemy::fight()
{
    float distance;
    distance= sqrt(pow(rect.getPosition().x- player->getRect().getPosition().x, 2) + pow(rect.getPosition().y- player->getRect().getPosition().y, 2));

    sf::Vector2f playerDir;
    playerDir.x=(player->getRect().getPosition().x-rect.getPosition().x)/distance;
    playerDir.y=(player->getRect().getPosition().y-rect.getPosition().y)/ distance;

    if (attackClock.getElapsedTime() > attackDelay && distance<600) {
        isFighting = true;
        attackClock.restart();
    }

    if( isFighting) {
        weaponVec.push_back(std::unique_ptr<Weapon>(weaponFactory.createWeapon(targetList, playerDir, rect.getPosition(), this)));
        isFighting = false;
    }

    for (int i = 0; i < weaponVec.size(); i++)
    {
        weaponVec[i]->attack();
    }
}


void Enemy::update(Weapon* weapon) {
    if (weapon->getRect().getGlobalBounds().intersects( rect.getGlobalBounds()))       //controllo collisioni in base alla posizione di Weapon
    {
        const std::type_info& type_info = typeid(*weapon);                          //verifica il tipo di arma
        if( type_info== typeid(PlayerWeapon))
            weapon->setIsDestroyed(true);

        else
        {
            wounded=true;
            woundedClock.restart();
            if(hp>1){
                hp--;
                weapon->setIsDestroyed(true);
                player->stats.updateScore(10);
            }
            else{
                isDestroyed=true;
                weapon->setIsDestroyed(true);
            }
        }
    }
}
void Enemy::updateState() {
    GameCharacter::updateState();
    move();
    std::vector<std::unique_ptr<Weapon>>::const_iterator iter2;
    for(int j=0; j!=weaponVec.size(); j++)
    {
        iter2=weaponVec.begin();
        if(weaponVec[j]->isDestroyed1())
        {
            weaponVec[j]->destroy(weaponVec,iter2);
            break;
        }
        iter2++;
    }
}


void Enemy::destroy(std::vector<std::unique_ptr<Enemy>>& enemy,std::vector<std::unique_ptr<Enemy>>::const_iterator iter1)
{
    player->targetList.remove(this);
    for(int i=0; i< player->inventory.weaponVec.size(); i++)
    {
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
    distance= sqrt(pow(posX- player->getRect().getPosition().x, 2) + pow(posY- player->getRect().getPosition().y, 2));

    if(hp>1 && distance <400) {
        delete (strategy);
        strategy = new Follow;
    }
    else {
        if (hp > 1) {
            delete (strategy);
            strategy = new RandomMove();
        }

        else {
            delete(strategy);
            strategy = new Static;
        }

    }
    strategy->move(*this, *player);
}
