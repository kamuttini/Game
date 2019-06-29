//
// Created by camut on 29/06/19.
//

#include <gtest/gtest.h>
#include "../Player.h"
#include "../HUD.h"
#include "../ClassRoom.h"

class BadgeTest : public ::testing::Test {
protected:
    BadgeTest(): weapon(player,PlayerWeapon::type::book,HALL_ORIGIN,HALL_DIMENSION), classRoom(ClassRoom::type::classroom1){};
    ~BadgeTest(){};
    HUD hud;
    Player player;
    PlayerWeapon weapon;
    ClassRoom classRoom;
    void SetUp() override {
        player.addObserver(&hud);
    }
};

TEST_F(BadgeTest, kills) {
    for(int i=0; i<KILLS; i++)
    {
        EXPECT_FALSE(hud.getBadge()[0].isActive());
        player.setKilled();
    }
    EXPECT_TRUE(hud.getBadge()[0].isActive());
}

TEST_F(BadgeTest, secchione) {
    for(int i=0; i<SECCHIONE+1; i++)
    {
        EXPECT_FALSE(hud.getBadge()[1].isActive());
        weapon.setPosition(player.getPosition().x,player.getPosition().y);
        weapon.notify();
    }
    EXPECT_TRUE(hud.getBadge()[1].isActive());
}

TEST_F(BadgeTest, pacifista) {
    classRoom.getProfessor()->getToken()->setActive(true, &player);
    classRoom.getProfessor()->getToken()->setPosition(player.getPosition().x,player.getPosition().y);
    classRoom.getProfessor()->getToken()->update();
    player.setPosition(classRoom.getProfessor()->getPosition().x,classRoom.getProfessor()->getPosition().y);
    classRoom.activeUpdate(player);

    EXPECT_TRUE(hud.getBadge()[2].isActive());
}