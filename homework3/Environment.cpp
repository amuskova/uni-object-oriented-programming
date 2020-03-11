#include <iostream>
#include <string>
#include <vector>
#include "Environment.h"

void Environment::add(Entity& new_entity)
{
    box.push_back(new_entity.cloning());
}
Entity* Environment::getAt(const int position) const
{
    if (position>box.size())
    {
        return nullptr;
    }
    return box[position];
}
void Environment::removeAt(const int position)
{
    if (position<box.size())
    {
        box.erase(box.begin()+position);
    }
}
Entity* Environment::getClosestAliveEntity(const Entity& object, const Enums en)
{
    int index=-1;
    double range=-1.0;
    if (object.get_enum() == 0)
    {
        for (int i=0; i<box.size();i++)
        {
            if (box[i]->get_enum()==(int)en && object.get_id()!=box[i]->get_id() && box[i]->isAlive()==true)
            {
                if (range==-1.0)
                {
                    range=box[i]->getDistanceTo(object);
                    index=i;
                }
                else
                {
                    if (box[i]->getDistanceTo(object)<=range)
                    {
                        range=box[i]->getDistanceTo(object);
                        index=i;
                    }
                }
            }
        }
        if (index!=-1)
        {
            return box[index];
        }
    }
}
void Environment::generateEntities()
{
    Point3D one(1, 1, -9);
    Point2D two(-1, 11);
    Point2D three(-2, 3);
    Player player("Created player", one, 55, 240);
    Mob mob("Created mob", two, 34, 110);
    NPC npc("Created npc", three);
    add(player);
    add(mob);
    add(npc);
}
void Environment::destroyEntities()
{
    for (int i=0; i< box.size();i++)
    {
        delete box[i];
    }
    box.clear();
}
void Environment::print() const
{
    if(box.size()!=0)
    {
        for (int i = 0; i < box.size(); i++)
        {
            box[i]->print();
            std::cout << std::endl;
        }
    }
}
