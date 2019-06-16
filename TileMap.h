//
// Created by Filippo Paolini on 2019-06-16.
//

#ifndef GAME_TILEMAP_H
#define GAME_TILEMAP_H


#include <SFML/Graphics.hpp>
#include "Tile.h"
#include "GameCharacter.h"
#include "Player.h"
#include <list>
#include <random>
#include "Def.h"


class TileMap : public sf::Drawable, public sf::Transformable
{
public:
    TileMap(){}
    ~TileMap(){}

    void InitMap(unsigned int w, unsigned int h, sf::Vector2u tS){
        width = w;
        height = h;
        tileSize = tS;
    }

    bool load(const std::string& tilesetFile, sf::RenderWindow &window, bool newLevel = false);



    void drawColTile(sf::RenderWindow &window){
        for(auto tiles:colTiles) {
            tiles->drawSingleTile(window);
        }
    }

    void LoadColMap(int preMap);

    std::vector<std::vector<int>> map;

    unsigned  int width;
    unsigned  int height;
    std::vector<Tile*> colTiles;

private:

    void draw(sf::RenderTarget& target, sf::RenderStates states)  const ;

    sf::VertexArray vertices;
    sf::Texture tileset;
    int init;

    sf::Vector2u tileSize = sf::Vector2u(175, 175);





};


#endif //GAME_TILEMAP_H
