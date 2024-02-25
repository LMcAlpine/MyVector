#include <iostream>
#include "MyVector.h"

MyVector::MyVector() : capacity(4), size(0)
{
    MyVector::list = new int[capacity];
}

void MyVector::insert(int item, int index)
{

    if (index < 0)
    {
        std::cout << "Index out of bounds" << std::endl;
        return;
    }
    if (MyVector::size == MyVector::capacity)
    {
        resize();
    }

    if (index <= MyVector::size)
    {

        MyVector::list[index] = item;
        MyVector::size++;
        std::cout << "size " << size << "\n";
        std::cout << "index " << index << "\n";
        std::cout << "\n";
    }
    else
    {
        std::cout << "error when size is " << size << " index of " << index << std::endl;
        return;
    }
}

void MyVector::resize()
{
    MyVector::capacity = capacity * 2;
    int *temp = new int[MyVector::capacity];

    // is this necessary?
    for (size_t i = 0; i < capacity; i++)
    {
        temp[i] = 0;
    }

    // i < size not i < capacity because then it will access memory in list that is not in bounds
    for (size_t i = 0; i < size; i++)
    {
        temp[i] = MyVector::list[i];
    }

    delete[] MyVector::list;
    MyVector::list = temp;
}

void MyVector::print()
{

    for (int i = 0; i < capacity; i++)
    {
        std::cout << MyVector::list[i] << " ";
    }
    std::cout << "\n";
}

MyVector::~MyVector()
{
    delete[] MyVector::list;
}

int main()
{

    // my process with insert was to first just get one item inserted
    // then it was to try adding elements out of range
    // this worked initially but it was evaluating an unsigned integer vs signed integer which was causing size to be incremented even though nothing was added (in what I could see with my print function)
    // then when I changed size to be int and not size_t it was causing the index -1 to pass the check of if index < size. So size was being incremented.
    // this caused a bug where the size was being counted as one more than how many elements were actually in the array
    // so it was making the size one more then it should have been
    // it was causing a "double free or corruption (out)" and "Aborted (core dumped)"
    // then i was having an issue where I was doing i < capacity but it was accessing elements not part of the list array
    //  // i < size not i < capacity because then it will access memory in list that is not in bounds
    // that is why when I was printing list that it had random values that I didnt add.

    MyVector myVector = MyVector();
    // myVector.insert(1, -1);
    // myVector.insert(4, 15);

    // myVector.insert(17, 17);
    for (int i = 0; i < 4; i++)
    {
        myVector.insert(i + 1, i);
    }
    myVector.print();
    myVector.insert(1, -1);
    myVector.print();
    myVector.insert(5, 4);
    myVector.print();
    myVector.insert(17, 17);

    myVector.print();
}