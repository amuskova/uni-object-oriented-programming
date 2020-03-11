#pragma once
#include <string>

enum class Enums{Player,NPC,Mob};
static long long count_id=1000;
class Entity
{
protected:
    unsigned long long id;
    std::string name;
    Point2D* location=nullptr;
    void set_id(const unsigned long long other_id);
    void set_name(const std::string other_name);
public:
    Entity();
    Entity(const std::string other_name,const Point2D& other_location);
    Entity(const Entity& object);
    Entity& operator=(const Entity& object);
    virtual ~Entity();
    Enums enum_type;
    void set_enum(const Enums other_enum);
    int get_enum() const;
    void set_location(const Point2D* other_location);
    Point2D* get_location() const;
    virtual bool isAlive() const;
    unsigned long long get_id() const;
    std::string get_name() const;
    virtual int get_damage() const=0;
    virtual int get_health() const=0;
    virtual void set_damage(const int other_damage)=0;
    virtual void set_health(const int other_health)=0;
    double getDistanceTo2D(const Entity& object) const;
    double getDistanceTo(const Entity& object) const;
    void moveTo(const Point2D& object);
    void moveTo(const Entity& object);
    virtual void print() const;
    virtual Entity* cloning() const=0;
};
