//
// Created by camut on 07/06/19.
//

#include "gtest/gtest.h"
#include "/Users/filippopaolini/CLionProjects/Game/Player.h"


class PlayerTest : public ::testing::Test {

protected:
    virtual void TearDown() {}

    PlayerTest() : player(sidebar), weapon(Weapon::type::coffee) {};
    Sidebar sidebar;
    Player player;
    Weapon weapon;

    void SetUp() {
        weapon.addObserver(&player);
        weapon.getRect().setPosition(sf::Vector2f(player.getRect().getPosition()));
    }

};

TEST_F(PlayerTest, Collision) {
    // randomMove.move(enemy, playe
    player.setHp(2);
    weapon.notify();
    EXPECT_EQ(1, player.getHp());
    ASSERT_FALSE(player.isDestroyed()) << "player is alive";
}

TEST_F(PlayerTest, CollisionToDeath) {
    player.setHp(1);
    weapon.notify();
    ASSERT_TRUE(player.isDestroyed()) << "player is dead";
}