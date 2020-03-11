#include <iostream>
#include <cstring>
#include "Guest.h"

Guest::Guest(const Guest& g)
{
    ip_address=new char[strlen(g.ip_address)+1];
    strcpy(ip_address,g.ip_address);
}
Guest::Guest(const char* ip)
{
    ip_address=new char[strlen(ip)+1];
    strcpy(ip_address,ip);
}
Guest& Guest::operator=(const Guest& g)
{
    if (this!=&g)
    {
        delete[] ip_address;
        ip_address=new char[strlen(g.ip_address)+1];
        strcpy(ip_address,g.ip_address);
    }
    return *this;
}
Guest::~Guest()
{
    delete[] ip_address;
}
void Guest::print() const
{
    std::cout << "IP -> " << get_ip() << std::endl;
}

char* Guest::get_ip() const
{
    return ip_address;
}

