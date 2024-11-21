# ***Template Classes and Const***

>Preprocessor :预处理器
>
>macro:宏

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
  //   \表示连接符 作用是将下一行与当前行连接成一行
  // 如何调用这个代码
  GENERATE_VECTOR(int)  // 这将生成 intVector 类
  ```

- 