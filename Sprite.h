//
// Created by camut on 07/06/19.
//

#ifndef GAME_SPRITE_H
#define GAME_SPRITE_H

#include <SFML/Graphics.hpp>
#include <string>

class StaticComponent;

class Sprite {
public:
    Sprite(std::string filename, StaticComponent &object, int down=0, int up=0, int right=0, int left=0, int i=3, float w = 32, float h = 32);

    ~Sprite()= default;;
    void update();
    void animate();
    void draw(sf::RenderWindow& window);
    void setScale(sf::Vector2f vector);
    void setExplodeTexture();
    void explode();

private:
    StaticComponent& object;
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Texture explosionTexture;
    sf::Clock explosionClock;
    sf::Time explosionDelay=sf::seconds(0.1);
    int iter, maxiter;
    float height, width;
    int left,right,up,down;
};


#endif //GAME_SPRITE_H
