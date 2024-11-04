# Lecture 6: Iterators

## Iterator Basics(迭代器基础)

- ```cpp
  //容器接口:
  containers.begin()
  containers.end()
  ```

- `containers.end()`不指向一元素,他指向容器的最后一个位置,通常是一个无效的元素

- ```cpp
  //以下两段代码等效:
  for(auto it:s){
      std::cout<<it<<std::endl;
  }
  for(auto it = s.begin() ; it!=s.end() ; it++){
      auto elem = *it;
      std::cout <<elem<<std::endl;
  }
  ```

- 关于`iterator`的类型

  - 以下例子

  - ```cpp
    //iterator类型只与容器有关
    std::map<int,int>::itertator 
    std::list<double>::iterator 
    std::vector<int>::iterator
    ```

- 关于`++it`和`it++`

  - ```cpp
    // 前置 ++it
    // 递增 it 并返回对同一对象的引用
    Iterator& operator++();
    
    // 后置 it++
    // 递增 it 并返回旧值的副本
    // Increments it and returns a copy of the old value
    Iterator operator++(int);
    ```

- ##### 支持访问不同的容器迭代器

- ![749ce1e9e9de1821bcbd727bc500397d](F:\Tencent software\QQ\Chat_stored\Tencent Files\937623624\nt_qq\nt_data\Pic\2024-10\Ori\749ce1e9e9de1821bcbd727bc500397d.png)

- 通过迭代器访问容器

  - ```cpp
    	//vector
    	std::vector<int> vec = {1, 2, 3, 4, 5};
        for (auto it = vec.begin(); it != vec.end(); ++it) {
            *it += 1; // 可以修改元素
        }
        for (const auto &val : vec) {
            std::cout << val << " "; // 输出: 2 3 4 5 6
        }
    	//deque
        std::deque<int> deq = {1, 2, 3, 4, 5};
        for (auto it = deq.begin(); it != deq.end(); ++it) {
            *it *= 2; // 可以修改元素
        }
        for (const auto &val : deq) {
            std::cout << val << " "; // 输出: 2 4 6 8 10
        }
    	//list
        std::list<int> lst = {1, 2, 3, 4, 5};
        for (auto it = lst.begin(); it != lst.end(); ++it) {
            *it += 10; // 可以修改元素
        }
        for (const auto &val : lst) {
            std::cout << val << " "; // 输出: 11 12 13 14 15
        }
    	//set
        std::set<int> mySet = {1, 2, 3, 4, 5};
        for (auto it = mySet.begin(); it != mySet.end(); ++it) {
            std::cout << *it << " "; // 只读访问
        }
    	//map
        std::map<int, std::string> myMap = {{1, "one"}, {2, "two"}, {3, "three"}};
        for (auto it = myMap.begin(); it != myMap.end(); ++it) {
            std::cout << it->first << ": " << it->second << "\n"; // 只读访问
        }
    	//unorderded_se
        std::unordered_set<int> myUSet = {1, 2, 3, 4, 5};
        for (auto it = myUSet.begin(); it != myUSet.end(); ++it) {
            std::cout << *it << " "; // 只读访问
        }
    ```
  
  - 
  
- 如何获得地址

  - ```cpp
    #include <iostream>
    int main() {
        int x = 106;          
        int* px = &x;
        // 指针px指向x的地址 可以通过*px来访问x的值
        std::cout << x << std::endl;    // 输出 x 的值
        std::cout << *px << std::endl;   // 通过指针输出 x 的值
        std::cout << px << std::endl;    // 输出指针 px 的地址 例如：0x50527c
        return 0;
    }
    
    ```
    
  - 
