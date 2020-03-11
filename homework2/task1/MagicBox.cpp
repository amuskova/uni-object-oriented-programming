#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "MagicBox.h"

template <class T>
MagicBox<T>::MagicBox()
{
    size=0;
    maxSize=10;
    values= new T[maxSize];
}

template <class T>
MagicBox<T>::MagicBox(const MagicBox& rhs)
{
    size=rhs.size;
    maxSize=rhs.maxSize;
    values=new T[maxSize];
    for (int i=0; i<size; i++)
    {
        values[i]=rhs.values[i];
    }
}
template <class T>
MagicBox<T>&  MagicBox<T>::operator=(const MagicBox& rhs)
{
    if(this != &rhs)
    {
        delete[] values;
        size=rhs.size;
        maxSize=rhs.maxSize;
        values=new T[maxSize];
        for (int i=0; i<size; i++)
        {
            values[i]=rhs.values[i];
        }
    }
    return *this;
}

template <class T>
MagicBox<T>::~MagicBox()
{
    delete[] values;
}
template <class T>
void MagicBox<T>::resize()
{
    maxSize*=2;
    T* new_values=new T[maxSize];
    for (int i=0; i<size; i++)
    {
        new_values[i]=values[i];
    }
    delete[] values;
    values=new_values;
}
template <class T>
void MagicBox<T>::insert(T value)
{
    if(size==maxSize) resize();

    values[size]=value;
    size++;
}

int number_winner=0;
template <class T>
void MagicBox<T>::pop()
{
    if(size==0)
    {
        std::cout<<"You can not pop element from empty box!";
    }
    else
    {
       srand ( time(NULL) );
       int random = rand() % size;
       winner = values[random];
       for(int i=random; i<size-1 ;i++)
       {
          values[i]=values[i+1];
       }
       number_winner++;
       size--;
    }
}
template <class T>
void MagicBox<T>::list() const
{
    for(int i=0;i<size;i++)
    {
        std::cout<<values[i]<<" ";
    }
    if(number_winner>0)
    {
        std::cout<<std::endl;
        std::cout<<"The winner is: "<<winner;
        number_winner=0;
    }
    std::cout<<std::endl;
}

template <class T>
int MagicBox<T>::get_size() const
{
    return size;
}

template <class T>
int MagicBox<T>::get_maxSize() const
{
    return maxSize;
}

