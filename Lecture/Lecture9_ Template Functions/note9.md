

>constraints:约束
>
>recursively:递归地

# Lecture10:Functions and Lambdas



## **Content:**

- Template Functions
- Concepts
- Variadic Templates(可变参数模板)
- 模板元编程Template MetaProgramming



## Template Functions:



**explicit instantiation:显式实例化**

**Implicit instantiation:隐式实例化**

```cpp
#include <iostream>
#include <set>
template <class T, class Y>
auto min_(const T &a, const Y &b)
{
    return a < b ? a : b;
}
template <class T, class Y>
auto find(const T &begin, const T &end, const Y &pattern)
{
    for (auto _it = begin; _it != end; ++_it)
    {
        if (*_it == pattern)
            return _it;
    }
    return end;
}
int main()
{
    std::cout << min_(555, 'a') << std::endl;
    std::set<std::string> v{"aaa", "bbb"};
    auto it = find(v.begin(), v.end(), "bbb");
    if (it != v.end())
        std::cout << "Found: " << *it << std::endl;
    else
        std::cout << "Not found." << std::endl;
    return 0;
}
```

## **Concept**

- ```cpp
  //example
  concept Comparable = requires(const T &a, const T &b) {
      { a < b } -> std::convertible_to<bool>;
  };
  ```

- 这个概念 `Comparable` 确保了类型 `T` 满足以下要求：

  - 你可以对两个类型为 `T` 的对象进行 `<` 比较。
  - 该比较操作必须返回一个能够转换为 `bool` 的结果。

- ```cpp
  template<typename T> requires Comparable<T>
  可以简写为
  template<Comparable T>
  ```

## **Variadic Templates **

- 在模板中递归,递归直至`vector`只有一个元素

- ```cpp
  concept Comparable = requires(const T &a, const T &b) {
      { a < b } -> std::convertible_to<bool>;
  };
  //template <Comparable T>
  template<typename T>
  T min__(const std::vector<T> &values)
  {
      if (values.size() == 1)
          return values[0];
      const auto &first = values[0];
      std::vector<T> rest(values.begin() + 1, values.end());
      auto m = min__(rest);
      return first < m ? first : m;
  }
  ```

可变参数模板:

- ```cpp
  concept Comparable = requires(const T &a, const T &b) {
      { a < b } -> std::convertible_to<bool>;
  };
  //template <Comparable T>
  template <typename T>
  T min__(const T &v){
      return v;
  }
  //处理只有一个元素的情况 
  template <typename T, typename... Args>
  T min__(const T &v, const Args &...args){
      T m = min__(args...);
      return v < m ? v : m;
  };
  //递归
  ```

- `typename... Args`

  - `typename... Args` 或 `class... Args`， `Args` 是一个用户自定义的占位符名称。它表示一个 **类型包**，即可以接受任意数量的类型参数

  - ```cpp
    template <typename T, typename... Args>
    T min(const T& v, const Args&... args)
    {
        T m = min(args...);  // 递归调用 min(args...)
        return v < m ? v : m;  // 比较 v 和递归结果 m，返回较小值
    }
    std::cout<<min__(22222222,3333,111)<<std::endl;
    //111
    ```

  - `T m = min(args...)`递归调用`min(args...)`，递归直到只有一个元素

## **模板元编程**

```cpp
template <size_t N>
struct Fac{
    enum{
        value = N * Fac<N - 1>::value
    };
};
template <>
struct Fac<0>{
    enum{
        value = 1
    };
};
```

```cpp
#include <iostream>
//常数编译时计算
//变量运行时计算
constexpr size_t fac_(size_t N)
{
    if (N == 0)
        return 1;
    return N * fac_(N - 1);
}
//只能传入常数 不能是变量
//编译时计算
consteval size_t fac__(size_t N)
{
    if (N == 0)
        return 1;
    return N * fac__(N - 1);
}

int main()
{
    std::cout << fac_(7) << std::endl;  // 输出 5040
    std::cout << fac__(7) << std::endl; // 输出 5040
    return 0;
}

```



### **区别总结**

| 特性             | `constexpr`                          | `consteval`                        |
| ---------------- | ------------------------------------ | ---------------------------------- |
| **编译时求值**   | 可选，取决于输入是否为编译时常量     | 强制，必须在编译时求值             |
| **运行时求值**   | 允许，支持运行时求值                 | 不允许，编译时常量必须传递给函数   |
| **常见使用场景** | 通常用于希望编译时优化计算的函数     | 通常用于要求必须在编译时计算的场景 |
| **灵活性**       | 较高，可以在编译时和运行时都能使用   | 较低，只能用于编译时计算           |
| **错误检查**     | 错误检查较晚，依赖于实际的运行时输入 | 错误检查较早，必须是常量表达式     |

