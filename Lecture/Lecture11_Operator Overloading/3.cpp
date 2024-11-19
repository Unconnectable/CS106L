#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;
// 错误的写法：friend 声明不能在类外部
class StudentID
{
private:
    string name;
    string sunet;
    int idNumber;

public:
    StudentID(string name, string sunet, int idNumber);
};

// 在类外定义 friend 函数，会报错
friend bool operator<(const StudentID &lhs, const StudentID &rhs)
{ // 编译错误
    return lhs.idNumber < rhs.idNumber;
}

int main()
{
    return 0;
}