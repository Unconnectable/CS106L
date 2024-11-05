#include <cstdio>

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
int main()
{

    return 0;
}