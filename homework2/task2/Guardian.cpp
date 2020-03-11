#pragma once
#include "Guardian.h"


Guardian::Guardian():GameCharacter()
{
    name="Guardian";
    HP=40;
    MP=25;
    AP=1;
    DP=3;
}

void Guardian::print() const
{
    GameCharacter::print();
}
