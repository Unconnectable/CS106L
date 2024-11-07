#include <cstdio>
#include <functional>
template <typename It, typename Pred>
It find(It first, It last, Pred pred)
{
    for (auto it = first; it != last; ++it)
    {
        if (pred(*it))
            return it;
    }
    return last;
}
template <typename T>
struct std::greater
{
    bool operator(const T &a, const T &b)
    {
        return a > b;
    }
};
template <>
struct std::hash<MyType>
{
    size_t operator(const MyType &v) const
    {
    }
};
int main()
{
    int n = 10;
    auto f = [n](int x) { return x < n; };
    std::find_if(begin, end, f);
class lambda_name
{
public:
    bool operator()(int x) const { return x < n };
    lambda_name(int &_n) : n{_n} {};

private:
    int n;
};
    return 0;
}
