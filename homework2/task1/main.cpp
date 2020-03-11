#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "MagicBox.hpp"

using namespace std;

int main()
{

    MagicBox<int> p;
    p.insert(2);
    p.insert(45);
    p.insert(18);
    p.insert(16);
    p.insert(5);

    p.list();
    cout<<endl;
    p.pop();
    p.list();


    return 0;
}
