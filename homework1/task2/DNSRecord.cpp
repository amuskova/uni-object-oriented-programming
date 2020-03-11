#include "DNSRecord.h"
#include <iostream>
#include <cstring>

using namespace std;

void setdomainName(char* a)
{
    int size=strlen(a);
    char domainName= new char[size];
    for(int i=0;i<size;i++)
    {
        domainName[i]=a[i];
    }
}
char getdomainName() const
{
    return domainName;
}
void setipAddress(char*a)
{
    int size=strlen(a);
    char ipAddress=new char[size];
    for(int i=0;i<size;i++)
    {
        ipAddress[i]=a[i];
    }
}
char getipAddress() const
{
    return ipAddress;
}

