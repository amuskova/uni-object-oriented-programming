#include <iostream>
#include "GameCharacter.h"

#include "Warrior.h"

#include "Guardian.h"

#include "Wizzard.h"

using namespace std;

int main()
{
    Warrior w;
    Guardian g;
    Wizzard wiz;

    w.print();
    g.print();
    wiz.print();

    w.getattacked(5);
    w.print();

    w.getattacked(17);
    w.print();

    w.getattacked(100);
    w.print();

    cout << endl;

    g.getattacked(5);
    g.print();

    g.getattacked(17);
    g.print();

    g.getattacked(26);
    g.print();

    g.getattacked(3);
    g.print();

    g.getattacked(4);
    g.print();

    g.getattacked(-4);
    g.print();

    cout << endl;
    wiz.getattacked(5);
    wiz.print();

    wiz.getattacked(17);
    wiz.print();

    wiz.getattacked(26);
    wiz.print();

    wiz.getattacked(3);
    wiz.print();

    wiz.getattacked(4);
    wiz.print();

    wiz.getattacked(-4);
    wiz.print();

    wiz.getattacked(11);
    wiz.print();

    /*do
{
    char a;
    std::cout<<"Choose character or exit:"
    <<"\n (W) Warrior"
    <<"\n (G) Guardian"
    <<"\n (I) Wizzard"
    <<"\n (Q) Quit"<<std::endl;
    std::cin>>a;
    if(a=='W')
    {
        w.print();
    }
    else if(a=='G')
    {
        g.print();
    }
}*/
    return 0;
}

