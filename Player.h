//
// Created by camut on 24/05/19.
//

#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H


#include "GameCharacter.h"
#include "Inventory.h"
#include "Subject.h"
#include "PositionSubject.h"
#include "PositionObserver.h"

class Player: public GameCharacter, public Subject, public PositionSubject {
public:
    explicit Player ();
    ~Player()= default;
    void addObserver(PlayerObserver* o) override ;
    void addPositionObserver (PositionObserver* o) override;
    void notify()override ;
    void getInput();
    void update(Weapon& weapon) override;
    void updateState()override;
    void updateTarget(CollisionObserver *enemy);
    void move() override ;

    void setKilled(bool=false);
    int getLevelKills();
    void Pacifista();


    Inventory inventory;
    PlayerObserver* stats;

private:
    void fight() override;
    void removeObserver(PlayerObserver* o) override;
    void removePositionObserver(PositionObserver* o) override {};
    void notifyPosition() override;;

    PositionObserver* map;
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
