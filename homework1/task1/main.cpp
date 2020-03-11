#include "IntStack.h"
#include<iostream>
using namespace std;
int main()
{
    IntStack s;
    int t,n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>t;
        s.push(t);
    }



    /*IntStack input;
    input.push(34);
    input.push(3);
    input.push(31);
    input.push(98);
    input.push(92);
    input.push(23);*/



    IntStack tmpStack = sortStack(s);
    std::cout << "Sorted numbers are:\n";

    while (!tmpStack.empty())
    {
        cout << tmpStack.last()<< " ";
        tmpStack.pop();
    }
    return 0;
}

