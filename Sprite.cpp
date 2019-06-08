//
// Created by camut on 07/06/19.
//

#include "Sprite.h"
#include "StaticComponent.h"
Sprite::Sprite(std::string filename, StaticComponent &object, int down, int up, int right, int left, int maxi, int w, int h)
        : object(object),
          width(w),
          height(h),
          iter(0),
          maxiter(maxi),
          right(right),left(left), down(down), up(up)
{
    texture.loadFromFile("assets/sprites/"+filename);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0,0,width,height));
    sprite.setScale(1.2,1.2);
    update();
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

