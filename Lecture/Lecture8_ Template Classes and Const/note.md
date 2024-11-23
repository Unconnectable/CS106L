# ***Template Classes and Const***

>Preprocessor :预处理器
>
>macro:宏
>
>A bit of history:简史

## ***ReCall***

### **函数签名：**

- 函数签名包括 **函数名**、**参数类型**（包括参数的个数、类型、顺序）以及 **返回类型**。
- 函数签名必须保持一致，不能在类内声明时使用一个签名，而在类外定义时修改签名。

### **参数类型**：

- 类内声明时，如果定义了 `void pop_back()`, 那么你在类外定义时必须保持相同的参数（即无参数）。
- 你不能在类外将 `void pop_back()` 改为 `void pop_back(int x)`，这会导致 **签名不一致** 的问题。

### **返回类型**：

- 类内声明的返回类型必须与类外定义的返回类型一致。例如，如果在类内声明 `T pop_back()`，那么在类外定义时必须也是 `T pop_back()`，不能更改为 `int pop_back()` 或其他类型。

### **函数的实现**：

- 函数的具体实现可以在类内或类外提供，但**签名必须一致**。如果你在类内定义了函数的实现，那么你在类外定义时就不需要再次实现它。
- 反之，如果你只在类内声明了函数（没有提供实现），那么你需要在类外提供实现。

## Template Classes 

- 一个例子

- `\`表示连接符 作用是将下一行与当前行连接成一行 

- **`##` 的作用**：在宏定义中将两个标记拼接成一个 这里的`MY_TYPE`和`Vector`拼接起来

- ```cpp
  #define GENERATE_VECTOR(MY_TYPE)                             \
  class MY_TYPE##Vector {                                     \
  public:                                                     \
      MY_TYPE& at(size_t index);                             \
      void push_back(const MY_TYPE& elem);                   \
                                                             \
  private:                                                    \
      MY_TYPE* elems;                                        \
      size_t logical_size;                                   \
  };
  ```
  
- ```cpp
  //如何调用
  //无需田间分号 宏定义已经补全了’；‘
  GENERATE_VECTOR(int)      // 生成 intVector 类
  GENERATE_VECTOR(double)   // 生成 doubleVector 类
  GENERATE_VECTOR(string)   // 生成 stringVector 类
  
  int main() {
      intVector iv;
      doubleVector dv;
      stringVector sv;
      return 0;
  }
  ```

- 使用`.h`文件调用 `.h`文件内容如下

- ```cpp
  //grandmas_template.h
  
  #define GENERATE_VECTOR(MY_TYPE)                             \
  class MY_TYPE##Vector {                                     \
  public:                                                     \
      MY_TYPE& at(size_t index);                             \
      void push_back(const MY_TYPE& elem);                   \
                                                             \
  private:                                                    \
      MY_TYPE* elems;                                        \
      size_t logical_size;                                   \
  };
  ```

- ```cpp
  //example.cpp
  #include "grandmas_template.h"
  GENERATE_VECTOR(int)  // 宏展开为 intVector 类定义
  intVector v1;
  v1.push_back(5);
  ```



### ***Template Class***

- ```cpp
  //使用template 替代intVector doubleVector stringVector etc.
  template <typename T>
  class Vector{
  public:
      T& at(size_t index);
      void push_back(const T& elem);
  private:
      T* elems;
  };  
  
  int main(){
      Vector<int>intVec;
      Vector<double>doubleVec;
      Vector<string>string;
      Vector<Vector<int> >vecVec;
      struct MyCustomType {};
      Vector<MyCustomType>structVec;
      return 0;
  }
  ```

- 当在使用`.h`文件 以下是要注意的地方

- ```cpp
  // StrVector.h
  class StrVector
  {
  public:
      string &at(size_t i);
  };
  
  // StrVector.cpp
  #include "StrVector.h"
  string &StrVector::at(size_t i)//使用::访问类的成员函数
  {
      // Implementation..
  }
  ```

- `typename 和 class`是一样的

- ```cpp
  template <typename K, typename V>
  struct pair;
  template <class K, typename V>
  struct pair;
  ```

**`const`**在前和在后的区别

- **`const` 放在成员函数声明的后面**，表示这是一个 **常量成员函数**（const member function）。

  这个函数 **不会修改类的成员变量**，并且你只能在 **`const`** 类型的对象上调用这个函数（即那些被声明为 **`const`** 的对象）。

- **`const` 放在返回类型前面**，表示返回的值是常量，即返回一个 `const` 类型的 `int`。

  这意味着你不能修改返回值。这个 `const` 修饰的是函数的返回值类型，而不是成员函数本身。

以下例子

- ```cpp
  template <class T>
  class Vector
  {
  public:
      size_t size();
      bool empty() const;
      T &operator[](size_t index);
      T &at(size_t index);
      void push_back(const T &elem);
  private:
      T *elems;
  };
  void printVec(const Vector<T> &v)
  {
      for (size_t i = 0; i < v.size(); ++i)
      {
          std::cout << v.at(i) << std::endl;
      }
  }
  ```

- `void printVec(const Vector<T> &v)`的参数是`const`类型,函数调用的`class里的函数 size()和at()`不能修改成员变量 需要在`class`里面后置声名`const`

- ```cpp
  //也就是这样 后置声名const
  template <class T>
  class Vector
  {
  public:
      size_t size() const;
      bool empty() const;
      T &operator[](size_t index);
      T &at(size_t index) const;
      void push_back(const T &elem);
  private:
      T *elems;
  };
  ```

### **`const_cast`**

- ```cpp
  
  template <typename T>
  T &Vector<T>::findElement(const T &value)
  {
      for (size_t i = 0; i < logical_size; i++)
      {
          if (elems[i] == elem)
              return elems[i];
      }
      throw std::out_of_range("Element not found");
  }
  
  const T &Vector<T>::findElement(const T &value) const
  {
      return const_cast<Vector<T> &>(*this).findElement(value);
  }
  ```

- `const_cast<new_type>(expression)`

- 我放弃了 这太难了

- 最好不要使用`const_cast`

- ```cpp
  struct MutableStruct
  {
      int dontTouchThis;
      mutable double iCanChange;  // 这里是 mutable，允许修改
  };
      const MutableStruct cm;
      // cm.dontTouchThis = 42; // 这行会报错，因为 dontTouchThis 不是 mutable
      cm.iCanChange = 3.14;  // 这行是正确的，因为 iCanChange 是 mutable
      return 0;
  ```

- 