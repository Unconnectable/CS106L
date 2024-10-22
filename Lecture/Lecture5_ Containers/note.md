# Containers

## 所有类型都可以使用的初始化方式是 **统一初始化**（Uniform Initialization）

- ```cpp
  int x {10};              // 基本类型
  std::vector<int> v {1, 2, 3};  // 容器
  Student jacob {"Jacob", "NM", 21};  // 类类型
  ```

## 今天的议程

- 什么是 STL？什么是模板？

- “标准模板库”STL（The Standard Template Library）

  - **序列容器**：如 `std::vector`、`std::list` 等

    **关联容器**：如 `std::map`、`std::set` 等

    **算法**：如排序算法、查找算法等（例如 `std::sort` `std::find`）

    **迭代器**：用于遍历容器元素

## Sequence containers(序列容器)

- 如 `std::vector`、`std::list` 等

- ```cpp
  #include <vector>
  #include <iostream>
  
  int main(){
      std::vector<int> vec { 1, 2, 3, 4 };
      vec.push_back(5);
      vec.push_back(6);
      vec[1] = 20;
      for (size_t i = 0; i < vec.size(); i++) {
          std::cout << vec[i] << " ";
      }
  
      return 0;
  }
  ```

- ### Stanford vs. STL `std::vector`

  | **What you want to do?**                         | **Stanford `Vector<int>`** | **`std::vector<int>`**        |
  | :----------------------------------------------- | -------------------------- | ----------------------------- |
  | **Create an empty vector**                       | `Vector<int> v;`           | `std::vector<int> v;`         |
  | **Create a vector with `n` copies of 0**         | `Vector<int> v(n);`        | `std::vector<int> v(n);`      |
  | **Create a vector with `n` copies of value `k`** | `Vector<int> v(n, k);`     | `std::vector<int> v(n, k);`   |
  | **Add `k` to the end of the vector**             | `v.add(k);`                | `v.push_back(k);`             |
  | **Clear the vector**                             | `v.clear();`               | `v.clear();`                  |
  | **Check if `v` is empty**                        | `if (v.isEmpty())`         | `if (v.empty())`              |
  | **Get the element at index `i`**                 | `int v = v.get(i);`        | `int k = v[i];` or `v.at(i);` |
  | **Replace the element at index `i`**             | `v.get(i) = k;`            | `v[i] = k;` or `v.at(i) = k;` |


- `v.at(i)=k` 和 `v[i]=k` 都是修改`v[i]` 的值

- 区别在 `at()` 是一个成员函数，它会先检查 `i` 是否在有效的范围内（即 `0 <= i < v.size()`）。

- 如果 `i` 超出了范围，它会抛出一个 `std::out_of_range` 异常。

- ```cpp
  for (size_t i = 0; i < vec.size(); i++) {
  	std::cout << vec[i] << " ";
  }
  //改写为以下
  for (auto elem : vec) {
  	std::cout << elem << " ";
  }
  //对所有的容器都有用不只是vecotr
  ```

- ```cpp
  std::vector<MassiveType> vec { ... };
  for (auto elem : vec) ...
  //改写为以下
      
  for (const auto& elem : v)
  //避免了每次拷贝 直接 & 引用 原始对象 
  //const保证变量是只读的
  ```

- 一个有趣的问题:`vector` 是没有 `push_fornt` 这个操作的，我们如何实现这个操作呢 答案是`deque` 

- 如何实现 `deque` 呢:

  -  `vector` 的问题是她只有一块连续的内存
  - `deque` 采用了分段的数组结构 ,每个段存储一些连续元素,最终被组织成一个双端队列
  - `deque`使用了很多的子数组`chunks`构成，每个子数组`chunk`可以理解为是一个包含多个元素的"块"，按照一定顺序链接一起来形成`双端队列`

## Associative Containers(关联容器)

- 如 `std::map`、`std::set`

- `std::map`

  - ```cpp
    std::map<std::string, int> map {
    { "Chris", 2 },
    { "CS106L", 42 },
    { "Keith", 14 },
    { "Nick", 51 },
    { "Sean", 35 },
    };
    int sean = map["Sean"]; // 35
    map["Chris"] = 31;
    
    ```

  - ## Stanford 与 STL map 的比较


  | 操作                           | Stanford                 | std::map                 |
  | ------------------------------ | ------------------------ | ------------------------ |
  | 创建一个空的 map               | `Map<char, int> m;`      | `std::map<char, int> m;` |
  | 向 map 中添加键 `k` 和值 `v`   | `m.put(k, v);`           | `m[k] = v;`              |
  |                                |                          | `m.insert({k, v});`      |
  |                                |                          | `m[k] = v;`              |
  | 从 map 中移除key `k`           | `m.remove(k);`           | `m.erase(k);`            |
  | 检查key `k` 是否在 map 中      | `if (m.containsKey(k))`  | `if (m.count(k))`        |
  |                                | `if (m.contains(k))` (*) |                          |
  | 检查 map 是否为空              | `if (m.isEmpty())`       | `if (m.empty())`         |
  | 检索或覆盖与键 `k` 关联的值    | `int i = m[k];`          | `int i = m[k];`          |
  | （如果不存在则自动插入默认值） | `m[k] = i;`              | `m[k] = i;`              |

  - `std::map` 是一个关联容器，它存储的是键值对（`std::pair<const K,V>`）
  - `std::map` 通过红黑树（平衡二叉搜索树）来保证元素有序存储，并且在常见的操作
  - `std::map<K,V>` 需要K类型具有 `<`操作符，因为`std::map`通过BST(通常是红黑树)来储存元素`std::map` 需要比较键值 `K` 的大小关系

