//
// Created by Filippo Paolini on 2019-06-16.
//

#ifndef GAME_TILEMAP_H
#define GAME_TILEMAP_H


#include <SFML/Graphics.hpp>
#include <list>
#include <random>
#include "Def.h"


class TileMap : public sf::Drawable, public sf::Transformable
{
public:
    TileMap(std::string filename, bool collisionCheck=false);
    ~TileMap(){};
    bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);
    void loadColTiles(const int* tiles, unsigned int width, unsigned int height);
     std::list<int> colTiles;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
};


#endif //GAME_TILEMAP_H
