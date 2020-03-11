#include <iostream>
#include "User.h"
#include <cstring>

void User::code_pass()
{
    for (int i = 0; i < strlen(password); i++)
    {
        password[i]++;
    }
}
void User::encode_pass()
{
    for (int i = 0; i < strlen(password); i++)
    {
        password[i]--;
    }
}
User::User(const char* new_ip,const char* new_name,const char* new_pass,const char* new_title):Guest(new_ip)
{
    username=new char[strlen(new_name)+1];
    strcpy(username,new_name);
    password=new char[strlen(new_pass)+1];
    strcpy(password,new_pass);
    title=new char[strlen(new_title)+1];
    strcpy(title,new_title);

    code_pass();
}
User::User(const User& u):Guest(u)
{
    username=new char[strlen(u.username)+1];
    strcpy(username,u.username);
    password=new char[strlen(u.password)+1];
    strcpy(password,u.password);
    title=new char[strlen(u.title)+1];
    strcpy(title,u.title);
}
User& User::operator=(const User& u)
{
    if (this!=&u)
    {
        Guest::operator=(u);
        delete[] username;
        delete[] password;
        delete[] title;
        username=new char[strlen(u.username)+1];
        strcpy(username,u.username);
        password=new char[strlen(u.password)+1];
        strcpy(password,u.password);
        title=new char[strlen(u.title)+1];
        strcpy(title,u.title);
    }
    return *this;
}
User::~User()
{
    delete[] username;
    delete[] password;
    delete[] title;
}
void User::change_password(char* old_pass,const char* new_pass)
{
    encode_pass();
    int number=0;
    if (strlen(old_pass)!=strlen(password))
    {
        std::cout << "Not correct old password!" << std::endl;
    }
    else
    {
        for (int i=0;i<strlen(password);i++)
        {
            if (password[i]==old_pass[i])
            {
                number++;
            }

            else
            {
                number=0;
                break;
            }
        }
        if (number == strlen(password))
        {
            delete[] password;
            password=new char[strlen(new_pass)+1];
            strcpy(password,new_pass);
            std::cout << "New password accepted!" << std::endl;
        }
        else
        {
            std::cout << "Not correct old password!" << std::endl;
        }
    }
    code_pass();
}
void User::print() const
{
    std::cout << std::endl;
    Guest::print();
    std::cout << "Username -> " << get_username() << std::endl;
    std::cout << "Title -> " << get_title() << std::endl;
}
char* User::get_username() const
{
    return username;
}
char* User::get_title() const
{
    return title;
}

