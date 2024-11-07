>
>
>Predicate Function:(谓词函数)是指返回布尔值(`true` 或 `false`)的函数
>
>Unary:一元运算
>
>Binary:二元
>
>functor:函子

# ***Template_Functions***

## ***一些函数用法***

- ```cpp
  //lambda函数
  //正常写法:
  bool cmp(int a,int b){
      return a<b;
  }
  sort(array.begin(),array.end(),cmp)
  //lambda写法
  sort(array.begin(),array.end(),[](int a,int b){return a<b});
  
  //简单讲解lambda的用法
  [捕获列表](参数列表) -> 返回类型 {
      // 函数体
  }
  
  auto generic_lambda = [](auto param1, auto param2){
      //body
  };
  [&]引用外界全部变量 [=]按值捕获全部   
  [=var1,&] 复制var1,其他引用
  [&var1,=] 引用var1,其他复制
  ```

- ```cpp
  //copy_if
  template <class InputIt, class OutputIt, class UnaryPredicate>
  OutputIt copy_if(InputIt first, InputIt last, OutputIt d_first, UnaryPredicate pred);
  //举例
  std::vector<int> numbers = {1, 2, 3, 4, 5, 6};
  std::vector<int> evens;
  
  // 使用 std::copy_if 复制偶数到 evens 容器
  std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(evens), [](int num){
      return num % 2 == 0; // 偶数的条件
  });
  ```

- ```cpp
  //copy
  std::copy(InputIterator first, InputIterator last, OutputIterator result);
  //Example
  std::vector<int> source = {1, 2, 3, 4, 5};
  std::vector<int> destination(5); // 创建一个目标容器，大小与源相同
  
  // 使用 std::copy 复制元素
  std::copy(source.begin(), source.end(), destination.begin());
  //copy vec的元素输出到控制台
  std::copy(vec.begin(), vec.end(), std::ostream_iterator<StructName>(std::cout, "\n"));
  ```

- ```cpp
  //remove_if
  template<class ForwardIt, class UnaryPredicate>
  ForwardIt remove_if(ForwardIt first, ForwardIt last, UnaryPredicate p);
  //Example
  std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  
  // 使用 std::remove_if 移除所有偶数 
  auto new_end = std::remove_if(numbers.begin(), numbers.end(), [](int x) {
          return x % 2 == 0;
  });
  numbers.erase(new_end, numbers.end());//erase才真正删除这些元素 否则仅仅是移到末尾
  
  //将二者结合
  vec.erase(std::remove_if(numbers.begin(), numbers.end(), rule),vec.end());
  
  ```

- `getline`

  - ```cpp
    std::istream& getline(std::istream& is, std::string& str, char delim);
    //默认分隔符是换行
    //对于某些文件 首先可以先读取全部 然后再读取他的每一行
    //例如以下的这样以","为分割的文件 先while (std::getline(filename, line)) { // 逐行读取 然后再读取他每一行的元素 while (std::getline(ss, value, ',')) {
    /*
    aaa,vvv,ccc
    ddd,eee,fff
    ddd,eee,fff
    ddd,eee,fff
    ddd,eee,fff
    ddd,eee,fff
    ddd,eee,fff
    */
    #include <iostream>
    #include <fstream>
    #include <string>
    #include <sstream>
        
    int main() {
        std::ifstream filename("data.txt"); // 假设文件名为 data.txt
        std::string line;
    
        if (filename.is_open()) {
            while (std::getline(filename, line)) { // 逐行读取
                std::stringstream ss(line); // 将每一行放入 stringstream
                std::string value;
    
                // 使用 getline 以逗号为分隔符读取每个值
                while (std::getline(ss, value, ',')) {
                    std::cout << value << std::endl; // 输出读取的值
                }
            }
        }
        filename.close(); // 关闭文件
        return 0;
    }
    ```

  - 

# 以下是正文

**Functions and Lambdas**

- How can we represent functions as variables in C++?
  - 我们如何在 C++ 中将函数表示为变量？

**Algorithms**

- Revisiting an old algorithm you may have seen before in modern C++
  - 在现代 C++ 中重新审视你可能以前见过的旧算法

**Ranges and Views**

- A brand new (C++26), functional approach to C++ algorithms
  - 一种全新的（C++26）函数式方法来处理 C++ 算法



## ***Functions and Lambdas***

- 把谓词函数当成参数传入模板

- ```cpp
  template <typename It, typename Pred>
  It find(It first, It last, Pred pred)
  {
      for (auto it = first; it != last; ++it)
      {
          if (pred(*it))
              return it;
      }
      return last;
  }
  ```

