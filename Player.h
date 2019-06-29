//
// Created by camut on 24/05/19.
//

#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H


#include "GameCharacter.h"
#include "Inventory.h"
#include "Subject.h"
#include "Badge.h"

class Player: public GameCharacter, public Subject {
public:
    explicit Player ();
    ~Player()= default;
    void addObserver(PlayerObserver* o) override ;
    void getInput();
    void update(Weapon& weapon) override;
    void updateState()override;
    void updateTarget(CollisionObserver *enemy);
    void setKilled(bool=false);
    int getLevelKills();
    void Pacifista();
    void notify()override ;

    Inventory inventory;
    PlayerObserver* stats;

private:
    void fight() override;
    void move() override ;
    void removeObserver(PlayerObserver* o) override;

    int kills;
    int levelkills;
    bool pacifista;
    float speed2;
    sf::Clock moveClock;
    sf::SoundBuffer token;
    sf::SoundBuffer damage;
    sf::Sound sound;
};


#endif //GAME_PLAYER_H
