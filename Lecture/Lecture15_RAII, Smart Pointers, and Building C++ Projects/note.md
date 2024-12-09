>exception:异常
>
>emblematic:有代表性的
>
>abide:遵守
>
>compliant:服从的,遵从的
>
>underlying memory :底层内存
>
>mitigate circular dependencies:缓解循环依赖
>
>deallocated memory:已经释放的内存
>
>circular dependencies:循环依赖

# RAII, Smart Pointers,  Building Projects

## **0.Exceptions**

`Excepttions`是一种解决代码中错误的方式，通常都会被`thrown(抛出)`，可以通过`catch`的方式捕获异常来解决错误，使得代码正常运行

```cpp
try{
    //code here for checking exception
}
catch([exception type]e1){
    //some behavior
}
catch([exception type]e2){
    //like else if
}
catch{
    //like else 
}
```

看一个example可能存在的问题

```cpp
std::string returnNameCheckPawsome(int petId) {
    Pet* p = new Pet(petId);
    p->firstName("Fluffy");
    if (p->type() == "Dog") {
        //"=="可能未重载	
        std::cout << p->firstName() << " is pawsome! " << p->lastName() << std::endl;
        //<<可能有误
    }
    std::string returnStr = p->firstName() + p->lastName();
    delete p;//和第一行的Pet* p对应 可能内存泄漏
    return returnStr;
}

```



| **资源类型** | **获取操作**         | **释放操作** |
| ------------ | -------------------- | ------------ |
| **堆内存**   | `new`                | `delete`     |
| **文件**     | `open`               | `close`      |
| **锁**       | `try_lock` 或 `lock` | `unlock`     |
| **套接字**   | `socket`             | `close`      |

## 1.RAII (Resource Acquisition Is Initialization) 

***RAII：资源获取即初始化***



RAII 是 C++ 编程中的一种重要设计理念，它的核心思想是：

- **资源的获取与对象的生命周期绑定**。即当对象被创建时，资源（如内存、文件句柄、网络连接、锁等）被分配；当对象生命周期结束时，资源会自动释放。

RAII 的好处是避免了资源泄漏和忘记释放资源的错误，特别是在发生异常时。通过局部对象的生命周期管理资源，确保资源能够自动释放。

`class`使用的资源在构造函数获取,使用的所有资源在析构函数释放

看一个例子

```cpp
void cleanDatabase(mutex& databaseLock, map<int, int>& db) {
    databaseLock.lock(); 
    // no other thread or machine can change database
    // modify the database
    // if any exception is thrown, the lock never unlocks!
    database.unlock();
}
//如果这三行注释的内容抛出了异常 那么db将不能被解锁
//把他修改为以下
void cleanDatabase(mutex& databaseLock, map<int, int>& db) {
	lock_guard<mutex> lg(databaseLock); 
    //lock_guard是一个遵循RAII设计的包装器 超出作用域后便会释放锁
    
    // no other thread or machine can change database
    // modify the database
    // if any exception is thrown, the lock never unlocks!
}
```



## 2.Smart Pointers 

遵循RAII的锁  → `lock_guard`
● 创建一个新对象，在构造函数中获取资源，在析构函数中释放资源

遵循RAII 的内存 → 像锁一样 🥳
● 这些“包装器”指针被称为“智能指针”。

有三类智能指针:

- `std::unique_ptr`:唯一指针,无法被复制
- `std::shared_ptr`:共享指针,当作用域超出底层内存销毁
- `std::weak_ptr`:弱指针,设计来循环依赖使用

### **`std::unique_ptr`**

```cpp
void rawPtrFn(){
    std::unique_ptr<node> n(new Node);
    //以下会编译错误 因为unique_ptr不允许复制
	std::unique_ptr<node> cpoy = n;
}
```

## **`std::shared_ptr`**

`shared_ptr`解决了复制`std::unique_ptr`指针的问题:在`shared_ptr`超出作用域之前，底层内存不会泄露

![shared_ptr工作原理](D:\code\Courses\CS106L fall 24\Lecture\Lecture15_RAII, Smart Pointers, and Building C++ Projects\shared_ptr工作原理.png)

对工作原理的解释:`shared_ptr`有两个部分:指向`T Object`的普通指针和指向`Control Block(控制块)`指针

- 指向Data的指针用于访问数据

- 指向`Control Block`的指针用于管理数据,有三个用途

  - #### (1) **Reference Count (引用计数)**

    - 记录当前有多少个 `shared_ptr` 实例共享这个对象。
    - 每次复制 `shared_ptr`，引用计数增加；当某个 `shared_ptr` 离开作用域或被销毁时，引用计数减少。
    - 当引用计数减为零时，`T Object` 会被释放。

    #### (2) **Weak Count (弱引用计数)**

    - 记录当前有多少个 `std::weak_ptr` 引用该对象。
    - `weak_ptr` 不会影响引用计数（`Reference Count`），主要用于防止循环引用问题。
    - 当引用计数和弱引用计数都为零时，控制块会被释放。

    #### (3) **Custom Deleter, Allocator**

    - 控制块可以存储自定义删除器（`Custom Deleter`）或分配器（`Allocator`），用于在对象销毁时执行特定逻辑。



如何初始化智能指针?

```cpp
//std::unique_ptr<T> uniquePtr{new,T);
std::unique_ptr<T> uniquePtr = std::make_unique<T>();

//std::unique_ptr<T> uniquePtr{new,T);
std::unique_ptr<T> sharedPtr = std::make_shared<T>();

std::weak_ptr<T> wp = sharedPtr;
```

