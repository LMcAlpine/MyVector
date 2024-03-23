#include <iostream>
#include <limits.h>
#include "MyVector.h"

template <typename T>
MyVector<T>::MyVector() : capacity(16), size(0), list(new T[capacity])
{
}
template <typename T>
void MyVector<T>::insert(T item, int index)
{

    if (index < 0 || index > size)
    {

        return;
    }
    if (size == capacity)
    {
        resize();
    }

    // if a shift is needed then perform it. Loops does not run if no shift needed
    for (size_t i = size; i > index; i--)
    {
        list[i] = list[i - 1];
    }
    list[index] = item;
    size++;
}
template <typename T>
int MyVector<T>::remove(int index)
{
    if (index < 0 || index >= size)
    {

        return 0;
    }

    if (index == size - 1)
    {
        size--;
        return index;
    }

    // 1 2 3 4 5
    // remove item at index 2
    // 1 2 4 5
    // list[index] = list[index+1]
    // from index to size?

    // to shift go from the index up to the size
    for (int i = index; i < size; i++)
    {
        list[i] = list[i + 1];
    }
    size--;
    return index;
}
template <typename T>
bool MyVector<T>::contains(T item)
{
    for (size_t i = 0; i < size; i++)
    {
        if (list[i] == item)
        {
            return true;
        }
    }
    return false;
}
template <typename T>
int MyVector<T>::indexOf(T item)
{
    for (size_t i = 0; i < size; i++)
    {
        if (list[i] == item)
        {
            return i;
        }
    }
    return -1;
}
template <typename T>
int MyVector<T>::get(int index)
{
    if (index < 0 || index >= size)
    {

        return 0;
    }
    return list[index];
}
template <typename T>
void MyVector<T>::set(int index, T item)
{
    if (index < 0 || index >= size)
    {

        return;
    }
    list[index] = item;
}
template <typename T>
int MyVector<T>::getSize()
{
    return size;
}
template <typename T>
bool MyVector<T>::isEmpty()
{
    if (size == 0)
    {
        return true;
    }
    return false;
}
template <typename T>
void MyVector<T>::resize()
{
    capacity = capacity * 2;
    T *temp = new T[capacity];

    // i < size not i < capacity because then it will access memory in list that is not in bounds
    for (size_t i = 0; i < size; i++)
    {
        temp[i] = MyVector::list[i];
    }

    delete[] list;
    list = temp;
}
template <typename T>
void MyVector<T>::print()
{
    if (size == 0)
    {
        std::cout << "[]";
    }

    for (size_t i = 0; i < size; i++)
    {
        std::cout << list[i] << " ";
    }
    std::cout << "\n";
}
template <typename T>
MyVector<T>::~MyVector()
{
    delete[] list;
}
