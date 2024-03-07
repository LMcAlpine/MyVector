#include <iostream>
#include <limits.h>
#include "MyVector.h"

MyVector::MyVector() : capacity(4), size(0), list(new int[capacity])
{
}

void MyVector::insert(int item, int index)
{

    if (index < 0 || index > size)
    {
        throw std::runtime_error("Out of bounds when index is: " + std::to_string(index));
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

int MyVector::remove(int index)
{
    if (index < 0 || index >= size)
    {
        throw std::runtime_error("Out of bounds when index is: " + std::to_string(index));
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

    // to shift go from the size down to the index being removed
    for (int i = index; i < size; i++)
    {
        list[i] = list[i + 1];
    }
    size--;
    return index;
}

void MyVector::resize()
{
    capacity = capacity * 2;
    int *temp = new int[capacity];

    // i < size not i < capacity because then it will access memory in list that is not in bounds
    for (size_t i = 0; i < size; i++)
    {
        temp[i] = MyVector::list[i];
    }

    delete[] list;
    list = temp;
}

void MyVector::print()
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

MyVector::~MyVector()
{
    delete[] list;
}

int main()
{

    try
    {

        MyVector myVector = MyVector();

        myVector.insert(1, 0);
        myVector.insert(2, 1);
        myVector.insert(3, 2);
        myVector.insert(4, 3);
        myVector.insert(5, 4);
        myVector.print();

        myVector.remove(0);
        myVector.print();
        myVector.remove(1);
        myVector.print();
        myVector.remove(2);
        myVector.print();
        //  myVector.remove(3);
        //  myVector.print();
        //  myVector.remove(4);
        //  myVector.print();

        myVector.remove(1);
        myVector.print();
        myVector.remove(0);
        myVector.print();
    }
    catch (const std::runtime_error &ex)
    {
        std::cerr << ex.what() << '\n';
    }
}