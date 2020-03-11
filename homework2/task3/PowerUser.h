#include "User.h"
#pragma once

class PowerUser:public virtual User
{
protected:
    int reputation;
public:
    PowerUser(const char*,const char*,const char*,const char*);
    void rate(PowerUser&);
    void print() const;
    int get_reputation() const;
};
