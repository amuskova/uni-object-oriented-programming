#include "PowerUser.h"
#include "Vip.h"
#pragma once

class Admin:public PowerUser, public Vip
{
public:
    Admin(const char*,const char*,const char*,const char*);
    void set_username(const char*);
    void change_username(User&, char*);
    void print() const;
};
