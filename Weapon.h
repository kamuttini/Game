//
// Created by camut on 24/05/19.
//

#ifndef GAME_WEAPON_H
#define GAME_WEAPON_H

#include "DynamicComponent.h"
#include "Subject.h"


class Weapon: public DynamicComponent, public Subject  {
    enum id {cafe, pasta, book};

public:

    Weapon (std::list<CollisionObserver*>& targetList, sf::Color color1, sf::Vector2f targetDir, sf::Vector2f position, float s=3);
    Weapon(sf::Color color1,float s=7);
    ~Weapon(){};
    void attack();
    void addObserver(CollisionObserver* o) override ;
    void removeObserver(CollisionObserver* o) override;
    void notify() override;
    static void destroy(std::vector<std::unique_ptr<Weapon>>& enemy,std::vector<std::unique_ptr<Weapon>>::const_iterator iter1);
    std::unique_ptr<Weapon> clone() const;

protected:
    std::list<CollisionObserver*> characters;
    sf::Vector2f targetDir;
};


#endif //GAME_WEAPON_H
