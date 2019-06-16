//
// Created by Filippo Paolini on 2019-06-16.
//

#ifndef GAME_TILEMAP_H
#define GAME_TILEMAP_H


#include <SFML/Graphics.hpp>
#include "GameCharacter.h"
#include "Player.h"
#include <list>
#include <random>
#include "Def.h"


class TileMap : public sf::Drawable, public sf::Transformable
{
public:
    TileMap();
    bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);

private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // apply the transform
        states.transform *= getTransform();

        // apply the tileset texture
        states.texture = &m_tileset;

        // draw the vertex array
        target.draw(m_vertices, states);
    }

    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
};


#endif //GAME_TILEMAP_H
