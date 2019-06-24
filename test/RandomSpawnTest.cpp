//
// Created by camut on 24/06/19.
//

#include "gtest/gtest.h"

#include "../Enemy.h"
#include "../Token.h"

class RandomSpawnTest: public ::testing::Test {
public:
    RandomSpawnTest(): player(sidebar), enemy(&player, ID, CLASSROOM1_ORIGIN, CLASSROOM1_DIMENSION), weaponToCollect(player,type, CLASSROOM1_ORIGIN, CLASSROOM1_DIMENSION), token(Token::type::license){};
    ~RandomSpawnTest(){};
    HUD sidebar;
    Player player;
    Enemy enemy;
    PlayerWeapon weaponToCollect;
    Token token;
    Enemy::type ID=Enemy::type::student;
    Weapon::type type=Weapon::type::book;
    void TearDown() override {
        std::cout<< "FOR EACH OBJECT RANDOMLY GENERATED TEST EXECUTED 100 TIMES";
    }
};

TEST_F(RandomSpawnTest, EnemyWeapon) {
    for(int i=0;i<100;i++)
    {
        enemy.randomPosition(CLASSROOM1_DIMENSION,CLASSROOM1_ORIGIN);
        weaponToCollect.randomPosition(CLASSROOM1_DIMENSION,CLASSROOM1_ORIGIN);
        token.randomPosition(CLASSROOM3_DIMENSION,CLASSROOM1_ORIGIN);
        ASSERT_TRUE(enemy.checkPosition(enemy.findTile()));
    }
}