#include <iostream>
#include "Mob.h"

Mob::Mob()
{
    set_damage(0);
    set_health(0);
    set_enum(Enums::Mob);
}
Mob::Mob(const std::string other_name, const Point2D& other_location,const int other_damage,const int other_health):Entity(other_name,other_location)
{
    set_damage(other_damage);
    set_health(other_health);
    set_enum(Enums::Mob);
}
Mob::Mob(const Mob& object):Entity(object)
{
    set_damage(object.get_damage());
    set_health(object.get_health());
    set_enum(Enums::Mob);
}
bool Mob::isAlive() const
{
   if (get_health()> 0)
   {
       return true;
   }
   else
   {
       return false;
   }
}
void Mob::set_damage(const int other_damage)
{
    damage=other_damage;
}
int Mob::get_damage() const
{
    return damage;
}
void Mob::set_health(const int other_health)
{
    health=other_health;
}
int Mob::get_health() const
{
    return health;
}
void Mob::attack(Entity& object)
{
    if (object.get_enum()==0)
    {
        if (this->Entity::get_id()!=object.Entity::get_id())
        {
            if (getDistanceTo(object)<5)
            {
                int object_health = object.get_health();
                int attack_damage = this->get_damage();
                int result = object_health-attack_damage;
                object.set_health(result);
            }
        }
    }
}
void Mob::print() const
{
    std::cout<<"Mob"<<std::endl;
    Entity::print();
    std::cout <<"Damage: "<<get_damage()<<std::endl;
    std::cout <<"Health: "<<get_health()<<std::endl;
}
Mob* Mob::cloning() const
{
    return new Mob(*this);
}

