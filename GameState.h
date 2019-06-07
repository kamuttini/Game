//
// Created by camut on 04/06/19.
//

#ifndef GAME_GAMESTATE_H
#define GAME_GAMESTATE_H

#include "Game.h"
#include "Enemy.h"
#include "Player.h"

typedef std::unique_ptr<Enemy>  enemyPtr;
typedef std::unique_ptr<PlayerWeapon> playerWeaponPtr;


class GameState: public State {
public:

    GameState(GameDataRef data);
    ~GameState(){};
    void Init() override ;
    void HandleInput() override ;
    void Update()  override;
    void Draw() override ;
    
    std::vector<enemyPtr> enemyVec;

private:
    GameDataRef data;
    Sidebar* sidebar;
    Player* player;
    Factory factory;
    std::vector<playerWeaponPtr> weaponToCollect;
    sf::Clock enemyClock;
    sf::Time enemyDelay=sf::seconds(3.f);
    sf::Clock playerWeaponClock;
    sf::Time playerWeaponDelay=sf::seconds(2.5f);
};


#endif //GAME_GAMESTATE_H
