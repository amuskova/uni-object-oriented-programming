#include <iostream>
#include <cmath>
#include <string>
#include "Entity.h"

Entity::Entity()
{
    set_id(count_id);
    set_name("No name");
    set_location(nullptr);
    count_id++;
}
Entity::Entity(const std::string other_name,const Point2D& other_location)
{
    set_id(count_id);
    set_name(other_name);
    set_location(&other_location);
    count_id++;
}
Entity::Entity(const Entity& object)
{
    set_id(count_id);
    set_name(object.get_name());
    set_location(object.get_location());
    count_id++;
}
Entity& Entity::operator=(const Entity& object)
{
    if (this!=&object)
    {
        set_name(object.get_name());
        set_location(object.get_location());
    }
    return *this;
}
Entity::~Entity()
{
    delete location;
}
void Entity::set_enum(const Enums other_enum)
{
    enum_type=other_enum;
}
int Entity::get_enum() const
{
    if (enum_type == Enums::Player)
    {
        return 0;
    }
    if (enum_type == Enums::NPC)
    {
        return 1;
    }
    if (enum_type == Enums::Mob)
    {
        return 2;
    }
}
void Entity::set_location(const Point2D* other_location)
{
    if (other_location==nullptr)
    {
        delete this->location;
        this->location = nullptr;
        return;
    }
    delete this->location;
    this->location = other_location->clone();
}
Point2D* Entity::get_location() const
{
    return this->location;
}
bool Entity::isAlive() const
{
    return true;
}
void Entity::set_id(const unsigned long long other_id)
{
    id=other_id;
}
unsigned long long Entity::get_id() const
{
    return id;
}
void Entity::set_name(const std::string other_name)
{
    name=other_name;
}
std::string Entity::get_name() const
{
    return name;
}
double Entity::getDistanceTo2D(const Entity& object) const
{
    return get_location()->Point2D::getDistanceTo(*object.get_location());
}
double Entity::getDistanceTo(const Entity& object) const
{
    if (dynamic_cast<Point3D*>(this->get_location())==nullptr || dynamic_cast<Point3D*>(object.get_location())==nullptr)//if one of them is 2D
    {
        return get_location()->Point2D::getDistanceTo(*object.get_location());
    }
    return get_location()->getDistanceTo(*object.get_location());
}
void Entity::moveTo(const Point2D& object)
{
    if (this->get_location()!=&object)
    {
        set_location(&object);
    }
}
void Entity::moveTo(const Entity& object)
{
    if (object.get_location()!=this->get_location())
    {
        set_location(object.get_location());
    }
}
void Entity::print() const
{
    std::cout<<"Number id: "<<get_id()<<std::endl;
    std::cout<<"Name: "<<get_name()<<std::endl;
    if (get_location()==nullptr)
    {
        std::cout<<"No points"<<std::endl;
    }
    else
    {
        get_location()->print();
    }
}
