#include <iostream>
#include "Point2D.h"
#include "Point2D.cpp"
#include "Point3D.h"
#include "Point3D.cpp"
#include "Entity.h"
#include "Entity.cpp"
#include "Player.h"
#include "Player.cpp"
#include "NPC.h"
#include "NPC.cpp"
#include "Mob.h"
#include "Mob.cpp"
#include "Environment.h"
#include "Environment.cpp"

using namespace std;

int main()
{
    Environment world;
    Point2D one(1, 0);
    Point2D two(2, 4);
    Point2D three(-2, 5);
    Point3D four;
    Point2D five(-5, 11);
    Point2D six(4, -2);
    Point3D seven(1, -1, 7);
    Point3D eight(8, -3, -1);
    Point3D nine(0, 1, 0);
    Point3D ten(1, 1, 1);

    Player player_one("Milena", one, 14, 21);
    Player player_two("Lili", seven, 31, 199);
    Mob mob_one("Ivan", eight, 55, 205);
    Mob mob_two("Jack", two, 20, 90);
    Mob mob_three("Koko", one, 15, 105);
    NPC npc_one("Rose", five);
    NPC npc_two("Vivi", four);

    player_one.print();

    cout<<endl;

    world.add(player_one);
    world.add(player_two);
    world.add(mob_one);
    world.add(mob_two);
    world.add(mob_three);
    world.add(npc_one);
    world.add(npc_two);
    world.print();
    cout<<endl;
    cout<<"Distance Milena->Lili: "<<player_one.getDistanceTo(player_two)<<endl;
    cout<<"Distance Ivan->Vivi: "<<mob_one.getDistanceTo(npc_two)<<endl;
    cout<<"Distance Ivan->Jack: "<<mob_one.getDistanceTo2D(mob_two)<<endl;

    player_one.attack(player_two);
    cout<<endl<<endl << "Attacked: "<<endl;
    player_two.print();

    world.generateEntities();

    cout<<endl <<endl<<endl;

    world.print();
    cout<<"Closest enemy: "<<endl;
    world.getClosestAliveEntity(player_one,Enums::Mob)->print();

    cout<<endl<<endl<<endl;

    mob_two.moveTo(npc_one);
    mob_two.print();

    cout<<endl;
    mob_two.attack(mob_three);
    mob_three.print();

    cout<<endl;
    player_one.attack(mob_three);
    mob_three.print();

    cout<<endl;
    mob_two.moveTo(four);
    mob_two.print();

    return 0;
}
