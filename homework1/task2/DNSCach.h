#ifndef DNSCACH_H_INCLUDED
#define DNSCACH_H_INCLUDED
#endif // DNSCACH_H_INCLUDED

class DNSCach
{
    private:
    int *a; //the main stack
    int top; //the index of the last input element
    int capacity; //the capacity of the stack
    int* values;
    int size;
    int maxSize;


public:
    DNSCach();
    DNSCach(const DNSCach& b);
    char operator=(char*) const;
    ~DNSCach();
    bool empty() const; //if the stack is empty
    bool add(char*); //input int the stack
    void flush() const;
    char lookup(char*); //cut elements from the stack
    int last() const; //the peek
    void print() const;
    void push_back(int);
    int pop_back();
    char* get_size() const;

private:
    bool full() const; //if the stack is full
    void resize();

};




