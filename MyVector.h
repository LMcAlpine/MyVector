//template <class T>
class MyVector
{
private:
    int *list;

    // number of elements in the list
    int size;
    // total number of elements the array can hold
    int capacity;

public:
    MyVector();
    ~MyVector();

    void insert(int item, int index);
    int remove(int index);

void resize();

    void print();
};
