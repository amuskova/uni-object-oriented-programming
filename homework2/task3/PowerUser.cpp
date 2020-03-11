#include <iostream>
#include "PowerUser.h"
#include <cstring>

PowerUser::PowerUser(const char* new_ip,const char* new_name,const char* new_pass,const char* new_title):User(new_ip,new_name,new_pass,new_title)
{
    reputation = 0;

}
void PowerUser::rate(PowerUser& pu)
{
    int number=0;
    if (strlen(username)<=strlen(pu.username))
    {
        for (int i=0;i<strlen(pu.username);i++)
        {
            if (pu.username[i]==username[i])
            {
                number++;
            }
            else
            {
                number=0;
                break;
            }
        }
        if (number!=strlen(pu.username))
        {
            pu.reputation++;
        }
    }
    else
    {
        for (int i=0; i<strlen(username); i++)
        {
            if (username[i]==pu.username[i])
            {
                number++;
            }
            else
            {
                number=0;
                break;
            }
        }
        if (number!=strlen(pu.username))
        {
            pu.reputation++;
        }
    }
}
void PowerUser::print() const
{
    User::print();
    std::cout << "Reputation -> " << get_reputation() << std::endl;
}
int PowerUser::get_reputation() const
{
    return reputation;
}