## ***讲讲相比起`new T` ，使用`std::make_unique`和`std::make_shared`的好处***

```cpp
struct Example {
    Example(int x) {
        if (x < 0) throw std::runtime_error("Invalid value");
    }
};

std::unique_ptr<Example> ptr(new Example(-1)); // 构造函数抛出异常
//对于这段代码  会抛出runtime_error的异常
//使用new的话 会出现分配了内存 但是因为出现了异常 动态内存块会变成未绑定的孤立状态
//此时的ptr 没有被绑定到内存 动态分配的内存无人管理 造成内存泄漏(memory leak)

std::unique_ptr<Example> ptr = std::make_unique<Example>(-1);
//std::make_unique 执行对象分配和 std::unique_ptr 的绑定操作。
//相比之下 智能指针 std::make_unique 在检查到异常的时候，分配失败的内存会自动回收
```



为什么使用`std::unique_ptr 和std::unique_ptr<T>`s

### **避免内存分配两次**

- ```cpp
  std::shared_ptr<int> sp(new int(42));
  //new int(42) 分配了 int 的内存。
  //std::shared_ptr 为控制块（包含引用计数等）额外分配了内存。
  std::shared_ptr<int> sp = std::make_shared<int>(42);
  //使用 std::make_shared 时，对象和控制块分配在一块连续内存中，减少了一次堆内存分配的开销。
  
  ```



### **`std::weka_ptr`**

弱指针是一种避免代码中循环依赖的方法，以防止内存泄漏

```cpp
#include <iostream>
#include <memory>  // 使用 std::shared_ptr

class B;  // 前向声明 B 类

class A {
public:
    std::shared_ptr<B> ptr_to_b;  // A 持有指向 B 的 shared_ptr

    ~A() {
        std::cout << "All of A's resources deallocated" << std::endl;
    }
};

class B {
public:
    std::shared_ptr<A> ptr_to_a;  // B 持有指向 A 的 shared_ptr

    ~B() {
        std::cout << "All of B's resources deallocated" << std::endl;
    }
};

int main() {
    std::shared_ptr<A> shared_ptr_to_a = std::make_shared<A>();  // 创建 A 的 shared_ptr
    std::shared_ptr<B> shared_ptr_to_b = std::make_shared<B>();  // 创建 B 的 shared_ptr

    shared_ptr_to_a->ptr_to_b = shared_ptr_to_b;  // A 指向 B
    shared_ptr_to_b->ptr_to_a = shared_ptr_to_a;  // B 指向 A
    // 当 shared_ptr 离开作用域时，资源会被自动释放
    return 0;
}
```

这里的两个指针`shared_ptr_to_a 和 shared_ptr_to_b`相互引用,导致他们的计数无法归零,内存会泄露

```cpp
class B {
public:
    std::weak_ptr<A> ptr_to_a;  // 使用 weak_ptr 避免循环引用
    ~B() {
        std::cout << "All of B's resources deallocated" << std::endl;
    }
};
```

改为`std::weak_ptr`后,B不会增加A的引用计数，能够正确释放

## 3.Building C++ projects

如何编译一个cpp文件

```sh
$ g++ main.cpp -o main 
# g++是编译器 输出二进制文件main
# g++ 编译命令
# main.cpp 源代码
# -o 指定输出文件的名称

$ ./main
# 运行main文件

```

简单介绍`Makefile` `make` `cmake`

`Makefile`用来设置编译器的版本和其他的参数

```makefile
# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++20

# Source files and target
SRCS = ../main.cpp $(wildcard ../src/*.cpp)
TARGET = main

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

# Target to enable virtual inheritance
virtual: CXXFLAGS += -DVIRTUAL_INHERITANCE
virtual: $(TARGET)

# Clean up
clean:
	rm -f $(TARGET)

```



`Cmake`用来构筑`Makefiles`

```cmake
 cmake_minimum_required(VERSION 3.10)
 project(cs106l_inheritance)
 set(CMAKE_CXX_STANDARD 20)
 include_directories(include)
 add_definitions(-DVIRTUAL_INHERITANCE)
 file(GLOB SRC_FILES "src/*.cpp")
 add_executable(main main.cpp ${SRC_FILES})
```

总结:

`RAII`原则动态分配资源和释放资源     



![C++Iceberg](D:\code\Courses\CS106L fall 24\Lecture\Lecture15_RAII, Smart Pointers, and Building C++ Projects\C++Iceberg.png)

```cpp
const T& operator*() const{}
const T& operator*() {}
T& operator*() const {}
这三者的区别
```

### 区别：

| **特性**                            | **`const T& operator\*() const`**                    | **`const T& operator\*()`**                              | **`T& operator\*() const`**                             |
| ----------------------------------- | ---------------------------------------------------- | -------------------------------------------------------- | ------------------------------------------------------- |
| **返回类型**                        | `const T&`（常量引用）                               | `const T&`（常量引用）                                   | `T&`（非常量引用）                                      |
| **成员函数是否是 `const` 成员函数** | 是 (`const`)                                         | 否                                                       | 是 (`const`)                                            |
| **能否修改解引用的值**              | 不可以                                               | 不可以                                                   | 可以                                                    |
| **适用对象类型**                    | 适用于 `const` 对象                                  | 适用于 `const` 和非 `const` 对象                         | 只能用于 `const` 对象，不能修改其成员                   |
| **典型用途**                        | 用于读取对象的值，不修改它，通常用于智能指针、容器等 | 用于返回不可修改的引用，适用于 `const` 和非 `const` 对象 | 非常罕见，通常用于返回引用，但不应该用在 `const` 对象上 |