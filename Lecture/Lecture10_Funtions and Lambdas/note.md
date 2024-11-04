# Lecture10:Functions and Lambdas

## **Content:**

- Template Functions
- Concepts
- Variadic Templates(可变参数模板)
- 模板元编程Template MetaProgramming



## Template Functions:



explicit instantiation:显式实例化

Implicit instantiation:隐式实例化

```cpp
#include <iostream>
#include <set>
template <class T, class Y>
auto min_(const T &a, const Y &b)
{
    return a < b ? a : b;
}
template <class T, class Y>
auto find(const T &begin, const T &end, const Y &pattern)
{
    for (auto _it = begin; _it != end; ++_it)
    {
        if (*_it == pattern)
            return _it;
    }
    return end;
}
int main()
{
    std::cout << min_(555, 'a') << std::endl;
    std::set<std::string> v{"aaa", "bbb"};
    auto it = find(v.begin(), v.end(), "bbb");
    if (it != v.end())
        std::cout << "Found: " << *it << std::endl;
    else
        std::cout << "Not found." << std::endl;
    return 0;
}
```

