#include <iostream>
#include <cstring>

class Shape{
public:
    virtual double area() const = 0;
};

class Circle : public Shape{  //Circle继承自Shape
public:
    //Constructor
    Circle(double radius): _radius{radius}{};
    double area() const{
        return 3.14 * _radius * _radius;
    }
private:
    double _radius;
};

class Rectangle : public Shape{
public:
    //Constructor
    Rectangle(double width,double height): _height{height} , _width{width} {};
    double area() const{
        return 3.14 * _width * _height;
    }
private:
    double _width,_height;
};