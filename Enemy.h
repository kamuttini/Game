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
    enum type {student, barMan, chef};

    explicit Enemy(Player &player, type &ID,sf::Vector2f origin, sf::Vector2f bound);
    ~Enemy()= default;
    void destroy(std::vector<std::unique_ptr<Enemy>> &enemy, std::vector<std::unique_ptr<Enemy>>::const_iterator iter1);
    void updateState() override;
    void update(Weapon &weapon) override;
    sf::Vector2f calculateDirection(int distance);

    type getId() const;
    const std::unique_ptr<Strategy> &getStrategy() const;

    std::vector<weaponPtr> weaponVec;

private:
    void fight() override;
    void move() override;
    std::string setSprite();
    orientation swapDirection();

    std::unique_ptr<Strategy> strategy;
    type ID;
    Factory weaponFactory;
    Player& player;
};


#endif //GAME_ENEMY_H
