#include "Guest.h"
#pragma once

class User:public Guest
{
protected:
    char* username;
    char* password;
    char* title;
    void code_pass();
    void encode_pass();
    friend class Admin;
public:
    User(const char*,const char*,const char*,const char*);
    User(const User&);
    User& operator=(const User&);
    ~User();
    void change_password(char*, const char*);
    void print() const;
    char* get_username() const;
    char* get_title() const;
};

