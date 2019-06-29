//
// Created by camut on 24/06/19.
//
#include "gtest/gtest.h"
#include "../Enemy.h"

class WeaponDirectionTest: public ::testing::Test {
public:
protected:
    WeaponDirectionTest(): enemy(player, ID, HALL_ORIGIN, HALL_DIMENSION){};
    ~WeaponDirectionTest(){};
    int calculateDistance(sf::RectangleShape& rect);
    Player player;
    Enemy enemy;

    int startDistance;
    int endDistance;
    Enemy::type ID=Enemy::type::student;

    void TearDown() override {
        std::cout<< "WEAPON DIRECTION TEST  ";

        std::cout<< "start distance:"<< startDistance;
        std::cout<< "   end distance:"<< endDistance;
    }
};

int WeaponDirectionTest::calculateDistance(sf::RectangleShape& rect) {
    return sqrt(pow(rect.getPosition().x- player.getPosition().x, 2) + pow(rect.getPosition().y- player.getPosition().y, 2));
}

TEST_F(WeaponDirectionTest, Test) {
    player.setPosition(2000,1900);
    enemy.setPosition(player.getPosition().x-ATTACK_RANGE+100, player.getPosition().y);
    Weapon weapon(enemy.targetList,enemy.calculateDirection(calculateDistance(enemy.getRect())), enemy.getPosition(),Weapon::type::book );
    startDistance=calculateDistance(weapon.getRect());
    weapon.attack();
    endDistance = calculateDistance(weapon.getRect());
    ASSERT_TRUE(startDistance>endDistance);
}