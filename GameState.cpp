//
// Created by camut on 04/06/19.
//

#include "GameState.h"
#include "GameOverState.h"

GameState::GameState(GameDataRef data) : _data(data)
{
}

void GameState::Init()
{
    sidebar= new Sidebar;
    player=new Player(sidebar);
    _data->soundTrack.play();
}

void GameState::HandleInput()
{
    sf::Event event;

    while (this->_data->window.pollEvent(event))
    {
        switch(event.type)
        {
            case sf::Event::KeyPressed:
                player->getInput();
                break;

            case sf::Event::Closed:
                this->_data->window.close();
                break;
        }
    }
}

void GameState::Update()
{
    player->updateState();

    int i = 0;
    for (i = 0; i < weaponToCollect.size(); i++) {
        weaponToCollect[i]->notify();
        weaponToCollect[i]->updateState();
    }

    if (enemyVec.size() <= 5 &&
        enemyClock.getElapsedTime() >= enemyDelay)                                    //generate enemy
    {
        enemyVec.push_back(factory.createEnemy(player));
        enemyClock.restart();
    }
    if (playerWeaponClock.getElapsedTime() >= playerWeaponDelay)                     //generate playerWeapon
    {
        weaponToCollect.push_back(factory.createPlayerWeapon(player));
        playerWeaponClock.restart();
    }

    for (i = 0; i < enemyVec.size(); i++)                                         //generate enemyWeapon
        enemyVec[i]->updateState();

    std::vector<std::unique_ptr<Enemy>>::const_iterator iter1;                  //delete enemy if collision detected
    i = 0;
    for (iter1 = enemyVec.begin(); iter1 != enemyVec.end(); iter1++) {
        if (enemyVec[i]->isDestroyed1()) {
            enemyVec[i]->destroy(enemyVec, iter1);
            break;
        }
        i++;
    }


    std::vector<std::unique_ptr<PlayerWeapon>>::const_iterator iter3 = weaponToCollect.begin();    //delete weapon if collision detected
    for (i = 0; i < weaponToCollect.size(); i++) {
        if (weaponToCollect[i]->isDestroyed1())
            weaponToCollect[i]->destroy(weaponToCollect, iter3);
        iter3++;
    }

    if(player->isDestroyed1()){
        this->_data->machine.AddState(StateRef(new GameOverState(sidebar->getScore(), this->_data)), true);
    }
}

void GameState::Draw()
{
    this->_data->window.clear();
    sidebar->draw(this->_data->window);

    int i,j;
    for (i = 0; i < enemyVec.size(); i++){
        enemyVec[i]->draw(this->_data->window);
        for (j = 0; j < enemyVec[i]->weaponVec.size(); j++)
            enemyVec[i]->weaponVec[j]->draw(this->_data->window);
    }

    for (i = 0; i < weaponToCollect.size(); i++)
        weaponToCollect[i]->draw(this->_data->window);

    for (i = 0; i < player->inventory.weaponVec.size(); i++)
        player->inventory.weaponVec[i]->draw(this->_data->window);

    player->draw(this->_data->window);
    this->_data->window.display();
}