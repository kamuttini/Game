//
// Created by camut on 28/06/19.
//

#ifndef GAME_BADGE_H
#define GAME_BADGE_H

#include "SFML/Graphics.hpp"
#include "PlayerObserver.h"
#include "Text.h"
#include "Sprite.h"

class Badge {
public:
    enum type{killer,secchione, pacifista};
    explicit Badge(type ID);
    ~Badge(){delete(badgeText);};
    void draw(sf::RenderWindow& window);
    void setActive(bool val);
    bool isActive() const;

private:
    sf::Texture texture;
    sf::Sprite badgeSprite;
    Text* badgeText;
    bool active;
};


#endif //GAME_BADGE_H
