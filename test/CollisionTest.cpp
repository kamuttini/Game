//
// Created by camut on 07/06/19.
//

#include "gtest/gtest.h"
#include "/home/camut/CLionProjects/game1/Game/Player.h"


class PlayerTest : public ::testing::Test {
protected:
    PlayerTest(): player(sidebar), weapon(Weapon::type::coffee), weaponToCollect(&player, Weapon::type::coffee) {};
    ~PlayerTest() override{};
    Sidebar sidebar;
    Player player;
    Weapon weapon;
    PlayerWeapon weaponToCollect;

    void SetUp() override{
        weapon.addObserver(&player);
        weapon.getRect().setPosition(player.getRect().getPosition());
        weaponToCollect.getRect().setPosition(player.getRect().getPosition());
    }

};

TEST_F(PlayerTest, Collision) {
    player.setHp(2);
    weapon.notify();
    EXPECT_EQ(1,player.getHp());
    EXPECT_TRUE(weapon.isDestroyed1());
    ASSERT_FALSE(player.isDestroyed1())<< "player is alive";
}

TEST_F(PlayerTest, CollisionToDeath) {
    player.setHp(1);
    weapon.notify();
    EXPECT_TRUE(weapon.isDestroyed1());
    ASSERT_TRUE(player.isDestroyed1())<< "player is dead";
}

TEST_F(PlayerTest, CatchWeapon) {
    weaponToCollect.notify();
    EXPECT_EQ(player.inventory.collectionSize(),1)<< "weapon was caught";
    ASSERT_FALSE(player.isDestroyed1())<< "player still alive2";
}

TEST_F(PlayerTest, MultipleCollisions) {
    player.setHp(4);
    Weapon weapon1(Weapon::type::book);
    weapon1.addObserver(&player);
    weapon1.getRect().setPosition(player.getRect().getPosition());
    Weapon weapon2(Weapon::type::pizza);
    weapon2.getRect().setPosition(player.getRect().getPosition());
    weapon2.addObserver(&player);
    weapon.notify();
    EXPECT_EQ(3,player.getHp());
    weapon1.notify();
    EXPECT_EQ(2,player.getHp());
    weapon2.notify();
    EXPECT_EQ(1,player.getHp());
    ASSERT_FALSE(player.isDestroyed1())<< "player is dead";
}

