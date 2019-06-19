//
// Created by camut on 07/06/19.
//

#include "Sprite.h"
#include "StaticComponent.h"
Sprite:: Sprite(std::string filename, StaticComponent &object, int down, int up, int right, int left, int maxi, float w, float h):
          object(object),
          width(w),
          height(h),
          iter(0),
          maxiter(maxi),
          right(right),left(left), down(down), up(up)
{
    texture.loadFromFile("assets/sprites/"+filename);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0,0,width,height));
    update();
    explosionTexture.loadFromFile("assets/sprites/boom.png");
}

void Sprite::update() {
    sprite.setPosition(object.getRect().getPosition().x-(width/2), object.getRect().getPosition().y-(height/2));
}

void Sprite::draw(sf::RenderWindow &window) {
    window.draw(sprite);
}

void Sprite::animate() {

    switch (object.getDirection())
    {
        case StaticComponent::orientation::left:
            sprite.setTextureRect(sf::IntRect(iter * width, left*height, width, height));
            break;
        case StaticComponent::orientation::up:
            sprite.setTextureRect(sf::IntRect(iter * width, up*height, width, height));
            break;
        case StaticComponent::orientation ::down:
            sprite.setTextureRect(sf::IntRect(iter * width, down*height, width, height));
            break;
        case StaticComponent::orientation ::right:
            sprite.setTextureRect(sf::IntRect(iter * width, right*height, width, height));
            break;

    }
    iter++;

    if (iter == maxiter)
        iter = 0;
    update();
}

void Sprite::setScale(sf::Vector2f vector) {
    sprite.setScale(vector);
}

void Sprite::explode()  {
if(explosionClock.getElapsedTime()>explosionDelay) {
    sprite.setTextureRect(sf::IntRect(iter * width, left * height, width, height));
    iter++;

    if (iter == maxiter)
        iter = 0;
    explosionClock.restart();

}
}

void Sprite::setExplodeTexture() {

    sprite.setTexture(explosionTexture);
    sprite.setScale(0.8,0.8);
    width=155;
    height=155;
    maxiter=9;
}


