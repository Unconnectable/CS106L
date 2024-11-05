#include <algorithm>
#include <iostream>
#include <vector>
template <typename T>
concept Comparable = requires(const T &a, const T &b) {
    { a < b } -> std::convertible_to<bool>;
};
concept Addable = requires(const T)
template <typename T>
    requires Comparable<T>
// template <Comparable T>
T min(const T &a, const T &b)
{
}
// 重写find函数
template <std::input_iterator IT, typename T>
auto find(IT begin, IT end, const T &value)
{
    for (; begin != end; ++begin)
    {
        if (*begin == value)
        {
            return begin;
        }
    }
    return end;
}
int main()
{
    int value;
    std::cin >> va
    std::vector<int> a = {1, 2, 3, 4, 5};
    auto pos = find(a.begin(), a.end(), 3);
    if (pos != a.end())
        std::cout << *pos << std::endl;
    else
        std::cout << "NOT FIND";
    return 0;
}