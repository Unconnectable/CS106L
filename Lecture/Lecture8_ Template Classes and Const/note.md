# ***Template Classes and Const***

>Preprocessor :预处理器
>
>macro:宏

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