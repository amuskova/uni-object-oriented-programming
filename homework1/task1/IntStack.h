#pragma once
const int INIT_CAPACITY = 8;
class IntStack{
private:
    int *a; //the main stack
    int top; //the index of the last input element
    int capacity; //the capacity of the stack
    friend IntStack sortStack(IntStack a);
public:
    IntStack();
    IntStack(const IntStack& b);
    ~IntStack();
    bool empty() const; //if the stack is empty
    bool push(int); //input int the stack
    int pop(); //cut elements from the stack
    int last() const; //the peek
    void print() const;
    int size() const;
private:
    bool full() const; //if the stack is full
    void resize();
};

