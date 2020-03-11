#include <iostream>
#include "DNSCach.h"
#include <cstring>

DNSCach::DNSCach()
{
    domainName=new char[5];
    domainName[0]='\0';
    ipAddress=new char[5];
    ipAddress[0]='\0';
}
DNSCach::DNSCach(const DNSCach& b)
{
    int size=strlen(b);
    domainName=new char[size];
    strcpy(domainName,b);
}
DNSCach& DNSCach::operator=(const DNSCach& rhs)
{
    if(this != &rhs)
    {
        delete[] values;

        maxSize = rhs.maxSize;
        size = rhs.size;

        values = new int[maxSize];

        for(int i = 0; i < size; i++)
        {
            values[i] = rhs.values[i];
        }
    }
    return *this;
}
DNSCach::~DNSCach()
{
    delete[] domainName;
}


DNSCach::DNSCach():size(0), maxSize(10)
{
    values = new int[maxSize];
}

DNSCach::DNSCach(const DNSCach& rhs): size(rhs.size), maxSize(rhs.maxSize)
{
    values = new int[maxSize];

    for(int i = 0; i < size; i++)
    {
        domainName[i] = rhs.domainName[i];
    }
}
DNSCach& DNSCach::operator=(const DNSCach& rhs)
{
    if(this != &rhs)
    {
        delete[] values;

        maxSize = rhs.maxSize;
        size = rhs.size;

        values = new int[maxSize];

        for(int i = 0; i < size; i++)
        {
            values[i] = rhs.values[i];
        }
    }
    return *this;
}
void DNSCach::resize()
{
    maxSize*=2;
    int* newValues = new int[maxSize];

    for(int i = 0; i < size; i++)
    {
        newValues[i] = values[i];
    }

    delete[] values;

    values = newValues;
}

void DNSCach::resize(char* val)
{
    if(size == maxSize)
        resize();

    values[size] = val;
    size++;
}
void DNSCach::add(char* values,int pos)
{
    if(pos <= size)
    {
        if(size == maxSize)
            resize();

        for(int i = size; i > pos; i--)
        {
            values[i] = values[i-1];
        }
        values[pos] = val;
        size++;
    }
}

void DNSCach::flush(int pos)
{
    if(pos <= size)
    {
        for(int i = pos; i < size-1; i++)
        {
            values[i] = values[i+1];
        }
        size--;
    }
    else
        std::cout << "Invalid position \n";
}

void DNSCach::print(char* values) const
{
    for(int i = 0; i < size; i++)
        std::cout << values[i] << " ";

    std::cout << std::endl;
}




int DNSCach::pop_back()
{
    if(size != 0)
    {
        size--;
        return values[size];
    }
    else
        std::cout << "No values to pop \n";
}



char* DNSCach::get_size(char* c) const
{
    return strlen(c);
}


