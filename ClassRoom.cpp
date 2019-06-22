//
// Created by camut on 20/06/19.
//

#include "ClassRoom.h"

ClassRoom::ClassRoom(Room::type ID): Room(ID), completed(false){
    switch (ID)
    {
        case classroom1:
            professor=new Professor(Professor::type::prof1);
            sound.openFromFile("assets/music/completed.wav");
            break;

        case classroom2:
            professor=new Professor(Professor::type::prof2);
            sound.openFromFile("assets/music/completed.wav");
            break;

        case classRoom3:
            professor=new Professor(Professor::type::prof3);
            sound.openFromFile("assets/music/win.flac");
            break;
    }
    sound.setVolume(30);
}

bool ClassRoom::activeUpdate(Player &player) {

    Room::activeUpdate(player);
    if(professor->getToken()->isActive())
        professor->getToken()->update();

    if(player.getRect().getGlobalBounds().intersects(professor->getRect().getGlobalBounds())){
        if(!professor->checkToken()) {
            professor->talk();
            professor->getToken()->setActive(true,&player);
        }
        else
            if(!completed) {
                player.changeColMap();
                player.stats.updateScore(80);
                completed=true;
                sound.play();
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
    if(professor->getToken()->isActive())
        professor->getToken()->draw(window);
}

void ClassRoom::update() {
    Room::update();
    if(professor->getToken()->isActive())
        professor->getToken()->update();
}