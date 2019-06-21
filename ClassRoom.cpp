//
// Created by camut on 20/06/19.
//

#include "ClassRoom.h"

ClassRoom::ClassRoom(Room::type ID): Room(ID), completed(false){
    switch (ID)
    {
        case classroom1:
            professor=new Professor(Professor::type::prof1);
            break;

        case classroom2:
            professor=new Professor(Professor::type::prof2);
            break;

        case classRoom3:
            professor=new Professor(Professor::type::prof3);
            break;
    }
}

bool ClassRoom::activeUpdate(Player &player) {

    Room::activeUpdate(player);
    if(player.getRect().getGlobalBounds().intersects(professor->getRect().getGlobalBounds())){
        professor->talk();
        if(!completed) {
            player.changeColMap();
            completed=true;
            return true;
        }
    }
    return false;
}

void ClassRoom::draw(sf::RenderWindow &window) {
    Room::draw(window);
    professor->draw(window);
    if(professor->isTalking()) {
        window.draw(professor->message);
        professor->stopTalking();
    }
}






