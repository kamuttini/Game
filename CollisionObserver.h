//
// Created by camut on 29/05/19.
//

#ifndef GAME_COLLISIONOBSERVER_H
#define GAME_COLLISIONOBSERVER_H


class CollisionObserver {
public:
    CollisionObserver(){};
    virtual ~CollisionObserver(){};
    virtual void update(sf::FloatRect rect)=0;

};


#endif //GAME_COLLISIONOBSERVER_H
