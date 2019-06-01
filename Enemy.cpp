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



void Enemy::fight()
{
    float distance;
    distance= sqrt(pow(posX- player->getRect().getPosition().x, 2) + pow(posY- player->getRect().getPosition().y, 2));

    if (attackClock.getElapsedTime() > attackDelay && distance<300) {
        isFighting = true;
        attackClock.restart();
    }

    sf::Vector2f playerDir;
    playerDir.x=(player->getRect().getPosition().x-posX)/distance;
    playerDir.y=(player->getRect().getPosition().y-posY)/ distance;

    GameCharacter::fight(playerDir);
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