#include <iostream>
#include <limits.h>
#include "MyVector.h"

MyVector::MyVector() : capacity(16), size(0), list(new int[capacity])
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

    // to shift go from the index up to the size
    for (int i = index; i < size; i++)
    {
        list[i] = list[i + 1];
    }
    size--;
    return index;
}

bool MyVector::contains(int item)
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

int MyVector::indexOf(int item)
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

int MyVector::get(int index)
{
    if (index < 0 || index >= size)
    {
        throw std::runtime_error("Out of bounds when index is: " + std::to_string(index));
    }
    return list[index];
}

void MyVector::set(int index, int item)
{
    if (index < 0 || index >= size)
    {
        throw std::runtime_error("Out of bounds when index is: " + std::to_string(index));
    }
    list[index] = item;
}

int MyVector::getSize()
{
    return size;
}

bool MyVector::isEmpty()
{
    if (size == 0)
    {
        return true;
    }
    return false;
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

// int main()
// {

//     try
//     {

//         MyVector myVector = MyVector();

//         myVector.insert(1, 0);
//         myVector.insert(2, 1);
//         myVector.insert(3, 2);
//         myVector.insert(4, 3);
//         myVector.insert(5, 4);
//         myVector.print();

//         std::cout << "\ncontains:\n"
//                   << std::endl;

//         bool result = myVector.contains(1);
//         std::cout << result << std::endl;
//         result = myVector.contains(2);
//         std::cout << result << std::endl;
//         result = myVector.contains(3);
//         std::cout << result << std::endl;
//         result = myVector.contains(4);
//         std::cout << result << std::endl;
//         result = myVector.contains(5);
//         std::cout << result << std::endl;

//         std::cout << "end\n"
//                   << std::endl;

//         myVector.remove(0);
//         myVector.print();

//         std::cout << "\ncontains after removal:\n"
//                   << std::endl;
//         result = myVector.contains(1);
//         std::cout << result << std::endl;

//         std::cout << "end"
//                   << std::endl;

//         myVector.remove(1);
//         myVector.print();

//         std::cout << "\ncontains after removal:\n"
//                   << std::endl;
//         result = myVector.contains(3);
//         std::cout << result << std::endl;

//         std::cout << "end"
//                   << std::endl;
//         myVector.remove(2);

//         std::cout << "\ncontains after removal"
//                   << std::endl;
//         result = myVector.contains(5);
//         std::cout << result << std::endl;

//         std::cout << "end"
//                   << std::endl;

//         myVector.print();
//         //  myVector.remove(3);
//         //  myVector.print();
//         //  myVector.remove(4);
//         //  myVector.print();
//         // bool result = myVector.contains(500);
//         // std::cout << result << std::endl;

//         myVector.remove(1);

//         std::cout << "\ncontains after removal"
//                   << std::endl;
//         result = myVector.contains(4);
//         std::cout << result << std::endl;

//         std::cout << "end"
//                   << std::endl;

//         myVector.print();
//         myVector.remove(0);

//         std::cout << "\ncontains after removal"
//                   << std::endl;
//         result = myVector.contains(2);
//         std::cout << result << std::endl;

//         std::cout << "end"
//                   << std::endl;
//         myVector.print();

//         result = myVector.contains(1);
//         std::cout << result << std::endl;
//     }
//     catch (const std::runtime_error &ex)
//     {
//         std::cerr << ex.what() << '\n';
//     }
// }