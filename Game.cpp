//
// Created by camut on 25/05/19.
//

#include "Game.h"

sf::Clock enemyClock;
sf::Time enemyDelay=sf::seconds(3.f);

void Game::run(sf::RenderWindow& window)
{

    while (window.isOpen())
    {
        processEvents(window);
        update();
        render(window);
    }
}

void Game::processEvents(sf::RenderWindow& window)
{
    sf::Event event;

    while (window.pollEvent(event))
    {

        switch(event.type)
        {
            case sf::Event::KeyPressed:
                player.getInput();
                break;

            case sf::Event::Closed:
                window.close();
                break;
        }
    }
}

void Game::render(sf::RenderWindow& window)
{
    window.clear();
    for (int i = 0; i < enemyVec.size(); i++)
    {
        enemyVec[i]->draw(window);
        for (int j = 0; j < enemyVec[i]->weaponVec.size(); j++)
        {
            enemyVec[i]->weaponVec[j]->draw(window);
        }

    }


    for (int d = 0; d < player.weaponVec.size(); d++)
    {
        player.weaponVec[d]->attack();
        player.weaponVec[d]->draw(window);
    }
    player.draw(window);
    window.display();
}


void Game::update() {
    //generate enemy
    player.fight();
    if( enemyClock.getElapsedTime()>=enemyDelay)
    {
        enemyVec.push_back(std::unique_ptr<Enemy>(new Enemy(&player)));
        enemyClock.restart();
    }

    //generate enemyWeapon
    for( int i=0; i < enemyVec.size(); i++)
    {
        enemyVec[i]->fight();
    }

    //check collision between playerWeapon and enemy
    for(int j = 0; j < player.weaponVec.size(); j++)
    {
        for (int i = 0; i < enemyVec.size(); i++)
        {
            if (player.weaponVec[j]->getRect().getGlobalBounds().intersects( enemyVec[i]->getRect().getGlobalBounds()))
            {
                player.weaponVec[j]->setIsDestroyed(true);
                enemyVec[i]->setIsDestroyed(true);
            }
        }
    }

    //delete playerWeapon if collision is detected
    std::vector<std::unique_ptr<Weapon>>::const_iterator iter;
    int i=0;
    for (iter=player.weaponVec.begin(); iter!=player.weaponVec.end(); iter++)
    {
        if (player.weaponVec[i]->isDestroyed1())
        {
            player.weaponVec.erase(iter);
            break;
        }
        i++;
    }

    //delete enemy if collision detected
    std::vector<std::unique_ptr<Enemy>>::const_iterator iter1;
    i=0;
    for (iter1=enemyVec.begin(); iter1!=enemyVec.end(); iter1++)
    {
        if (enemyVec[i]->isDestroyed1())
        {
            enemyVec[i]->destroy(enemyVec,iter1);
            break;
        }
        i++;
    }
}


