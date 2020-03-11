#include "IntStack.h"
#include <iostream>


using namespace std;

IntStack::IntStack(){
top=-1;
a= new int[INIT_CAPACITY];
capacity=INIT_CAPACITY;
}


bool IntStack::empty() const{
return top==-1;
}

bool IntStack::full() const{
return top==capacity-1;
}

int IntStack::pop(){
if(empty())
{
    return 0;
}
return a[top--];
}
int IntStack::last() const{
if(empty()) return 0;

return a[top];
}

bool IntStack::push(int x){
if(full()) resize();
a[++top]=x;
return true;
}

void IntStack::resize(){
capacity*=2;
int* newa=new int[capacity];
for(int i=0;i<capacity/2;i++)
{
    newa[i]=a[i];
    delete[] a;
    a=newa;
}
}
void IntStack::print() const{
    if (empty()){std::cout<<"The stack is empty! "<<std::endl;}
    else{
        for(int i=top;i>0;i--)
        {
            std::cout<<a[i]<<std::endl;
        }
    }
}
IntStack::~IntStack(){
delete[] a;
}
int IntStack::size() const{
return top+1;
}
IntStack::IntStack(const IntStack& b)
{
    this-> a= new int[b.capacity];
    for(int i=0;i<b.size();i++)
    {
        a[i]=b.a[i];
    }
    capacity=b.capacity;
    top=b.top;
}
IntStack sortStack(IntStack input)
{
    IntStack tmpStack;

    while (!input.empty())
    {

        int tmp = input.last();
        input.pop();
        while (!tmpStack.empty() && tmpStack.last() > tmp)
        {
            input.push(tmpStack.last());
            tmpStack.pop();
        }

        tmpStack.push(tmp);
    }

    return tmpStack;
}

