#pragma once
#include "Wizzard.h"

Wizzard::Wizzard():GameCharacter()
{
    name="Wizzard";
    HP=30;
    MP=30;
    AP=2;
    DP=2;
}

void Wizzard::print() const
{
    GameCharacter::print();
}
