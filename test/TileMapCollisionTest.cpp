//
// Created by camut on 24/06/19.
//

#include "gtest/gtest.h"
#include "../Enemy.h"

class TileMapCollisionTest: public ::testing::Test {
public:
protected:
    TileMapCollisionTest():player(sidebar), testTime(sf::seconds(5)) {};
    ~TileMapCollisionTest(){};
    HUD sidebar;
    Player player;
    sf::Clock testClock;
    sf::Time testTime;

    void TearDown() override {
        std::cout<< "PLAYER-TILEMAP COLLISION TESTED ON RANDOM MOVEMENT FOR 5 SECONDS THAT VERIFIES PLAYER'S IN A WALKABLE TILE AND THAT HE CANNOT KEEP WALKING IN THE RANDOM DIRECTION DUE TO THE PRESENCE OF A COLLISION TILE";
    }
};


TEST_F(TileMapCollisionTest, Test) {
    player.setPosition(PLAYER_START_POSITION);
    srand((clock()));
    player.setOrientation(DynamicComponent::orientation(rand() % 4));
    while(testClock.getElapsedTime()<testTime) {
        player.move();
    }
    EXPECT_FALSE(player.checkBorders(player.getDirection()));
    ASSERT_TRUE(player.checkPosition(player.findTile()));
}