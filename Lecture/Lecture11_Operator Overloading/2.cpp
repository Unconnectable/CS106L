#include <iostream>
#include <string>

class StudentID
{
private:
    std::string name;
    std::string sunet;
    int idNumber;

public:
    // 构造函数
    StudentID(std::string name, std::string sunet, int idNumber)
        : name(name), sunet(sunet), idNumber(idNumber) {}

    // 重载 << 运算符，输出 StudentID 对象的成员
    friend std::ostream &operator<<(std::ostream &out, const StudentID &sid);
};

/*
// 第一个版本的 operator<< 输出简单的空格分隔
std::ostream& operator << (std::ostream& out, const StudentID& sid) {
    out << sid.name << " xxxxx " << sid.sunet << " yyyyyy " << sid.idNumber;
    return out;
}
*/
// 第二个版本的 operator<< 输出带标识符

std::ostream &operator<<(std::ostream &out, const StudentID &sid)
{
    out << "Name: " << sid.name << " sunet: " << sid.sunet << " idnumber: " << sid.idNumber;
    return out;
}

int main()
{
    // 创建两个 StudentID 对象
    StudentID student1("John", "johndoe", 12345);
    StudentID student2("Alice", "alice123", 67890);

    // 使用重载的 << 输出学生信息
    std::cout << "Using the first version of operator<<:" << std::endl;
    std::cout << student1 << std::endl; // 输出格式：John johndoe 12345
    std::cout << student2 << std::endl; // 输出格式：Alice alice123 67890

    std::cout << "\nUsing the second version of operator<<:" << std::endl;
    std::cout << student1 << std::endl; // 输出格式：Name: John sunet: johndoe idnumber: 12345
    std::cout << student2 << std::endl; // 输出格式：Name: Alice sunet: alice123 idnumber: 67890

    return 0;
}