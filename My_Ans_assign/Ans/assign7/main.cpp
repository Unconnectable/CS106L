/*
 * CS106L Assignment 7: Unique Pointer
 * Created by Jacob Roberts-Baca.
 */

#include <functional>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

#include "unique_ptr.h"

/**
 * @brief A singly-linked list node that deallocates itself automatically
 * by using a `unique_ptr` to manage the pointer to the next node.
 * @tparam T The type of the value stored in the node.
 *
 * @note No modifications are necessary to this struct in order to complete the assignment!
 */
template <typename T> struct ListNode {

  /** @brief The value stored inside this node. */
  T value;

  /** @brief The smart pointer to the next node. May be null. */
  unique_ptr<ListNode<T>> next;

  /**
   * @brief Constructs a single element linked list, setting `next` to `nullptr`.
   * @param value The value to store in the node.
   */
  ListNode(T value) : value(value), next(nullptr) {
    /* This line is just here for logging purposes so we can see when the
     * constructor runs!
     */
    std::cout << "Constructing node with value '" << value << "'\n";
  }

  ~ListNode() {
    /* This line is just here for logging purposes so we can see when the
     * destructor runs!
     */
    std::cout << "Destructing node with value '" << value << "'\n";
  }
};

/**
 * @brief Creates a singly-linked list from a vector of values.
 * @param values The values to store in the list.
 * @return A `unique_ptr` to the head of the list.
 */


//auto node = std::make_unique<ListNode<T>>(value);

template <typename T> 
unique_ptr<ListNode<T>> create_list(const std::vector<T>& values) {
  /* STUDENT TODO: Implement this method */
  if (values.empty())
    return nullptr;

  unique_ptr<ListNode<T>> head = nullptr;

  std::vector<T> values_copy = values;
  std::reverse(values_copy.begin(), values_copy.end());
  for (auto value : values_copy)
  {
    //unique_ptr 期望的是一个指向动态分配对象的指针。
    /*
    1.不是动态分配的内存： &value 返回的是栈上已有对象的地址，而不是堆上分配的对象指针。unique_ptr 只能管理堆上动态分配的对象，而栈上分配的对象并不符合 unique_ptr 的内存管理模型。unique_ptr 无法接管栈上对象的生命周期，试图这样做会导致所有权管理上的混乱。

    2.引用的生命周期问题： &value 只是一个指向栈上或其他位置对象的引用，而不是一个独立的内存区域。如果你用 unique_ptr 管理 &value，当 unique_ptr 被销毁时，它会尝试删除这个对象（调用 delete），但这会引发错误，因为栈上的对象并不需要被删除。
    */
    //auto node = unique_ptr<ListNode<T>>(value);

    //auto node = unique_ptr<ListNode<T>>(new ListNode<T>{value});
    //列表初始化
    //auto node = unique_ptr<ListNode<T>>(new ListNode<T>(value));  
    //
    
    //不过unique_ptr.h文件已经实现了 make_unique<T> 为什么不使用呢
    //这里有个很傻逼的坑 make_unique<T>的T是 ListNode<T>
    //写成 make_unique<ListNode>(value) 会错...我瞎了半天
    auto node = make_unique<ListNode<T>>(value);
    node->next = std::move(head);
    head = std::move(node);
  }
  return head;
  //throw std::runtime_error("Not implemented: createList");
}

/**
 * @brief Applies a function to each element in the linked list.
 * @tparam T The type of the value stored in the list.
 * @tparam Func The type of the function to apply.
 * @param head The head of the linked list.
 * @paragraph func The function to apply to each element.
 */
template <typename T, typename Func>
void map_list(const unique_ptr<ListNode<T>>& head, const Func& func) {
  if (!head)
    return;
  func(head->value);
  map_list(head->next, func);
}

/**
 * @brief An example of using a singly-linked list with `unique_ptr`.
 */
void linked_list_example() {
  std::vector<std::string> names{"Jacob", "Fabio", "Keith", "Chris", "Sean"};
  auto head = create_list(names);
  map_list(head, [](const std::string& name) { std::cout << name << "\n"; });
}

#include "autograder/utils.hpp"