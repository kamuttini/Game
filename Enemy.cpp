//
// Created by camut on 26/05/19.
//

#include "Enemy.h"
#include <cmath>
sf::Time attackDelay=sf::seconds(2.f);

Enemy:: Enemy(Player* player1): player(player1){
    setPosition();
    rect.setFillColor(sf::Color::Green);
}

void Enemy::setPosition()
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
        attackClock.restart();
    }

    GameCharacter::fight();

    for (int i = 0; i < weaponVec.size(); i++)
    {
       weaponVec[i]->attack();
    }
}

void Enemy::destroy(std::vector<std::unique_ptr<Enemy>>& enemy,std::vector<std::unique_ptr<Enemy>>::const_iterator iter1)
{
    enemy.erase(iter1);
}