- 

  ```cpp
  /*这里的的第三个参数调用了lambda函数作为PredicateFunction谓词函数传入参数
  [](auto c){
  	c = std::toupper(static_cast<unsigned char>(c));  // Convert to uppercase
      return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
  } 
  */
  auto it = std::find_if(corlys.begin(), corlys.end(),
      [](auto c) {
          c = std::toupper(static_cast<unsigned char>(c));  // Convert to uppercase
          return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
      });
  ```

- 以下代码等同

- ```cpp
  //lambda
  int n = 10;
  auto f = [n](int x) { return x < n; };
  find_if(begin, end, f);
  
  //和以下等同
  class lambda_name
  {
  public:
      bool operator()(int x) const { return x < n };
      lambda_name(int &_n) : n { _n } {};
  
  private:
      int n;
  };
  int n = 10;
  auto f = lambda_name{n};
  find_if(beign, end, f);
  ```

- **使用函数/λ表达式传递行为作为变量**

  - **附注：** `std::function` 是一个用于函数/λ表达式的通用类型。
  - 任何 **函数对象**（functor）、**λ表达式** 或 **函数指针** 都可以转换为 `std::function` 类型。
  - 它的性能稍微慢一些。
  - 使用 `auto` 或模板，并不太担心类型问题。

- ```cpp
  std::function<bool(int, int)> less = std::less<int>{};
  std::function<bool(char)> vowel = isVowel;
  std::function<int(int)> twice = [](int x)
  ```



## **`Lambda`函数在算法库的应用**

- ## `<algorithm>是模板函数的集合`

- Soundex编码规则

### Soundex编码规则

1. **保留首字母**：保留单词的第一个字母（字母不编码）。
2. **编码其余字母**：将每个字母转换为一个数字（除去首字母），具体映射规则如下：
   - `B`, `F`, `P`, `V` 映射为 `1`
   - `C`, `G`, `J`, `K`, `Q`, `S`, `X`, `Z` 映射为 `2`
   - `D`, `T` 映射为 `3`
   - `L` 映射为 `4`
   - `M`, `N` 映射为 `5`
   - `R` 映射为 `6`
3. **删除元音和某些辅音**：去掉元音（`A`, `E`, `I`, `O`, `U`, `Y`, `H`, `W`），它们不编码。
4. **合并相邻的重复编码**：如果两个相邻的字母映射到相同的数字，则只保留一个。例如，`BB` 映射为 `1`，不会重复。
5. **编码长度**：最终结果应为4位：
   - 若编码不足4位，用 `0` 填充至4位。
   - 若编码超过4位，截断到前4位。

### 示例

- Robert的 Soundex 编码步骤为：
- 保留首字母 `R`
- 将 `O`, `B`, `E`, `R`, `T` 转换为 `0`, `1`, `0`, `6`, `3`
- 去掉 `0` 并合并重复项，得出 `R163`

因此，`Robert` 的 Soundex 编码为 `R163`，以下是代码

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
std::vector<char> letters = {'a', 'e', 'i', 'u', 'o'};

std::string Transform_(const std::string &words)
{
    std::vector<char> words_t;
    std::transform(words.begin(), words.end(), std::back_inserter(words_t),toupper);
    std::string Soundex_code;
    auto judge = [](const char &x)
    {
        if (x == 'B' || x == 'F' || x == 'P' || x == 'V')
        {
            return '1';
        }
        else if (x == 'C' || x == 'G' || x == 'J' || x == 'K' || x == 'Q' || x == 'S' || x == 'X' || x == 'Z')
        {
            return '2';
        }
        else if (x == 'D' || x == 'T')
        {
            return '3';
        }
        else if (x == 'L')
        {
            return '4';
        }
        else if (x == 'M' || x == 'N')
        {
            return '5';
        }
        else if (x == 'R')
        {
            return '6';
        }
        else
        {
            return '0';
        }
    };
    Soundex_code += words_t[0];

    for (auto it = words_t.begin() + 1; it != words_t.end(); ++it)
    {
        char soundex_char = judge(*it);

        if (soundex_char != Soundex_code.back() and soundex_char != '0')
        {
            Soundex_code += soundex_char;
        }
    }
    Soundex_code.resize(4, '0');
    return Soundex_code;
}

int main()
{
    std::string original_code;
    std::cin >> original_code;
    std::cout << Transform_(original_code);
    return 0;
}
```

