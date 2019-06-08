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
    Sprite(std::string filename, StaticComponent &object, int down=0, int up=0, int right=0, int left=0, int i=3, int w = 32, int h = 32);

    ~Sprite()= default;;
    void update();
    void animate();
    void draw(sf::RenderWindow& window);
    void setScale(sf::Vector2f vector);

private:
    StaticComponent& object;
    sf::Sprite sprite;
    sf::Texture texture;
    int iter, maxiter;
    int height, width;
    int left,right,up,down;
};


#endif //GAME_SPRITE_H
