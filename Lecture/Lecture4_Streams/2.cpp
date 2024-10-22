#include <iostream>
using namespace std;

int main() {
    //cout << "Hello, ";
    //cout.flush();  // 强制刷新缓冲区，立即输出内容
    //cout << "World!" << endl;  // 这行会自动刷新缓冲区


    std::ios::sync_with_stdio(false);
    for (int i=1; i <= 5; ++i)
        std::cout << i << '\n';
    return 0;
}
