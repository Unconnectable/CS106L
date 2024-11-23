#include <cstdio>
#include <iostream>
#include <cstring>
using std::cin;
using std::cout;
using std::string;
template <typename T>
class Vector
{
public:
    T &at(size_t index);
    void push_back(const T &elem);

private:
    T *elems;
};

int main()
{
    Vector<int> intVec;
    Vector<double> doubleVec;
    Vector<string> string;
    Vector<Vector<int>> vecVec;
    struct MyCustomType
    {
    };
    Vector<MyCustomType> structVec;
    return 0;
}

template <class T>
class Vector
{
public:
    size_t size();
    bool empty();

    T &operator[](size_t index)
        T &at(size_t index);
    void push_back(const T &elem);
}

void
printVec(const Vector<int> &v)
{
    for (size_t i = 0; i < v.size(); ++i)
    {
        std::cout << v.at(i);
        << std::endl;
    }
}

template <class T>
class Vector
{
public:
    size_t size() const;

    bool empty() const;

    T &operator[](size_t index);
    T &at(size_t index) const;
    void push_back(const T &elem);

private:
    T *elems;
};
void printVec(const Vector<T> &v)
{
    for (size_t i = 0; i < v.size(); ++i)
    {
        std::cout << v.at(i) << std::endl;
    }
}

template <typename T>
T &Vector<T>::findElement(const T &value)
{
    for (size_t i = 0; i < logical_size; i++)
    {
        if (elems[i] == elem)
            return elems[i];
    }
    throw std::out_of_range("Element not found");
}

template <typename T>
const T &Vector<T>::findElement(const T &value) const
{
    for (size_t i = 0; i < logical_size; i++)
    {
        if (elems[i] == elem)
            return elems[i];
    }
    throw std::out_of_range("Element not found");
}

const T &Vector<T>::findElement(const T &value) const
{
    return const_cast<Vector<T> &>(*this).findElement(value);
}