- `std::set`

  - ```cpp
    std::set<std::string> set { 
    "CS106L!", 
    "Keith", 
    "Sean", 
    "Nick", 
    "Chris"
    };
    ```

  - # Stanford vs. STL set

    | 操作                         | Stanford Set<char> | std::set<char>    |
    | ---------------------------- | ------------------ | ----------------- |
    | **创建一个空集合**           | Set<char> s;       | std::set<char> s; |
    | **向集合中添加元素 k**       | s.add(k);          | s.insert(k);      |
    | **从集合中删除元素 k**       | s.remove(k);       | s.erase(k);       |
    | **检查集合中是否包含元素 k** | if (s.contains(k)) | if (s.count(k));  |
    | **检查集合是否为空**         | if (s.isEmpty())   | if (s.empty());   |

  - `td::map` 是存储键值对（key-value pairs）的，而 `std::set` 只存储唯一的键.

  - 如果只关心key不关心value，`std::set`是简化版的`std:map`

- ## `std::unordered_map` and `std::unordered_set`

  - 你可以把 `unordered_map` 视为 `map` 的优化版

  - 它与 `map` 有相同的接口。

  - ```cpp
    std::unordered_map<std::string, int> map {
    { "Chris", 2 },
    { "Nick", 51 },
    { "Sean", 35 },
    };
    int sean = map["Sean"]; // 35
    map["Chris"] = 31;
    ```

  - `unordered_map` 使用哈希表，其元素没有顺序，查找、插入和删除的平均时间复杂度是 O(1)，因此通常更快，但不保证元素的顺序。

  - `std::unordered_map<K,V>` 需要K是可哈希的

  - `std::unordered_map<K,V>`和`std::unordered_set<K,V>`都是通过哈希函数和哈希冲突实现的

  - **unordered_map** 通过保持负载因子较小来实现非常快速的查找。

  - 如果负载因子变得过大（默认值为 1.0 以上），我们会进行重新哈希，以下是如何调整load_factor

  - ```cpp
    std::unordered_map<std::string, int> map;
    double lf = map.load_factor(); // 获取当前的负载因子
    map.max_load_factor(2.0); // 设置最大负载因子
    // 现在，直到负载因子超过 2.0，map 才会重新哈希
    
    ```

  - `unordered_map` 通常比 `map` 快
    • 然而，它使用更多的内存（organized vs. disorganized garage）
    • 如果你的键类型没有全序（`operator<`），使用 `unordered_map`！
    • 如果必须选择，`unordered_map` 是一个安全的选择

- 从上往下的每个元素的开销的空间依次增加

- | 数据结构             | 插入（前/后） | 插入（其他位置） | 删除（前/后） | 删除（其他位置） | 查找   | 访问第i个元素 |
  | -------------------- | ------------- | ---------------- | ------------- | ---------------- | ------ | ------------- |
  | `std::set`           | 慢            | 不适用           | 慢            | 不适用           | 快     | 不适用        |
  | `std::map`           | 慢            | 不适用           | 慢            | 不适用           | 快     | 不适用        |
  | `std::vector`        | 快            | 慢               | 快            | 慢               | 快     | 非常快        |
  | `std::deque`         | 快            | 慢               | 快            | 慢               | 快     | 快            |
  | `std::unordered_set` | 非常快        | 不适用           | 非常快        | 不适用           | 非常快 | 不适用        |
  | `std::unordered_map` | 非常快        | 不适用           | 非常快        | 不适用           | 非常快 | 不适用        |

  

![42592bae308166bd6543486b2da7bff6](D:\code\Courses\CS106L fall 24\Lecture5_ Containers\42592bae308166bd6543486b2da7bff6.png)

`std::array`  一个固定大小的数组

`std::list `一个双向链表

`std::multiset (+unordered)  `一个可以包含重复元素的集合

`std::multimap (+unordered)`可以为同一个键包含多个值