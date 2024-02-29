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
    // here the index must be less than or equal to size
    // but how do I know if I need to do a shift?
    // if index==size?
    size++;
    if (index == size)
    {
        list[index] = item;
    }
    else
    {
        // now the index must be less than size so it is going to require a shift
        for (int i = size - 1; i >= index; i--)
        {
            list[i + 1] = list[i];
        }
        list[index] = item;
    }
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

    for (int i = 0; i < capacity; i++)
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

    // logic error in insert but where?
    // try catch , exception
    // throw anything
    // typically want to throw a pointer

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

    // I had redundant code by having a check of if index > size
    // and then later if index <= size

    // test for
    // add value at end
    // add value when size is filled to capacity
    // add value at size
    // add value at the first index
    // add value at an index greater than the size
    // add value at an index one greater than the size
    // add value at an index one less than the size
    // add value when size is one less than capacity
    // add value when size is greater than capacity
    // add value when size is less than index
    try
    {

        MyVector myVector = MyVector();
        //  myVector.insert(1, -1);
        // myVector.insert(4, 15);

        //  myVector.insert(17, 17);
        for (int i = 0; i < 4; i++)
        {
            myVector.insert(i + 1, i);
            myVector.print();
        }
        myVector.print();
        // bug here when inserting an element at the index of size-1
        // this is because it is doubling the capacity but not shifting any elements yet.
        // So the size is increased by one but there are still only 4 elements not 5
        myVector.insert(5, 3);
        myVector.print();

        myVector.insert(INT_MAX, 0);

        // myVector.insert(9, 20);

        myVector.print();
    }
    catch (const std::runtime_error &ex)
    {
        std::cerr << ex.what() << '\n';
    }

    // myVector.insert(1, -1);
    // myVector.print();
    // myVector.insert(5, 4);
    // myVector.print();
    // myVector.insert(17, 17);

    // insert that will require a shift
    // logic error when replacing an index right now because it increases the size even though an extra element is not added
    // but now how do I shift elements?
    // how do I tell if an index is already occupied by an element?
    // maybe, if the size is greater than the index you want to put an element then you know its occupied..?
    // so, then shift each element by one
    // then insert the new element at the index
    // what if you shift each element by 1 and it is goes out of bounds?

    // x
    // 1 2 3 4 5 0 0 0 0
    // 1 2 3 4 _ 5 0 0 0
    // start at the last inserted element
    // size-1?
    // 1 2 3 _ 4 5 0 0 0
    // 1 2 _ 3 4 5 0 0 0
    // 1 _ 2 3 4 5 0 0 0
    // _ 1 2 3 4 5 0 0 0
    // insert
    // 9 1 2 3 4 5 0 0 0

    // for i = size -1; i > capacity; i--
    //      move the element one space forward

    // does that work?
    // size = 3, capacity = 6
    // x
    // 1 2 3 _ _ _
    // i = 2, i > 6
    // oh, this above loop is wrong
    //
    // for i = size-1; i < capacity; i++
    // move element one space forward

    // x
    // 1 2 3
    // i = 2, i < 6; i++

    //  1 2 _ 3 _ _
    // i = 3, i < 6; i++
    //  1 _ 2 3 __
    // no, this is wrong too because its not accessing the right indices

    // I want to go from right to left in the array
    // oh from size-1 > 0
    // for i - size-1; i > 0; i--
    // x
    // 1 2 3
    // i = 2; i >= 0; i--
    // 1 2 _ 3 _ _
    // i = 1; i >= 0; i--
    // 1 _ 2 3 _ _
    // i = 0; i >= 0; i--
    // _ 1 2 3 _ _
    // insert item
    // 9 1 2 3 _ _
    // what if the shift goes all the way to the end and then an item is lost?
    // will this happen? or will it resize?

    // myVector.insert(9, 0);

    // myVector.print();
}