//
// Created by camut on 04/06/19.
//

#ifndef GAME_DEF_H
#define GAME_DEF_H

//SETTINGS
#define WINDOW_HEIGHT 1000
#define WINDOW_WIDTH 1400
#define FRAME 60
#define SPLASHSCREEN_TIME sf::seconds(2.5)
#define nLAYERS 4
#define WEAPONALER_POSITION 260,200
#define SOUNDTRACK_VOLUME 32

//TIMES
#define PROF_MESSAGE_DISPLAY_TIME sf::seconds(2)
#define EXPLOSION_TIME sf::seconds(1)
#define WEAPONTOCOLLECT_DISPLAY_TIME sf::seconds(12)
#define WALKING_DELAY sf::seconds(.1f)


//TILEMAP
#define BACKGROUNDCOLOR sf::Color(123, 173, 44)
#define nTILES 7700
#define MAP_WIDTH 110
#define MAP_HEIGHT 70
#define TIE_SIZE 16,16

//PLAYER
#define PLAYER_START_POSITION 2050, 2300
#define PLAYER_HP 4
#define MAX_SPEED 32
#define MIN_SPEED 18

//ENEMY
#define ENEMY_HP 2
#define ATTACK_DELAY sf::seconds(4.f)
#define ATTACK_RANGE 400
#define FOLLOW_RANGE 300
#define FOLLOW_SPEED 8
#define RANDOMMOVE_SPEED 5

//ROOMS
#define CANTEEN_DIMENSION sf::Vector2f(940,800)
#define CANTEEN_ORIGIN sf::Vector2f(380,1200)
#define HALL_DIMENSION sf::Vector2f(630,980)
#define HALL_ORIGIN sf::Vector2f(1720,1368)
#define BAR_DIMENSION sf::Vector2f(1100,625)
#define BAR_ORIGIN sf::Vector2f(3080,1800)
#define CLASSROOM1_DIMENSION sf::Vector2f(700,280)
#define CLASSROOM1_ORIGIN sf::Vector2f(1690,840)
#define CLASSROOM2_DIMENSION sf::Vector2f(700,380)
#define CLASSROOM2_ORIGIN sf::Vector2f(2786,840)
#define CLASSROOM3_DIMENSION sf::Vector2f(800,300)
#define CLASSROOM3_ORIGIN sf::Vector2f(2150,90)
#define PROF1_POSITION sf::Vector2f(1950,800)
#define PROF2_POSITION sf::Vector2f(3150,900)
#define PROF3_POSITION sf::Vector2f(2370,90)
#define nHALLRECT 5

//SCORE
#define ROOM_COMPLETED 80
#define WOUNDED_ENEMY 10
#define DEAD_ENEMY 25
#define WEAPON_CAUGHT 5

#endif //GAME_DEF_H
