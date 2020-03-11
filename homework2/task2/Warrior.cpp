#pragma once
#include "Warrior.h"

Warrior::Warrior():GameCharacter()
{
    name="Warrior";
    HP=20;
    MP=5;
    AP=4;
    DP=1;
}

void Warrior::print() const
{
    GameCharacter::print();
}

