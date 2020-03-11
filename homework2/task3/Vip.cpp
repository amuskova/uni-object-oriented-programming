#include <iostream>
#include "Vip.h"
#include <cstring>

Vip::Vip(const char* new_ip,const char* new_name,const char* new_pass,const char* new_title):User(new_ip,new_name,new_pass,new_title)
{

}
void Vip::set_title(const char* new_title)
{
    if (new_title==nullptr)
    {
        delete[] new_title;
        title=nullptr;
        return;
    }
    delete[] title;
    title=new char[strlen(new_title)+1];
    strcpy(title,new_title);
}
void Vip::print() const
{
    User::print();
}

