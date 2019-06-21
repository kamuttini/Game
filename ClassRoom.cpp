//
// Created by camut on 20/06/19.
//

#include "ClassRoom.h"

ClassRoom::ClassRoom(Room::type ID): Room(ID){
    switch (ID)
    {
        case classroom1:
            professor=new Professor(Professor::type::prof1);
            token=new Token(Token::type::token1);
            break;

        case classroom2:
            professor=new Professor(Professor::type::prof2);
            token=new Token(Token::type::token2);
            break;

        case bossRoom:
            professor=new Professor(Professor::type::prof3);
            token=new Token(Token::type::token3);

            break;
    }
}

bool ClassRoom::activeUpdate(Player &player) {

    Room::activeUpdate(player);
    if(player.getRect().getGlobalBounds().intersects(professor->getRect().getGlobalBounds())&& !completed){
        //if(professor->checkToken())
        player.changeColMap();
        //else
        //   professor->talk();
        completed=true;
        return true;
    }
    return false;
}

void ClassRoom::draw(sf::RenderWindow &window) {
    Room::draw(window);
    professor->draw(window);
    token->draw(window);
}






