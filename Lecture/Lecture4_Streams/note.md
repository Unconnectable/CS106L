# 04_Streams

## 2.What are streams

- iostream是istream和ostream的交集



## 3.stringstream

- `stringstream` 在处理混合数据类型的用例中非常有用。

- `>>` 运算符只会读取到下一个空白字符为止。

- ```cpp
  #include <iostream>
  #include <sstream>
  #include <string>
  
  int main() {
      // 部分 Bjarne 引述
      std::string initial_quote = "Bjarne Stroustrup C makes it easy to shoot yourself in the foot";
      
      // 创建一个 stringstream
      std::stringstream ss(initial_quote);
      
      // 数据接收目的地
      std::string first;
      std::string last;
      std::string language, extracted_quote;
      
      // 从 stringstream 中提取内容
      ss >> first >> last >> language;
      //此时first是Bjarne last是Stroustrup language是C
      // 获取剩余的句子
      std::getline(ss, extracted_quote);
      //extracted_quote是剩下的所有
      // 输出结果
      std::cout << first << " " << last << " said this: " << language << " " << extracted_quote << std::endl;
  
      return 0;
  }
  ```

- 

- ```shell
  istream& getline(istream& is, string& str, char delim)
  ● getline() 从输入流 is 中读取内容，直到遇到分隔符字符 delim，并将其存储在缓冲区 str 中。
  ● 默认的分隔符字符是 ‘\n’（换行符）。
  ● getline() 会消耗掉分隔符字符！
  ○ 注意这一点 :) 
  
  ```



## 4.cout and cin

- 输出流中的字符会先存储在一个中间缓冲区中，然后再被刷新到目的地。

- `std::flush` 刷新  是一个用于刷新输出流的操作，它会将缓冲区中的内容立即写入到对应的输出设备

- ```cpp
  #include <iostream>
  using namespace std;
  
  int main() {
      cout << "Hello, ";
      cout.flush();  // 强制刷新缓冲区，立即输出内容
      cout << "World!" << endl;  // 这行会自动刷新缓冲区
      return 0;
  }
  ```

- **Buffer（缓冲区）** 是一个内存区域，用于临时存储数据，以便高效地读写数据。在 C++ 中，输出流（如 `std::cout`）和输入流（如 `std::cin`）都使用缓冲区来提高效率。缓冲区将数据暂时存储在内存中

- `std::endl` 还会告诉流刷新缓冲区!!

- ```cpp
  int main() 
  {
  	for (int i=1; i <= 5; ++i)
  	std::cout << i << std::endl;
      
      return 0;
  }
  ```

- 拿以上代码举例 Intermediate buffer（中间缓冲区）会接受到 `1` `'\n'` ，然后会被立刻刷新，送到output

- 如果是仅仅`std::cout<< i << '\n' `就不会立刻flush,而是会把东西存储在中间缓存区，最后进行output

- 当缓冲区的容量达到一定限制时，它会被自动刷新

- **`cerr` 和 `clog`**

  - **`cerr`**: 用于输出错误信息（无缓冲）。
  - **`clog`**: 用于记录非关键事件日志（缓冲）。

- ***Output File Streams***

  ```cpp
  #include <iostream>
  #include <fstream>
  
  int main() {
      std::ofstream ofs("hello.txt");
  
      if (ofs.is_open()) {
          ofs << "Hello CS106L!" << '\n';
      }
  
      ofs.close();  // 关闭文件
  
      // 重新打开文件并写入
      ofs.open("hello.txt");
      if (ofs.is_open()) {
          ofs << "this will though! It’s open again";
      }
  
      return 0;
  }
  
  ```

  - 以上的文件内容只会有`"this will though! It’s open again";`因为使用的是截断模式 在`ofs.open("hello.txt"，std::ios::app)`改为追加模式能持续输入文件

***Input File Streams***

- `c++`的制表符包括`'\n`  换行符 ` \t'  制表符`  `' '`空白符
- 总结（主要要点）：
  1. 流是用于在程序中读取和写入数据的通用接口。
  2. 同一源/目标类型的输入流和输出流相辅相成！
  3. 除非确实非常需要，不要同时使用 `getline()` 和 `std::cin()`！