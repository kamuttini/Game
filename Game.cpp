//
// Created by camut on 25/05/19.
//

#include "Game.h"

sf::Clock enemyClock;
sf::Time enemyDelay=sf::seconds(3.f);
sf::Clock playerWeaponClock;
sf::Time playerWeaponDelay=sf::seconds(2.5f);

Game::Game(){
    player.addObserver(&sidebar);
}


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
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                {
                    run(window);
                    delete menu;
                }
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
    sidebar.draw(window);

    int i,j;
    for (i = 0; i < enemyVec.size(); i++){
        enemyVec[i]->draw(window);
        for (j = 0; j < enemyVec[i]->weaponVec.size(); j++)
            enemyVec[i]->weaponVec[j]->draw(window);
    }

    for (i = 0; i < weaponToCollect.size(); i++)
        weaponToCollect[i]->draw(window);

    for (i = 0; i < player.inventory.weaponVec.size(); i++)
        player.inventory.weaponVec[i]->draw(window);

    player.draw(window);
    window.display();
}


void Game::update() {

    player.fight();

    int i=0;
    for (i = 0; i < weaponToCollect.size(); i++) {
        weaponToCollect[i]->notify();
        weaponToCollect[i]->updateState();
    }

    if(enemyVec.size()<=5 && enemyClock.getElapsedTime()>=enemyDelay)                                    //generate enemy
    {
        enemyVec.push_back(factory.createEnemy(&player));
        enemyClock.restart();
    }
    if( playerWeaponClock.getElapsedTime()>=playerWeaponDelay)                     //generate playerWeapon
    {
        weaponToCollect.push_back(factory.createPlayerWeapon(&player));
        playerWeaponClock.restart();
    }

    for( i=0; i < enemyVec.size(); i++)                                         //generate enemyWeapon
        enemyVec[i]->fight();

    std::vector<std::unique_ptr<Enemy>>::const_iterator iter1;                  //delete enemy if collision detected
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

    for(i=0; i!=enemyVec.size(); i++)
    {
        enemyVec[i]->updateState();
    }

    player.inventory.updateState();

    std::vector<std::unique_ptr<PlayerWeapon>>::const_iterator iter3= weaponToCollect.begin();    //delete weapon if collision detected
    for (i = 0; i < weaponToCollect.size(); i++) {
        if (weaponToCollect[i]->isDestroyed1())
            weaponToCollect[i]->destroy(weaponToCollect, iter3);
        iter3++;
    }

    player.dead();
}

void Game::start(sf::RenderWindow& window) {
    menu= new MainMenu(window);
    while (window.isOpen())
    {

        processEvents(window);
        window.clear(sf::Color(86, 126, 199));
        menu->draw(window);
        window.display();
    }
}
