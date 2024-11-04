# Template_Functions



## 一些函数用法

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





***Implicit Interface***



