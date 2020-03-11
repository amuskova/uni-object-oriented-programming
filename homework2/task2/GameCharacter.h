#pragma once

class GameCharacter
{
protected:
    char* name;
    int HP;
    int MP;
    int AP;
    int DP;
    GameCharacter();

public:
    GameCharacter(const GameCharacter&);
    GameCharacter& operator=(const GameCharacter&);
    ~GameCharacter();
    void getattacked(int);

    char* get_name() const;
    int get_HP() const;
    int get_MP() const;
    int get_AP() const;
    int get_DP() const;

    void print() const;

};
