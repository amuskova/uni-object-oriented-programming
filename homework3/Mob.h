#pragma once
#include "Entity.h"

class Mob:public Entity
{
private:
    int damage;
    int health;
    virtual void set_damage(const int other_damage);
    virtual void set_health(const int other_health);
public:
    Mob();
    Mob(const std::string other_name,const Point2D& other_location,const int other_damage,const int other_health);
    Mob(const Mob& object);
    virtual bool isAlive() const;
    virtual int get_damage() const;
    virtual int get_health() const;
    void attack(Entity& object);
    virtual void print() const;
    virtual Mob* cloning() const;
};
