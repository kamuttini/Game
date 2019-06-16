//
// Created by Filippo Paolini on 2019-06-16.
//

#ifndef GAME_TILE_H
#define GAME_TILE_H


#include <SFML/Graphics.hpp>


class Tile {

public:
    explicit Tile(sf::Vector2f(position), bool w=true, bool in=true, bool o=false){
        tile.setSize(tileSize);
        tile.setFillColor(sf::Color::Transparent);
        tile.setPosition(position);
        walkable=w;
        inMap=in;
        open=o;


    };

    void drawSingleTile(sf::RenderWindow &window){
        window.draw(tile);
    };


    bool getWalk(){
        return walkable;
    }
    bool getInMap(){
        return inMap;
    }

    bool getOpen(){
        return open;
    }

    sf::RectangleShape tile;
    sf::Vector2f tileSize = sf::Vector2f(175.0f, 175.0f);

private:
    bool walkable;
    bool inMap;
    bool open;




};


#endif //GAME_TILE_H
