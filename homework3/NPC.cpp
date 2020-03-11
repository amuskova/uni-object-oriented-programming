#include <iostream>
#include "NPC.h"

NPC::NPC():Entity()
{
    set_enum(Enums::NPC);
}
NPC::NPC(const std::string other_name, const Point2D& other_location):Entity(other_name, other_location)
{
    set_enum(Enums::NPC);
}
NPC::NPC(const NPC& object):Entity(object)
{
    set_enum(Enums::NPC);
}
bool NPC::isAlive() const
{
    Entity::isAlive();
}
void NPC::set_damage(const int other_damage){}

int NPC::get_damage() const
{
    return 0;
}
void NPC::set_health(const int other_health){}

int NPC::get_health() const
{
    return 0;
}
void NPC::print() const
{
    std::cout<<"NPC"<<std::endl;
    Entity::print();
}
NPC* NPC::cloning() const
{
    return new NPC(*this);
}

