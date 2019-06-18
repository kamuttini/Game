//
// Created by camut on 26/05/19.
//

#ifndef GAME_ENEMY_H
#define GAME_ENEMY_H


#include "GameCharacter.h"
#include "Player.h"
#include "Strategy.h"

class Enemy : public GameCharacter {
public:
    enum type {
        student, barMan, chef
    };

    explicit Enemy(Player *player, type &ID,sf::Vector2f origin, sf::Vector2f bound);
    ~Enemy() {};
    void fight() override;
    void move() override;
    void destroy(std::vector<std::unique_ptr<Enemy>> &enemy, std::vector<std::unique_ptr<Enemy>>::const_iterator iter1);
    void updateState() override;
    void update(Weapon *weapon) override;
    void findTile() override;
    type getId() const;
    std::string setSprite();
    Strategy* getStrategy() const;

    std::vector<weaponPtr> weaponVec;
    sf::Clock changeDirectionClock;

private:
    Strategy* strategy;
    type ID;
    Factory weaponFactory;
    Player *player;
};


#endif //GAME_ENEMY_H
