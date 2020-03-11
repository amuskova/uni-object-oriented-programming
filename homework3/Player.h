#pragma once
#include "Entity.h"

class Player:public Entity
{
private:
    int damage;
    int health;
    virtual void set_damage(const int other_damage);
    virtual void set_health(const int other_health);
public:
    Player();
    Player(const std::string other_name,const Point2D& other_location,const int other_damage,const int other_health);
    Player(const Player& object);
    virtual int get_damage() const;
    virtual int get_health() const;
    virtual bool isAlive() const;
    void attack(Entity& object);
    virtual void print() const;
    virtual Player* cloning() const;
};
