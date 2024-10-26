#include "StudentID.h"
#include <string>

// default constructor
StudentID::StudentID() {
    name = "John Appleseed";
    sunet = "jappleseed";
    idNumber = 00000001;
    my_array = new int[10]; // 动态分配数组
}
    // parameterized constructor
StudentID::StudentID(std::string name, std::string sunet, int idNumber) {
    this->name = name;
    this->sunet = sunet; // 替换为正确的成员变量
    this->idNumber = idNumber; // 替换为正确的成员变量
}

std::string StudentID::getName(){
    return this->name;
}
std::string StudentID::getSunet(){
    return this->sunet;
}
int StudentID::getID(){
    return this->idNumber;
}
void StudentID::setName(std::string name) {
    this->name = name;
}
void StudentID::setSunet(std::string sunet) {
    this->sunet = sunet;
}
void StudentID::setID(int idNumber) {
    if (idNumber >= 0){
        this->idNumber = idNumber;
    }
}
StudentID::~StudentID(){
    delete [] my_array;
}

