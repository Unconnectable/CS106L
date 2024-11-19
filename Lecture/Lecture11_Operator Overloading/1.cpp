#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

class StudentID
{
private:
    string name;
    string sunet;
    int idNumber;
public:
    // 构造函数声明
    StudentID(string name, string sunet, int idNumber);
    bool operator<(const StudentID &rhs) const；
};

bool StudentID::operator<(const StudnetID &rhs) const
{
    return idNumber < rhs.idNumber;
}

bool operator<(const StudentID &rhs, const StudentID &lhs)
{
    return lhs.idNumber < rhs.idNumber;
}

StudentID jacob;
StudentID fabio;
auto minStanfordID = min<StanfordID>(jacob, fabio);
StanfordID min(const StanfordID &a, const StanfordID &b)
{
    return a < b ? a : b;
}
int main()
{
    return 0;
}
