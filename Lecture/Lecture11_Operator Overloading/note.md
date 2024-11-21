# Operator Overloading

对于某些函数的使用Like `map<K,V>`要求`K`必须能够进行`<`的比较,如何实现呢?

### ***Operatore Overloading!***

接下来展示如何对一个类进行重载运算符

```cpp
class StudentID
{
private:
    string name;
    string sunet;
    int idNumber;
public:
    // 构造函数声明
    StudentID(string name, string sunet, int idNumber);
};
```

`class`的`Operator Overloading`分为成员重载`(member overloading)`和非成员重载`(non member overloading)`

## ***成员函数***

- ```cpp
  class StudentID
  {
  private:
      string name;
      string sunet;
      int idNumber;
  public:
      StudentID(string name, string sunet, int idNumber);
      bool operator<(const StudentID &rhs) const{
          return idNumber < rhs.idNumber;
          //完整写法
         	//return this->idNumber < rhs.idNumber;
      }
  };
  
  ```

- 直接在`class`内部实现了重载

- 以下在`class`外部实现重载，也就是非成员函数的外部运算符重载格式

- ```cpp
  //通用格式为:
  type class_name::operator X(参数){
  	//具体实现
  }
  //这里的X是药重载的函数 type是返回类型 class_name是要重载的函数名称 具体见下面
  ```

- ```cpp
  class StudentID
  {
  private:
      string name;
      string sunet;
      int idNumber;
  public:
      StudentID(string name, string sunet, int idNumber);
      bool operator<(const StudentID &rhs) const；
  };
  
  bool StudentID::operator<(const StudnetID &rhs) const
  {
      return idNumber < rhs.idNumber;
      //事实上完整写法是
      //return this->idNumber < rhs.idNumber;
  }
  ```



## ***非成员函数***

同样拿上面的例子举例

- ``` cpp
  class StudentID
  {
  private:
      string name;
      string sunet;
      int idNumber;
  public:
      StudentID(string name, string sunet, int idNumber);
  };
  bool operator < (const StudentID& lhs,const StudentID& rhs){
  	return lhs.idNumber  < 	rhs.idNumber;
  }
  ```

- 直接在外部进行重载,没有在内部声名`bool operator<(const StudentID &rhs) const;` 

- 非成员重载的缺点是不能访问`private`的成员,如果需要访问的话需要在`class`使用`friend`关键字declare

- ```cpp
  class StudentID
  {
  private:
      std::string name;
      std::string sunet;
      int idNumber;
  
  public:
      StudentID(std::string name, std::string sunet, int idNumber);
      friend bool operator<(const StudentID &lhs, const StudentID &rhs);
  }
  bool operator <(const StudentID &lhs, const StudentID &rhs){
      return lhs.idNumber < rhs.idNumber;
  }
  ```

- 在类外定义 `friend` 函数，会报错

- 

  ```cpp
  
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
  { 
      // 编译错误
      return lhs.idNumber < rhs.idNumber;
  }
  ```



### **对比总结**

| **方面**         | **成员函数重载 (Member Function Overloading)**         | **非成员函数重载 (Non-Member Function Overloading)**         |
| ---------------- | ------------------------------------------------------ | ------------------------------------------------------------ |
| **访问私有成员** | 直接访问类的私有成员                                   | 需要使用 `friend` 声明才能访问私有成员                       |
| **设计理念**     | 运算符作为类的一部分，符合封装原则，内聚性强           | 更加灵活，可以与不同类型的对象一起使用                       |
| **对称性**       | 对运算符不对称（例如，`a.operator<` 不是对称的）       | 对运算符对称（例如，`operator<` 是对称的，`a` 和 `b` 没有先后顺序） |
| **修改类**       | 每次添加新的运算符重载时需要修改类                     | 不需要修改类，可以在类外部定义                               |
| **使用场景**     | 适合那些类的行为（如比较、赋值）与运算符紧密相关的操作 | 适合那些需要跨类型操作或与外部实体（如流）交互的操作         |



由于操作符旨在传达一种类型的含义，因此其含义应该是显而易见的。

- 我们通常可以定义的操作符是算术操作符。其功能应与相应的运算相似
-  例如，不应将 `operator+` 定义为集合减法。
-  如果含义不明显，那么也许应该为此定义一个函数。

## ***对立原则***

```cpp
bool StudentID::operator==(const StudentID& other) const {
    return (this->name == other.name) && 
           (this->sunet == other.sunet) && 
           (this->idNumber == other.idNumber);
}

bool StudnetID::operator!=(const StudnetID& other) const {
	return !(*this == other);
    //this->用来访问成员变量
    //*this解指针 指向自己
}
```

###### ***通过定义`==`来定义`!=`，`==` 和 `!=` 是对立的运算符`!=` 依赖于 `==`***