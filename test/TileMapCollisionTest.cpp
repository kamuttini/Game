//
// Created by camut on 24/06/19.
//

#include "gtest/gtest.h"
#include "../Enemy.h"
#include "../Map.h"

class TileMapCollisionTest: public ::testing::Test {
public:
protected:
    TileMapCollisionTest():player(), testTime(sf::seconds(5)) {};
    ~TileMapCollisionTest(){};
    Player player;
    sf::Clock testClock;
    sf::Time testTime;
    Map map;

    void TearDown() override {
        std::cout<< "PLAYER-TILEMAP COLLISION TESTED ON RANDOM MOVEMENT FOR 5 SECONDS THAT VERIFIES PLAYER'S IN A WALKABLE TILE AND THAT HE CANNOT KEEP WALKING IN THE RANDOM DIRECTION DUE TO THE PRESENCE OF A COLLISION TILE";
    }
};


TEST_F(TileMapCollisionTest, Test) {
    player.addPositionObserver(&map);
    player.setPosition(CLASSROOM1_ORIGIN.x+350,CLASSROOM1_ORIGIN.y+140);
    srand((clock()));
    player.setOrientation(DynamicComponent::orientation::right);
    while(testClock.getElapsedTime()<testTime) {
        player.move();
    }
    sf::Vector2f startPosition=player.getPosition();
    player.move();
    sf::Vector2f endPosition= player.getPosition();
    ASSERT_TRUE(startPosition==endPosition);
}