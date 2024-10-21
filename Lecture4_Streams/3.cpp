#include <iostream>
#include <fstream>  // 需要包含这个头文件才能使用 ofstream

int main() {
    // 在构造时关联文件
    std::ofstream ofs("hello.txt");

    if (ofs.is_open()) {
        ofs << "Hello CS106L!" << '\n';
    }

    ofs.close();

    // 关闭后，这条语句不会写入文件
    ofs << "this will not get written";

    // 重新打开文件
    ofs.open("hello.txt",std::ios::app);
    ofs << "this will though! It’s open again";

    return 0;
}
