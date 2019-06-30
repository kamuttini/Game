//
// Created by camut on 20/06/19.
//

#include "ClassRoom.h"

ClassRoom::ClassRoom(Room::type ID, Map& map): Room(ID), completed(false){
    switch (ID)
    {
        case classroom1:
            professor=std::make_unique<Professor>(Professor::type::prof1);
            sound.openFromFile("assets/music/completed.wav");
            break;

        case classroom2:
            professor=std::make_unique<Professor>(Professor::type::prof2);
            sound.openFromFile("assets/music/completed.wav");
            break;

        case classRoom3:
            professor=std::make_unique<Professor>(Professor::type::prof3);
            sound.openFromFile("assets/music/win.flac");
            break;
    }
    sound.setVolume(SOUNDTRACK_VOLUME);
    professor->addPositionObserver(&map);
    professor->getToken()->addPositionObserver(&map);
    if(ID==classroom1)
        professor->notifyPosition();
}

bool ClassRoom::activeUpdate(Player &player) {

    if(professor->getToken()->isActive())
        professor->getToken()->update();

    if(player.getRect().getGlobalBounds().intersects(professor->getRect().getGlobalBounds())){
        if(!completed) {
            if (!professor->checkToken()) {
                professor->talk();
                professor->getToken()->setActive(true, &player);
            }
            else {
                player.changeColMap();
                player.stats->updateScore(ROOM_COMPLETED);
                if(player.getLevelKills()==0)
                {
                    player.Pacifista();
                    player.notify();
                }
                player.setKilled(true);
                completed = true;
                sound.play();
                return true;
            }
        }
    }
    Room::activeUpdate(player);

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
    if(!completed)
        if(professor->getToken()->isActive())
            professor->getToken()->update();
}

const std::unique_ptr<Professor> &ClassRoom::getProfessor() const {
    return professor;
}
