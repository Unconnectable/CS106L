#include <iostream>
#include <vector>

int main() {
    std::vector<int> v {10, 20, 30, 40, 50};  // 定义并初始化一个整数向量
    int* ptr = &v[0];
    int* arr = &v[0];  // 获取 v 的首元素地址
    std::cout <<*arr << " ";  // 输出第一个元素：1
    arr += 1;  // 移动指针到下一个元素
    std::cout << *arr << " ";  // 输出第二个元素：2
    ++arr;  // 移动指针到下一个元素
    std::cout << *arr << " ";  // 输出第三个元素：3
    arr += 2;  // 移动指针到第五个元素
    std::cout << *arr << " ";  // 输出第五个元素：5

    if (arr == &v[4])  // 检查指针是否指向最后一个元素
        std::cout << "At last index";  // 输出提示信息

    std::cout << std::endl;  // 换行
    return 0;  // 返回 0 表示程序正常结束
}
