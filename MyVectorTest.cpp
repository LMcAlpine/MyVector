#include <gtest/gtest.h>
#include "MyVector.h"

void insertTenItems(MyVector &list);

void insertTwentyItems(MyVector &list);

void insertTenItemsPlusFive(MyVector &list);

TEST(myVectorTest, size_0)
{
    MyVector vec;
    GTEST_ASSERT_EQ(0, vec.getSize());
}

TEST(myVectorTest, size_1)
{
    MyVector vec;
    vec.insert(1, 0);
    GTEST_ASSERT_EQ(1, vec.getSize());
}

TEST(myVectorTest, insert1)
{
    MyVector vec;
    vec.insert(0, 0);
    vec.insert(1, 1);
    vec.insert(2, 2);
    GTEST_ASSERT_EQ(0, vec.get(0));
    GTEST_ASSERT_EQ(1, vec.get(1));
    GTEST_ASSERT_EQ(2, vec.get(2));
}
TEST(myVectorTest, insert2)
{
    MyVector vec;
    vec.insert(0, 0);
    vec.insert(1, 1);

    GTEST_ASSERT_EQ(0, vec.get(0));
    GTEST_ASSERT_EQ(1, vec.get(1));
    vec.insert(2, 0);
    GTEST_ASSERT_EQ(2, vec.get(0));
    // vec.print();
}

TEST(myVectorTest, indexInBound)
{
    MyVector vec;
    vec.insert(1, 0);
    GTEST_ASSERT_EQ(1, vec.getSize());
}

TEST(myVectorTest, indexOutOfBoundPositive)
{
    MyVector vec;
    vec.insert(1, 1);
    GTEST_ASSERT_EQ(0, vec.getSize());
}

TEST(myVectorTest, indexOutOfBoundNegative)
{
    MyVector vec;
    vec.insert(1, -1);
    GTEST_ASSERT_EQ(0, vec.getSize());
}

TEST(myVectorTest, resize)
{
    MyVector vec;
    insertTwentyItems(vec);
    GTEST_ASSERT_EQ(20, vec.getSize());
}

TEST(myVectorTest, contains)
{
    MyVector vec;
    insertTenItems(vec);
    for (int i = 0; i < 10; i++)
    {
        GTEST_ASSERT_EQ(true, vec.contains(i));
    }
}

TEST(myVectorTest, notContain)
{
    MyVector vec;
    insertTenItems(vec);
    for (int i = 10; i < 20; i++)
    {
        GTEST_ASSERT_EQ(false, vec.contains(i));
    }
}

TEST(myVectorTest, containsAfterExpand)
{
    MyVector vec;
    insertTwentyItems(vec);
    for (int i = 0; i < 20; i++)
    {
        GTEST_ASSERT_EQ(true, vec.contains(i));
    }
}

TEST(myVectorTest, notContainAfterExpand)
{
    MyVector vec;
    insertTwentyItems(vec);
    for (int i = 20; i < 40; i++)
    {
        GTEST_ASSERT_EQ(false, vec.contains(i));
    }
}

TEST(myVectorTest, indexOfHasValue)
{
    MyVector vec;
    insertTenItemsPlusFive(vec);
    for (int i = 0; i < 10; i++)
    {
        GTEST_ASSERT_EQ(i, vec.indexOf(i + 5));
    }
}

TEST(myVectorTest, indexOfValueNotFound)
{
    MyVector vec;
    insertTenItemsPlusFive(vec);
    for (int i = 0; i < 5; i++)
    {
        GTEST_ASSERT_EQ(-1, vec.indexOf(i));
    }
    for (int i = 15; i < 20; i++)
    {
        GTEST_ASSERT_EQ(-1, vec.indexOf(i));
    }
}

TEST(myVectorTest, getInBound)
{
    MyVector vec;
    insertTenItems(vec);
    for (int i = 0; i < 10; i++)
    {
        GTEST_ASSERT_EQ(i, vec.get(i));
    }
    // vec.print();
}

TEST(myVectorTest, getOutBound)
{
    MyVector vec;
    insertTenItems(vec);
    for (int i = -5; i < 0; i++)
    {
        GTEST_ASSERT_EQ(0, vec.get(i));
    }
    for (int i = 10; i < 15; i++)
    {
        GTEST_ASSERT_EQ(0, vec.get(i));
    }
    // vec.print();
}

TEST(myVectorTest, setInBound)
{
    MyVector vec;
    insertTenItems(vec);
    vec.set(0, -1);
    vec.set(2, -1);
    vec.set(4, -1);
    vec.set(6, -1);
    vec.set(8, -1);
    for (int i = 0; i < 10; i++)
    {
        if (i % 2 == 0)
        {
            GTEST_ASSERT_EQ(-1, vec.get(i));
        }
        else
        {
            GTEST_ASSERT_EQ(i, vec.get(i));
        }
    }
    // vec.print();
}

TEST(myVectorTest, setOutBound)
{
    MyVector vec;
    insertTenItems(vec);
    vec.set(-1, -1);
    vec.set(-2, -1);
    vec.set(-3, -1);
    vec.set(10, -1);
    vec.set(11, -1);
    for (int i = 0; i < 10; i++)
    {

        GTEST_ASSERT_EQ(i, vec.get(i));
    }
}

TEST(myVectorTest, empty)
{
    MyVector vec;
    GTEST_ASSERT_EQ(true, vec.isEmpty());
}

TEST(myVectorTest, notEmpty)
{
    MyVector vec;
    vec.insert(1, 0);
    GTEST_ASSERT_EQ(false, vec.isEmpty());
}

TEST(myVectorTest, notEmptyTenItems)
{
    MyVector vec;
    insertTenItems(vec);
    GTEST_ASSERT_EQ(false, vec.isEmpty());
}

TEST(myVectorTest, notEmptyAfterResize)
{
    MyVector vec;
    insertTwentyItems(vec);
    GTEST_ASSERT_EQ(false, vec.isEmpty());
}
// vec.print();

void insertTenItems(MyVector &list)
{
    for (int i = 0; i < 10; i++)
    {
        list.insert(i, i);
    }
}

void insertTwentyItems(MyVector &list)
{
    for (int i = 0; i < 20; i++)
    {
        list.insert(i, i);
    }
}

void insertTenItemsPlusFive(MyVector &list)
{
    for (int i = 0; i < 10; i++)
    {
        list.insert(i + 5, i);
    }
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
