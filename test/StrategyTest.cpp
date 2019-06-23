//
// Created by camut on 14/06/19.
//

#include <cmath>
#include "gtest/gtest.h"
#include "/home/camut/CLionProjects/game1/Game/Enemy.h"
#include "/home/camut/CLionProjects/game1/Game/RandomMove.h"
#include "/home/camut/CLionProjects/game1/Game/Follow.h"
#include "/home/camut/CLionProjects/game1/Game/Static.h"


class StrategyTest : public ::testing::Test {
protected:
    StrategyTest(): player(sidebar), enemy(&player, ID, HALL_ORIGIN, HALL_DIMENSION){};
    ~StrategyTest() {};
    int calculateDistance();
    HUD sidebar;
    Player player;
    Enemy enemy;
    Enemy::type ID=Enemy::type::student;

    void SetUp() override{
        player.getRect().setPosition(100,100);
        enemy.setWalkingDelay(0);
    }
};

int StrategyTest::calculateDistance() {
    return sqrt(pow(enemy.getRect().getPosition().x- player.getRect().getPosition().x, 2) + pow(enemy.getRect().getPosition().x- player.getRect().getPosition().x, 2));
}

TEST_F(StrategyTest, RandomMove) {
    enemy.getRect().setPosition(900,900);

    sf::Vector2f startPosition=enemy.getRect().getPosition();
    enemy.move();
    sf::Vector2f endPosition= enemy.getRect().getPosition();

    const std::type_info& type_info = typeid(*enemy.getStrategy());
    EXPECT_TRUE(type_info== typeid(RandomMove));
    ASSERT_TRUE(startPosition!=endPosition);
}

TEST_F(StrategyTest, Follow) {
    enemy.getRect().setPosition(300,300);

    int startDistance=calculateDistance();
    enemy.move();
    int endDistance = calculateDistance();

    const std::type_info& type_info = typeid(*enemy.getStrategy());
    EXPECT_TRUE(type_info== typeid(Follow));
    ASSERT_TRUE(startDistance>endDistance);
}


TEST_F(StrategyTest, Static) {
    enemy.setHp(1);
    sf::Vector2f startPosition=enemy.getRect().getPosition();
    enemy.move();
    EXPECT_TRUE(enemy.getRect().getPosition()==startPosition);
    const std::type_info& type_info = typeid(*enemy.getStrategy());
    ASSERT_TRUE(type_info== typeid(Static));
}