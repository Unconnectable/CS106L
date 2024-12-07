explicitly adj.明显的 显示的

# Special Member Functions

## **从以下这段代码引出今天的内容:SMFS:特殊成员函数**

```cpp
class Widget {
public:
    Widget ();                           //Default Constructor: 默认构造对象
    Widget(const Widget& w);            //Copy Constructor: 拷贝构造函数
    Widget& operator = (const Widget& w); //Copy Assign Constructor: 拷贝赋值运算符
    ~Widget();                          //Destructor: 析构函数
    Widget(Widget&& rhs);                 //Move Constructor: 移动构造函数
    Widget& operator = (Widget&& rhs);   	//Move Assign Constructor: 移动赋值运算符
};
```

### 一个后来补充的每一个函数的具体实现

```cpp
class Widget {
public:
    std::string name;    
    // 默认构造函数
    Widget() {
        name = "Default Widget";
        std::cout << "Default Constructor: " << name << std::endl;
    }
    // 拷贝构造函数
    Widget(const Widget& w) {
        name = w.name;
        std::cout << "Copy Constructor: " << name << std::endl;
    }
    // 拷贝赋值运算符
    Widget& operator=(const Widget& w) {
        if (this != &w) {  // 防止自赋值
            name = w.name;
        }
        std::cout << "Copy Assignment Operator: " << name << std::endl;
        return *this;
    }
    // 移动构造函数
    Widget(Widget&& rhs) noexcept {
        name = std::move(rhs.name);  // 使用 std::move 转移资源
        std::cout << "Move Constructor: " << name << std::endl;
    }
    // 移动赋值运算符
    Widget& operator=(Widget&& rhs) noexcept {
        if (this != &rhs) {
            name = std::move(rhs.name);  // 使用 std::move 转移资源
        }
        std::cout << "Move Assignment Operator: " << name << std::endl;
        return *this;
    }
};
int main() {
    // 1. 默认构造函数
    Widget w1;  // 调用默认构造函数
  
    // 2. 拷贝构造函数
    Widget w2 = w1;  // 调用拷贝构造函数

    // 3. 拷贝赋值运算符
    Widget w3;
    w3 = w1;  // 调用拷贝赋值运算符

    // 4. 移动构造函数
    Widget w4 = std::move(w1);  // 调用移动构造函数
    
    // 5. 移动赋值运算符
    Widget w5;
    w5 = std::move(w2);  // 调用移动赋值运算符

    return 0;
}
```



## ○An overview 

| 功能           | 函数                     |
| -------------- | ------------------------ |
| 默认构造函数   | `T()`                    |
| 析构函数       | `~T()`                   |
| 拷贝构造函数   | `T(const T&)`            |
| 拷贝赋值运算符 | `T& operator=(const T&)` |
| 移动构造函数   | `T(T&&)`                 |
| 移动赋值运算符 | `T& operator=(T&&)`      |

## ○Copy and copy assignment 



- ```cpp
  //赋值操作
  template <typename T>
  Vector<T>::Vector() {
      _size = 0;
      _capacity = 4;
      _data = new T[_capacity];
  }
  ```
  
- ```cpp
  //列表初始化
  template <typename T>
  Vector<T>::Vector() 
      : _size(0), _capacity(4), _data(new T[_capacity]) {}
  ```

**赋值操作发生在默认初始化之后,也就是说在被默认构造之后再进行一次赋值,列表初始化在构造函数执行之前就完成了初始化,避免了多次初始化问题.**

一个只能用`List Initialization`的例子

```cpp
template <typename T>
class MyClass
{
    const int _constant;
    int &_reference;

public:
    // Only way to initialize const and reference members
    MyClass(int value, int &ref) : _constant(value),_reference(ref) {}
};
```

#### ***默认的构造函数无法实例化`constant`   和 `& 引用`***

### **深拷贝和浅拷贝**

