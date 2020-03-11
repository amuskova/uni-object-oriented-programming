#ifndef DNSRECORD_H_INCLUDED
#define DNSRECORD_H_INCLUDED
#endif // DNSRECORD_H_INCLUDED

class DNSRecord
{
private:
    char* domainName;
    char* ipAddress;
public:
    void setdomainName(char*);
    char* getdomainName() const;
    void setipAddress(char*);
    char* getipAddress() const;
    friend class DNSCach;
};
