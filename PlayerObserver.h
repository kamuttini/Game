//
// Created by camut on 28/06/19.
//

#ifndef GAME_PLAYER_OBSERVER_H
#define GAME_PLAYER_OBSERVER_H

class PlayerObserver {
public:
    PlayerObserver()= default;
    virtual ~PlayerObserver()= default;
    virtual void update(int kills, int weapon, int hp, bool pacifista)=0;
    virtual void updateScore(int bonus)=0;

protected:
    int kills;
    int weaponCaught;
    int hp;
    bool pacifista;
};
#endif //GAME_PLAYER_OBSERVER_H

