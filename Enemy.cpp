//
// Created by camut on 26/05/19.
//

#include "Enemy.h"
#include <cmath>

Enemy:: Enemy(Player* player1): player(player1) {
    CollisionObserver* target=player1;
    targetList.push_back(target);
    player1->updateSituation(this);
    attackDelay=sf::seconds(2.f);
    randomPosition();
    rect.setFillColor(sf::Color::Green);
}

void Enemy::randomPosition()
{
    srand((unsigned)time(0));
    posX=rand()%1350;
    posY=rand()%950;
    rect.setPosition(posX,posY);
}

void Enemy::fight(){
    if ( attackClock.getElapsedTime()> attackDelay)
    {
        isFighting=true;
    }

    GameCharacter::fight();
}


void Enemy::destroy(std::vector<std::unique_ptr<Enemy>>& enemy,std::vector<std::unique_ptr<Enemy>>::const_iterator iter1)
{
    player->targetList.remove(this);
    for(int i=0; i< player->weaponVec.size(); i++)
    {
        player->weaponVec[i]->removeObserver(this);
    }
    enemy.erase(iter1);
}