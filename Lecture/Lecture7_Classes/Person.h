#include <iostream>
#include <cstring>
#include <cstdint>

class Person {
protected:
    std::string name;

public:
    Person(const std::string& name) : name(name) {}
    std::string getName() const {
        return name;
    }
};

class Student : public virtual Person {
protected:
    std::string idNumber;
    std::string major;
    std::string advisor;
    uint16_t year;

public:
    Student(const std::string& name, /* other parameters */);
    std::string getIdNumber() const;
    std::string getMajor() const;
    uint16_t getYear() const;
    void setYear(uint16_t year);
    void setMajor(const std::string& major);
    std::string getAdvisor() const;
    void setAdvisor(const std::string& advisor);
};

class Employee :public virtual Person{
protected:
    double salary;

public:
    Employee(const std::string &name){};
    virtual std::string getRole() const = 0;
    virtual double getSalary() const = 0;
    virtual void setSalary() const = 0;
    virtual ~Employee() = default;
};

class SectionLeader : public Person, public Employee {
protected:
    std::string section;
    std::string course;
    std::vector<std::string> students;

public:
    SectionLeader(const std::string& name, /* other parameters */);
    std::string getSection() const;
    std::string getCourse() const;
    void addStudent(const std::string& student);
    void removeStudent(const std::string& student);
    std::vector<std::string> getStudents() const;
    std::string getRole() const override;
    double getSalary() const override;
    void setSalary(double salary) override;
    virtual ~SectionLeader() noexcept = default;
};
