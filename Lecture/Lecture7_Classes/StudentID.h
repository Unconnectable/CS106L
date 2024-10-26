#include <iostream>
#include <string>


class StudentID{
private:
    //成员变量
    std::string name;
    std::string sunet;
    int idNumber;
    int* my_array; // 动态数组的指针


public:
    //默认构造函数
    StudentID();
    //参数构造函数
    StudentID(std::string name,std::string sunet, int idNumber);
    std::string getName();
    std::string getSunet();
    int getID();

    void setName(std::string name);
    void setSunet(std::string sunet);
    void setID(int idNumber);

    //析构函数
    ~StudentID();
};