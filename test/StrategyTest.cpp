//
// Created by camut on 14/06/19.
//

#include <cmath>
#include "gtest/gtest.h"
#include "../Enemy.h"
#include "../RandomMove.h"
#include "../Follow.h"
#include "../Static.h"


class StrategyTest : public ::testing::Test {
protected:
    StrategyTest(): player(), enemy(player, ID, HALL_ORIGIN, HALL_DIMENSION){};
    ~StrategyTest() {};
    int calculateDistance();
    Player player;
    Enemy enemy;
    Enemy::type ID=Enemy::type::student;

    void SetUp() override{
        player.setPosition(2000,1900);
        enemy.setWalkingDelay(0);
    }
};

int StrategyTest::calculateDistance() {
    return sqrt(pow(enemy.getPosition().x- player.getPosition().x, 2) + pow(enemy.getPosition().y- player.getPosition().y, 2));
}

TEST_F(StrategyTest, RandomMove) {
    enemy.setPosition(player.getPosition().x-FOLLOW_RANGE-50, player.getPosition().y);
    sf::Vector2f startPosition=enemy.getPosition();
    enemy.updateState();
    sf::Vector2f endPosition= enemy.getPosition();

    const std::type_info& type_info = typeid(*enemy.getStrategy());
    EXPECT_TRUE(type_info== typeid(RandomMove));
    ASSERT_TRUE(startPosition!=endPosition);
}

TEST_F(StrategyTest, Follow) {
    enemy.setPosition(player.getPosition().x-FOLLOW_RANGE+50, player.getPosition().y);
    int startDistance=calculateDistance();
    enemy.updateState();
    int endDistance = calculateDistance();
    const std::type_info& type_info = typeid(*enemy.getStrategy());
    EXPECT_TRUE(type_info== typeid(Follow));
    ASSERT_TRUE(startDistance>endDistance);
}


TEST_F(StrategyTest, Static) {
    enemy.setHp(1);
    sf::Vector2f startPosition=enemy.getPosition();
    enemy.updateState();
    EXPECT_TRUE(enemy.getPosition()==startPosition);
    const std::type_info& type_info = typeid(*enemy.getStrategy());
    ASSERT_TRUE(type_info== typeid(Static));
}