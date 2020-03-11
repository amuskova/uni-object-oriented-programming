#include "GameCharacter.h"
#include <cstring>
#include <iostream>

GameCharacter::GameCharacter()
{
    name=new char[1];
    name[0]='\0';
    HP=0;
    MP=0;
    AP=0;
    DP=0;
}
GameCharacter::GameCharacter(const GameCharacter& rhs)
{
    int size=strlen(rhs.name);
    name=new char[size+1];
    strcpy(name,rhs.name);
    HP=rhs.HP;
    MP=rhs.MP;
    AP=rhs.AP;
    DP=rhs.DP;
}
GameCharacter& GameCharacter:: operator=(const GameCharacter& rhs)
    {
        if(this!= &rhs)
        {
            delete[] name;
             int size=strlen(rhs.name);
             name=new char[size+1];
             strcpy(name,rhs.name);
             HP=rhs.HP;
             MP=rhs.MP;
             AP=rhs.AP;
             DP=rhs.DP;
        }
        return *this;
    }
GameCharacter::~GameCharacter()
{
    delete[] name;
}
void GameCharacter:: getattacked(int attack)
{
    if((HP+DP-attack)>=0 && attack>=0)
    {
       HP=HP-attack+DP;
    }
}

char* GameCharacter::get_name() const
{
    return name;
}
int GameCharacter::get_HP() const
{
    return HP;
}
int GameCharacter::get_MP() const
{
    return MP;
}
int GameCharacter::get_AP() const
{
    return AP;
}
int GameCharacter::get_DP() const
{
    return DP;
}

void GameCharacter::print() const
{
    std::cout<<"Name: "<<get_name();
    std::cout<<"\n HP: "<<get_HP();
    std::cout<<"\n MP: "<<get_MP();
    std::cout<<"\n AP: "<<get_AP();
    std::cout<<"\n DP: "<<get_DP();
    std::cout<<std::endl;
}
