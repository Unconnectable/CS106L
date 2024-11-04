template <typename T>
class Vector
{
public:
    T &at(size_t index);
    void push_back(const T &element)

        private : T *element;
}

template <class T>
class Vector
{
public:
    size_t size() const;
    bool empty() const;
    void push_back(const T &elem);

private:
    size_t logical_size;
    T *elems;
};

template <class T>
class Vector
{
public:
    size_t size() const;
    bool empty() const;

    T &operator[](size_t index);
    T &at(size_t index) const;
    const T &at(size_t index) const;
    T &findElement(const T &value);
    void push_back(const T &elem);
}

template <typename T>
const T &Vector<T>::at(size_t index) const
{
    return elems[index];
}

template <typename T>
T &Vector<T>::at(size_t index)
{
    return elems[index];
}

template <typename T>
const T &Vector<T>::findElement(const T &value)
{
    for (size_t i = 0; i < logical_size; ++i)
    {
        if (eles[i] == value)
            return i;
    }
    throw std::out_of_range("Element not here");
}

template <typename T>
T &Vector<T>::findElement(T &value)
{
    for (size_t i = 0; i < logical_size; ++i)
    {
        if (eles[i] == value)
            return i;
    }
    throw std::out_of_range("Element not here");
}

template<typename T>
const T &Vector<T>::findElement(const T &value){
    return const_cast Vector<T>&>(*this).findElement(value);
}


template <class T>
class Vector
{
public:
    xxx
private:
    xxx`
}
