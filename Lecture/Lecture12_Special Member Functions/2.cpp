#include <cstdio>

template <typename T>
class Vector
{
private:
    size_t _size;
    size_t _capacity;
    T *_data;

public:
    Vector()
        : _size(0), _capacity(4), _data(new T[_capacity]) {}
    ~Vector()
    {
        delete[] _data; // 析构函数释放动态内存
    }
};
template <typename T>
Vector<T>::Vector()
    : _size(0), _capacity(4), _data(new T[_capacity]) {}

template <typename T>
Vector<T>::~Vector()
{
    delete[] _data;
}
{
public:
    Vector();
    ~Vector();
    void push_back(const T &value);
    T pop_back()
    {
        // A
    }
};

template <typename T>
T Vector<T>::pop_back()
{
    // B
}
class a_string_with_an_id()
{
public:
    /// getter and setter methods for our private variables
private:
    int id;
    std::string str;
}
a_string_with_an_id object;

template <typename T>
Vector<T>::Vector()
    : _size(0), _capacity(4), _data(new T[_capacity]) {}

Vector<T>::Vector(const Vector<T> &other)
    : _size(other._size), _capacity(other.capacity), _data(new T[other.capacity]) {}

Vector<T>::Vector(const Vector<T> &other)
    : _size(other._size), _capacity(other.capacity), _data(new T[other.capacity])
{
    for (size i = 0; i < _size; ++i)
    {
        _data[i] = other._data[i];
    }
}

template <typename T>
class Myclass
{
    const int _constant;
    int &_reference;

public:
    Myclass(int value, int &ref) : _constant(value), _reference(ref) {}
};

int main()
{

    return 0;
}

Widget widgetOne;
Widget widgetTwo = widgetOne; // 调用Copy Constructor:
widgetTwo = Widget widgetOne; // 调用Copy Assign Constructor

template <typename T>
class MyClass
{
    const int _constant;
    int &_reference;

public:
    // Only way to initialize const and reference members
    MyClass(int value, int &ref) : _constant(value),_reference(ref) {}
};