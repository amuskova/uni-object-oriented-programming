#pragma once
#include <string>
#include <vector>

class Environment
{
private:
    std::vector<Entity*> box;
public:
    void add(Entity& new_entity);

    Entity* getAt(const int position) const;
    void removeAt(const int position);
    Entity* getClosestAliveEntity(const Entity& object, const Enums en);
    void generateEntities();
    void destroyEntities();
    void print() const;
};
