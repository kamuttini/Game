//
// Created by camut on 24/05/19.
//

#ifndef GAME_WEAPON_H
#define GAME_WEAPON_H

#include "DynamicComponent.h"
#include "CollisionSubject.h"


class Weapon: public DynamicComponent, public CollisionSubject  {
public:
    enum type{pizza,coffee,book};

    Weapon(std::list<CollisionObserver *> &targetList, sf::Vector2f targetDir, sf::Vector2f position, type ID, float s = 3);
    Weapon(type ID, float s=7);
    ~Weapon()= default;
    void attack();
    void removeObserver(CollisionObserver* o) override;
    void notify() override;
    void destroy(std::vector<std::unique_ptr<Weapon>>& enemy,std::vector<std::unique_ptr<Weapon>>::const_iterator iter1);

    type getId() const;

protected:
    void addObserver(CollisionObserver* o) override ;
    std::string setSprite();

    std::list<CollisionObserver*> characters;
    sf::Vector2f targetDir;
    type ID;
    sf::Clock explosionClock;
    sf::Time explosionTime;
    bool exploded;
};


#endif //GAME_WEAPON_H
