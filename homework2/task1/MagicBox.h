#pragma once

template <class T>
class MagicBox
{
private:
    T* values;
    T winner;
    int size;
    int maxSize;
    void resize();
public:
    MagicBox();
    MagicBox(const MagicBox&);
    MagicBox& operator=(const MagicBox&);
    ~MagicBox();

    void insert(T);
    void pop();
    void list() const;

    int get_size() const;
    int get_maxSize() const;
};