- 浅拷贝

  - ```cpp
    Vector<T>::Vector(const Vector<T> &other) 
        : _size(other._size), _capacity(other.capacity), _data(new T[other.capacity]){}
    
    ```

  - 浅拷贝将指针指向已经分配的数据,而不是新副本

- 深拷贝

  - ```cpp
    Vector<T>::Vector(const Vector<T> &other) 
        : _size(other._size), _capacity(other.capacity), _data(new T[other.capacity])
    {
        for (size i = 0; i < _size; ++i)
        {
            _data[i] = other._data[i];
        }
    }
    
    ```

  - 深拷贝拷贝出一个新的副本 独立于原来的那个

| **特性** | **Memberwise Copy (浅拷贝)** | **Deep Copy (深拷贝)** |
|---|--|--|
| **拷贝内容** | 只复制值，包括指针地址 | 复制所有资源的实际内容 |
| **动态资源** | 共享资源 | 独立资源 |
| **对象独立性** | 不独立 | 独立 |
| **实现复杂性** | 简单（默认行为） | 复杂（需手动实现） |
| **修改影响** | 修改一个对象可能影响另一个 | 修改一个对象不影响另一个 |

## ○default and delete 

```cpp
//禁用某些特殊成员函数的功能
class Widget {
public:
    Widget();                           		// 默认构造函数
    Widget(const Widget& w);            		// 拷贝构造函数
    Widget& operator=(const Widget& w); 		// 拷贝赋值运算符
    Widget(Widget&& rhs) = delete;      		// 移动构造函数
    Widget& operator=(Widget&& rhs)= delete;    // 移动赋值运算符
};	
```



### 我们可以有选择地启用特殊成员函数的功能！

● 这有许多应用场景，例如，如果只想允许一个实例的副本存在怎么办？
● 这正是像 `std::unique_ptr` 这样的类的工作方式！
●可以在 **[cppreference](https://en.cppreference.com/w/)** 中看到对此的具体说明。

`std::unique_ptr`,`std::fstream`只支持`Move Constructor`和`Move Assign Constructor`，不支持`Copy`的行为，目的避免拷贝行为，通过移动语义允许高效地转移资源的所有权。

### **零原则（Rule of Zero）：**

​	如果不需要构造函数、析构函数或拷贝赋值运算符等特殊成员函数（SMFs），那就不要去定义！
​	如果类依赖的对象或类已经实现了这些特殊成员函数，那么就没有必要重新实现这些逻辑

例如以下的`std::string`已经存在默认的`Deafult Constructor` 无需额外造轮子

```cpp
 class a_string_with_an_id() {
    public:
        /// getter and setter methods for our private variables
    private:
        int id;
        std::string str;
 }
 a_string_with_an_id object;

```



### ***随堂小测***

- ```cpp
  //写出构造函数的类型
  vector<int> func(vector<int> vec0) {
      vector<int> vec1;
      vector<int> vec2(3);
      vector<int> vec3{3};
      vector<int> vec4();
      vector<int> vec5(vec2);
      vector<int> vec6{};
      vector<int> vec7{static_cast<int>(vec2.size() + vec6.size())};
      vector<int> vec8 = vec2;
      vec8 = vec2;
      return vec8;
   }
  ```

- ```cpp
  答案:
  1.默认构造
  2.自定义构造 不是SMF
  3.初始化构造 不是SMF
  4.这个定义是错误的(笑)
  5拷贝构造
  6默认构造 列表初始化
  7列表初始化 构造函数
  8拷贝构造
  拷贝赋值操作
  return vec8:拷贝构造
  
  函数的参数:vector<int> func(vector<int> vec0)
  是一个拷贝构造
  
  ```

## ○Move and move assignment

`Copy Constructor` 和`Copy Assign Constructor` 会复制每一个元素 有的时候会造成很多不必要的浪费 于是`Move Constructor`和`Move Assign Constructor`出现了
