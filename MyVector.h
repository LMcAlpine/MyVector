#ifndef _MYVECTOR_H_
#define _MYVECTOR_H_

template <typename T>
class MyVector
{
private:
    T *list;

    // number of elements in the list
    int size;
    // total number of elements the array can hold
    int capacity;

public:
    MyVector();
    ~MyVector();

    void insert(T item, int index);
    int remove(int index);
    bool contains(T item);

    int indexOf(T item);

    int get(int index);

    void set(int index, T item);

    int getSize();

    bool isEmpty();

    void resize();

    void print();

    void clear()
    {
        delete[] list;
        size = 0;
        capacity = 16;
        list = new T[capacity];
    }
};
#include "MyVector_impl.h"
#endif // _MYVECTOR_H_