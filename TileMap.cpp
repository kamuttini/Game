//
// Created by Filippo Paolini on 2019-06-16.
//

#include <fstream>
#include <sstream>
#include <random>
#include "TileMap.h"


TileMap::TileMap(std::string filename, bool collCheck) {
    std::ifstream openFile1;

    int  level[nTILES]={0};

    openFile1.open("assets/"+filename);

    for( int i=0; i<nTILES; i++)
        openFile1 >> level[i];

    openFile1.close();
    load("assets/sprites/mappa.png", sf::Vector2u(TIE_SIZE), level, MAP_WIDTH, MAP_HEIGHT);

    if(collCheck)
        loadColTiles(level, MAP_WIDTH, MAP_HEIGHT);
}
bool TileMap::load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height)
{
    // load the tileset texture
    if (!m_tileset.loadFromFile(tileset))
        return false;

    // resize the vertex array to fit the level size
    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(width * height * 4);

    // populate the vertex array, with one quad per tile
    for (unsigned int i = 0; i < width; ++i)
        for (unsigned int j = 0; j < height; ++j)
        {
            // get the current tile number
            int tileNumber = tiles[i + j * width];

            // find its position in the tileset texture
            int tu = (tileNumber -1)% (m_tileset.getSize().x / tileSize.x);
            int tv = (tileNumber -1)/ (m_tileset.getSize().x / tileSize.x);

            // get a pointer to the current tile's quad
            sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

            // define its 4 corners
            quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
            quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
            quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
            quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

            // define its 4 texture coordinates
            quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
            quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
            quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
            quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
        }

    return true;
}

void TileMap::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    {
        states.transform *= getTransform();
        states.transform.scale(2.5,2.5);
        states.texture = &m_tileset;
        target.draw(m_vertices, states);
    }

}

void TileMap::loadColTiles(const int* tiles,unsigned int width, unsigned int height) {
    for ( int i = 0; i < width*height; ++i)
    {
        if(tiles[i]==1)
            colTiles.push_back(i);
    }
}

