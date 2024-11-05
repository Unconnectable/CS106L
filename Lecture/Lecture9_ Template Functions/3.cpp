#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
T min__(const std::vector<T> &values)
{
    if (values.size() == 1)
        return values[0];
    const auto &first = values[0];
    std::vector<T> rest(values.begin() + 1, values.end());
    auto m = min__(rest);
    return first < m ? first : m;
}
template <typename T>
T min__(const T &v)
{
    return v;
}
template <typename T, typename... Args>
T min__(const T &v, const Args &...args)
{
    T m = min__(args...);
    return v < m ? v : m;
};

int main()
{
    std::vector<int>a{1,2,3};
    int x = min__(a);
    std::cout<<x<<std::endl;
    std::cout<<min__(22222222,3333,111)<<std::endl;
    return 0;
}