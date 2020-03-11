#include <iostream>
#include "Player.h"

Player::Player():Entity()
{
    set_damage(0);
    set_health(0);
    set_enum(Enums::Player);
}
Player::Player(const std::string other_name,const Point2D& other_location,const int other_damage,const int other_health):Entity(other_name,other_location)
{
    set_damage(other_damage);
    set_health(other_health);
    set_enum(Enums::Player);
}
Player::Player(const Player& object):Entity(object)
{
    set_damage(object.get_damage());
    set_health(object.get_health());
    set_enum(Enums::Player);
}
bool Player::isAlive() const
{
   if (get_health()>0)
   {
       return true;
   }
   else
   {
       return false;
   }
}
void Player::set_damage(const int other_damage)
{
    damage=other_damage;
}
int Player::get_damage() const
{
    return damage;
}
void Player::set_health(const int other_health)
{
    health=other_health;
}
int Player::get_health() const
{
    return health;
}
void Player::attack(Entity& object)
{
    if (object.get_enum()==0 || object.get_enum()==2)
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
void Player::print() const
{
    std::cout<<"Player"<<std::endl;
    Entity::print();
    std::cout<<"Damage: "<< get_damage()<<std::endl;
    std::cout<<"Health: "<<get_health()<<std::endl;
}

Player* Player::cloning() const
{
    return new Player(*this);
}
