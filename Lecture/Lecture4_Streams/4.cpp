#include <iostream>  // 用于 std::cout 和 std::endl
#include <fstream>   // 用于 std::ifstream
#include <string>    // 用于 std::string

int main() {
    std::ifstream ifs("append.txt");  // 打开文件 "append.txt" 以读取

    if (ifs.is_open()) {  // 检查文件是否成功打开
        std::string line;
        std::getline(ifs, line);  // 读取文件中的一行
        std::cout << "Read from the file: " << line << '\n';
    }

    if (ifs.is_open()) {  // 再次检查文件是否打开
        std::string lineTwo;
        std::getline(ifs, lineTwo);  // 读取文件中的第二行
        std::cout << "Read from the file: " << lineTwo << '\n';
    }

    return 0;
}
