#include <iostream>
int main() {
    int x = 106;
    int* px = &x;        // 定义一个指向 x 的指针 px
    std::cout << x << std::endl;    // 输出 x 的值
    std::cout << *px << std::endl;   // 通过指针输出 x 的值
    std::cout << px << std::endl;    // 输出指针 px 的地址 例如：0x50527c
    return 0;
}
