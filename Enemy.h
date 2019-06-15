//
// Created by camut on 26/05/19.
//

#ifndef GAME_ENEMY_H
#define GAME_ENEMY_H


#include "GameCharacter.h"
#include "Player.h"
#include "Strategy.h"
#include "BaseClock.h"

class Enemy : public GameCharacter {
public:
    enum type {
        student, barMan, chef
    };

    explicit Enemy(Player *player, Strategy *strategy, type &ID);

    ~Enemy() {};

    void fight() override;

    void move() override;

    void destroy(std::vector<std::unique_ptr<Enemy>> &enemy, std::vector<std::unique_ptr<Enemy>>::const_iterator iter1);

    void updateState() override;

    void update(Weapon *weapon) override;

    type getId() const;

    std::string setSprite();

    std::vector<weaponPtr> weaponVec;

private:
    Strategy* strategy;
    type ID;
    Factory weaponFactory;
    Player *player;
};


#endif //GAME_ENEMY_H
