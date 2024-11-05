#include <iostream>
constexpr size_t fac_(size_t N)
{
    if (N == 0)
        return 1;
    return N * fac_(N - 1);
}

consteval size_t fac__(size_t N)
{
    if (N == 0)
        return 1;
    return N * fac__(N - 1);
}

int main()
{
    std::cout << fac_(7) << std::endl;  // 输出 5040
    std::cout << fac__(7) << std::endl; // 输出 5040
    return 0;
}
