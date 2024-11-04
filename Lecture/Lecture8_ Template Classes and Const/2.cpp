template <typenameT, typenameU, typenameR>
std::pair<T, T> function_name(T &a, T &b, t)
{
    return a < b ? {a, b} : {b, a};
}

template <typename Collection, typename DataType>
int count_times function_name(const Collection<DataType> &list, const DataType &value)
{
    int count = 0;
    for (size_t i = 0; i < list.size(); ++i)
    {
        if (list[i] == value)
            count++;
    }
    return count;
}
bool func_name(int val)
{
    return val < 5 ? ;
}
template <class DataType>
bool func_name(DataType val)
{
    return val < 5 ? ;
}
template <class it, class func>
int function_name(it begin, it end, func cmp)
{
    int cnt = 0;
    for (auto iter = begin; it != end; ++it)
    {
        if (cmp(*iter))
            ++cnt;
    }
    return cnt;
}
std::vector<int> numbers = {1, 2, 3, 4, 5, 6};
std::vector<int> evens;

// 使用 std::copy_if 复制偶数到 evens 容器
std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(evens), [](int num){
    return num % 2 == 0; // 偶数的条件
});
std::vector<int> source = {1, 2, 3, 4, 5};
std::vector<int> destination(5); // 创建一个目标容器，大小与源相同

    // 使用 std::copy 复制元素
std::copy(source.begin(), source.end(), destination.begin());

std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

// 使用 std::remove_if 移除所有偶数
auto new_end = std::remove_if(numbers.begin(), numbers.end(), [](int x) {
        return x % 2 == 0;
});

vec.erase(std::remove_if(numbers.begin(), numbers.end(), rule),vec.end());