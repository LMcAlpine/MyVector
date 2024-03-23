#include <gtest/gtest.h>
#include "MyVector.h"
template <typename T>
void insertTenItems(MyVector<T> &list);
template <typename T>
void insertTwentyItems(MyVector<T> &list);
template <typename T>
void insertTenItemsPlusFive(MyVector<T> &list);

template <typename T>
class myVectorTest : public ::testing::Test
{
protected:
    MyVector<T> vec;
    void SetUp() override
    {
        vec.clear();
    }

    void TearDown() override {}
};

using MyVectorTypes = ::testing::Types<int>;

TYPED_TEST_SUITE(myVectorTest, MyVectorTypes);

TYPED_TEST(myVectorTest, size_0)
{

    GTEST_ASSERT_EQ(0, this->vec.getSize());
}

TYPED_TEST(myVectorTest, size_1)
{

    this->vec.insert(1, 0);
    GTEST_ASSERT_EQ(1, this->vec.getSize());
}

TYPED_TEST(myVectorTest, insert1)
{

    this->vec.insert(0, 0);
    this->vec.insert(1, 1);
    this->vec.insert(2, 2);
    GTEST_ASSERT_EQ(0, this->vec.get(0));
    GTEST_ASSERT_EQ(1, this->vec.get(1));
    GTEST_ASSERT_EQ(2, this->vec.get(2));
}
TYPED_TEST(myVectorTest, insert2)
{

    this->vec.insert(0, 0);
    this->vec.insert(1, 1);

    GTEST_ASSERT_EQ(0, this->vec.get(0));
    GTEST_ASSERT_EQ(1, this->vec.get(1));
    this->vec.insert(2, 0);
    GTEST_ASSERT_EQ(2, this->vec.get(0));
    // vec.print();
}

TYPED_TEST(myVectorTest, indexInBound)
{

    this->vec.insert(1, 0);
    GTEST_ASSERT_EQ(1, this->vec.getSize());
}

TYPED_TEST(myVectorTest, indexOutOfBoundPositive)
{

    this->vec.insert(1, 1);
    GTEST_ASSERT_EQ(0, this->vec.getSize());
}

TYPED_TEST(myVectorTest, indexOutOfBoundNegative)
{

    this->vec.insert(1, -1);
    GTEST_ASSERT_EQ(0, this->vec.getSize());
}

TYPED_TEST(myVectorTest, resize)
{

    insertTwentyItems(this->vec);
    GTEST_ASSERT_EQ(20, this->vec.getSize());
}

TYPED_TEST(myVectorTest, contains)
{

    insertTenItems(this->vec);
    for (int i = 0; i < 10; i++)
    {
        GTEST_ASSERT_EQ(true, this->vec.contains(i));
    }
}

TYPED_TEST(myVectorTest, notContain)
{

    insertTenItems(this->vec);
    for (int i = 10; i < 20; i++)
    {
        GTEST_ASSERT_EQ(false, this->vec.contains(i));
    }
}

TYPED_TEST(myVectorTest, containsAfterExpand)
{

    insertTwentyItems(this->vec);
    for (int i = 0; i < 20; i++)
    {
        GTEST_ASSERT_EQ(true, this->vec.contains(i));
    }
}

TYPED_TEST(myVectorTest, notContainAfterExpand)
{

    insertTwentyItems(this->vec);
    for (int i = 20; i < 40; i++)
    {
        GTEST_ASSERT_EQ(false, this->vec.contains(i));
    }
}

TYPED_TEST(myVectorTest, indexOfHasValue)
{

    insertTenItemsPlusFive(this->vec);
    for (int i = 0; i < 10; i++)
    {
        GTEST_ASSERT_EQ(i, this->vec.indexOf(i + 5));
    }
}

TYPED_TEST(myVectorTest, indexOfValueNotFound)
{

    insertTenItemsPlusFive(this->vec);
    for (int i = 0; i < 5; i++)
    {
        GTEST_ASSERT_EQ(-1, this->vec.indexOf(i));
    }
    for (int i = 15; i < 20; i++)
    {
        GTEST_ASSERT_EQ(-1, this->vec.indexOf(i));
    }
}

TYPED_TEST(myVectorTest, getInBound)
{

    insertTenItems(this->vec);
    for (int i = 0; i < 10; i++)
    {
        GTEST_ASSERT_EQ(i, this->vec.get(i));
    }
    // vec.print();
}

TYPED_TEST(myVectorTest, getOutBound)
{

    insertTenItems(this->vec);
    for (int i = -5; i < 0; i++)
    {
        GTEST_ASSERT_EQ(0, this->vec.get(i));
    }
    for (int i = 10; i < 15; i++)
    {
        GTEST_ASSERT_EQ(0, this->vec.get(i));
    }
    // vec.print();
}

TYPED_TEST(myVectorTest, setInBound)
{

    insertTenItems(this->vec);
    this->vec.set(0, -1);
    this->vec.set(2, -1);
    this->vec.set(4, -1);
    this->vec.set(6, -1);
    this->vec.set(8, -1);
    for (int i = 0; i < 10; i++)
    {
        if (i % 2 == 0)
        {
            GTEST_ASSERT_EQ(-1, this->vec.get(i));
        }
        else
        {
            GTEST_ASSERT_EQ(i, this->vec.get(i));
        }
    }
    // vec.print();
}

TYPED_TEST(myVectorTest, setOutBound)
{

    insertTenItems(this->vec);
    this->vec.set(-1, -1);
    this->vec.set(-2, -1);
    this->vec.set(-3, -1);
    this->vec.set(10, -1);
    this->vec.set(11, -1);
    for (int i = 0; i < 10; i++)
    {

        GTEST_ASSERT_EQ(i, this->vec.get(i));
    }
}

TYPED_TEST(myVectorTest, empty)
{

    GTEST_ASSERT_EQ(true, this->vec.isEmpty());
}

TYPED_TEST(myVectorTest, notEmpty)
{

    this->vec.insert(1, 0);
    GTEST_ASSERT_EQ(false, this->vec.isEmpty());
}

TYPED_TEST(myVectorTest, notEmptyTenItems)
{

    insertTenItems(this->vec);
    GTEST_ASSERT_EQ(false, this->vec.isEmpty());
}

TYPED_TEST(myVectorTest, notEmptyAfterResize)
{

    insertTwentyItems(this->vec);
    GTEST_ASSERT_EQ(false, this->vec.isEmpty());
}
// vec.print();
template <typename T>
void insertTenItems(MyVector<T> &list)
{
    for (int i = 0; i < 10; i++)
    {
        list.insert(i, i);
    }
}
template <typename T>
void insertTwentyItems(MyVector<T> &list)
{
    for (int i = 0; i < 20; i++)
    {
        list.insert(i, i);
    }
}
template <typename T>
void insertTenItemsPlusFive(MyVector<T> &list)
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
