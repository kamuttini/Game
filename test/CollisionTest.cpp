//
// Created by camut on 07/06/19.
//

#include "gtest/gtest.h"
#include "../Player.h"



class PlayerTest : public ::testing::Test {
protected:
    PlayerTest(): player(sidebar), weapon(Weapon::type::coffee), weaponToCollect(player, Weapon::type::coffee, HALL_ORIGIN, HALL_DIMENSION) {};
    ~PlayerTest() override{};
    HUD sidebar;
    Player player;
    Weapon weapon;
    PlayerWeapon weaponToCollect;

    void SetUp() override{
        weapon.addObserver(&player);
        weapon.setPosition(player.getPosition().x, player.getPosition().y);
        weaponToCollect.setPosition(player.getPosition().x, player.getPosition().y);
    }

};

TEST_F(PlayerTest, Collision) {
    player.setHp(2);
    weapon.notify();
    EXPECT_EQ(1,player.getHp());
    EXPECT_TRUE(weapon.isDestroyed());
    ASSERT_FALSE(player.isDestroyed())<< "player is alive";
}

TEST_F(PlayerTest, CollisionToDeath) {
    player.setHp(1);
    weapon.notify();
    EXPECT_TRUE(weapon.isDestroyed());
    ASSERT_TRUE(player.isDestroyed())<< "player is dead";
}

TEST_F(PlayerTest, CatchWeapon) {
    weaponToCollect.notify();
    EXPECT_EQ(player.inventory.collectionSize(),1)<< "weapon was caught";
    ASSERT_FALSE(player.isDestroyed())<< "player still alive2";
}

TEST_F(PlayerTest, MultipleCollisions) {
    player.setHp(4);
    Weapon weapon1(Weapon::type::book);
    weapon1.addObserver(&player);
    weapon1.setPosition(player.getPosition().x, player.getPosition().y);
    Weapon weapon2(Weapon::type::pizza);
    weapon2.setPosition(player.getPosition().x, player.getPosition().y);
    weapon2.addObserver(&player);
    weapon.notify();
    weapon1.notify();
    weapon2.notify();
    ASSERT_FALSE(player.isDestroyed())<< "player is dead";
}

