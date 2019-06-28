//
// Created by camut on 24/05/19.
//

#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H


#include "GameCharacter.h"
#include "Inventory.h"
#include "HUD.h"


class Player: public GameCharacter {
public:
    explicit Player (HUD& hud);
    ~Player(){};
    void getInput();
    void update(Weapon& weapon) override;
    void updateState()override;
    void updateTarget(CollisionObserver *enemy);
    HUD& stats;
    Inventory inventory;

private:
    void fight() override;

    float speed2;
    sf::Clock moveClock;
    sf::SoundBuffer token;
    sf::SoundBuffer damage;
    sf::Sound sound;
};


#endif //GAME_PLAYER_H
