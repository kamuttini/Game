//
// Created by camut on 24/06/19.
//

#include "gtest/gtest.h"

#include "../Enemy.h"
#include "../Token.h"

#include "../Enemy.h"
#include "../Token.h"

class RandomSpawnTest: public ::testing::Test {
public:
    RandomSpawnTest(){};
    ~RandomSpawnTest(){};
    Player player;
    Enemy::type ID=Enemy::type::student;
    Weapon::type type=Weapon::type::book;
    void TearDown() override {
        std::cout<< "FOR EACH OBJECT RANDOMLY GENERATED TEST EXECUTED 100 TIMES";
    }
};

TEST_F(RandomSpawnTest, EnemyWeapon) {
    for(int i=0;i<100;i++)
    {
        Enemy enemy(player, ID, CLASSROOM1_ORIGIN, CLASSROOM1_DIMENSION);
        int posX=enemy.getPosition().x;
        int posY=enemy.getPosition().y;
        int tile=(posX+(posY*MAP_WIDTH));
        auto it =std::find(enemy.getColMap()->colTiles.begin(), enemy.getColMap()->colTiles.end(), tile);
        ASSERT_FALSE(it != enemy.getColMap()->colTiles.end());
    }
}
TEST_F(RandomSpawnTest, WeaponToCollect) {
    for(int i=0;i<100;i++)
    {
        PlayerWeapon weaponToCollect(player,type, CLASSROOM1_ORIGIN, CLASSROOM1_DIMENSION);
        int posX=weaponToCollect.getPosition().x;
        int posY=weaponToCollect.getPosition().y;
        int tile=(posX+(posY*MAP_WIDTH));
        auto it =std::find(weaponToCollect.getColMap()->colTiles.begin(), weaponToCollect.getColMap()->colTiles.end(), tile);
        ASSERT_FALSE(it != weaponToCollect.getColMap()->colTiles.end());
    }
}
TEST_F(RandomSpawnTest, Token) {
    for(int i=0;i<100;i++)
    {
        Token token(Token::type::license);
        int posX=token.getPosition().x;
        int posY=token.getPosition().y;
        int tile=(posX+(posY*MAP_WIDTH));
        auto it =std::find(token.getColMap()->colTiles.begin(), token.getColMap()->colTiles.end(), tile);
        ASSERT_FALSE(it != token.getColMap()->colTiles.end());
    }
}