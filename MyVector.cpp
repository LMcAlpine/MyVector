#include <iostream>
#include "MyVector.h"

template <class T>
MyVector<T>::MyVector()
{
    std::cout << "testing" << std::endl;
}

template <class T>
MyVector<T>::~MyVector()
{
}

int main()
{
    MyVector<int> myVector = MyVector<int>();
   // std::cout << &myVector.list << std::endl;
    // std::vector<int> v = {8,4,5,9};

    // v.push_back(6);
    // v.push_back(9);

    // v[2] = -1;

    // for (int n: v)
    //     std::cout<< n << ' ';
    // std::cout << '\n';
}