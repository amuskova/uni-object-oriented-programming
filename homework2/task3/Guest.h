#pragma once

class Guest
{
private:
    char* ip_address;
public:
    Guest(const char*);
    Guest(const Guest&);
    Guest& operator=(const Guest&);
    ~Guest();
    void print() const;
    char* get_ip() const;
};

