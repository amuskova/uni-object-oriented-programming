#pragma once
#include "Entity.h"

class NPC:public Entity
{
private:
    virtual void set_damage(const int other_damage);
    virtual int get_health() const;
    virtual void set_health(const int other_health);
    virtual int get_damage() const;
public:
    NPC();
    NPC(const std::string other_name,const Point2D& other_location);
    NPC(const NPC& object);
    virtual bool isAlive() const;
    virtual void print() const;
    virtual NPC* cloning() const;
};
