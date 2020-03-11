#include <iostream>
#include "Admin.h"
#include <cstring>
Admin::Admin(const char* new_ip,const char* new_name,const char* new_pass,const char* new_title):Vip(new_ip,new_name,new_pass,new_title), PowerUser(new_ip,new_name,new_pass,new_title), User(new_ip,new_name,new_pass,new_title)
{

}
void Admin::set_username(const char* new_name)
{
    if (new_name==nullptr)
    {
        delete[] username;
        username = nullptr;
        return;
    }
    delete[] username;
    username=new char[strlen(new_name) + 1];
    strcpy(username, new_name);
}
void Admin::change_username(User &user,char* new_name)
{
    delete[] user.username;
    user.username=new char[strlen(new_name)+1];
    strcpy(user.username,new_name);
}
void Admin::print() const
{
    PowerUser::print();
}
