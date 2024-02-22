template <class T>
class MyVector
{
private:
    T *list;
    size_t size;
    int capacity;

public:
    MyVector();
    ~MyVector();
};