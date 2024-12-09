/*
 * CS106L Assignment 7: Unique Pointer
 * 作者: Jacob Roberts-Baca.
 */

#include <functional>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

#include "unique_ptr.h"

/**
 * @brief 一个单链表节点，使用 `unique_ptr` 管理指向下一个节点的指针，自动释放内存。
 * @tparam T 节点中存储的值的类型。
 *
 * @note 为完成此作业，不需要对该结构体进行任何修改！
 */
template <typename T> struct ListNode {

  /** @brief 存储在该节点中的值。 */
  T value;

  /** @brief 指向下一个节点的智能指针。可能为 null。 */
  unique_ptr<ListNode<T>> next;

  /**
   * @brief 构造一个单元素链表，将 `next` 设置为 `nullptr`。
   * @param value 要存储在节点中的值。
   */
  ListNode(T value) : value(value), next(nullptr) {
    /* 该语句仅用于记录日志，方便查看构造函数的运行情况！ */
    std::cout << "Constructing node with value '" << value << "'\n";
  }

  ~ListNode() {
    /* 该语句仅用于记录日志，方便查看析构函数的运行情况！ */
    std::cout << "Destructing node with value '" << value << "'\n";
  }
};

/**
 * @brief 根据一组值创建一个单链表。
 * @param values 要存储在链表中的值。
 * @return 一个指向链表头部的 `unique_ptr`。
 */
template <typename T> 
  unique_ptr<ListNode<T>> create_list(const std::vector<T>& values) {
  /* STUDENT TODO: 实现此方法 */
  throw std::runtime_error("Not implemented: createList");
}

/**
 * @brief 对链表中的每个元素应用一个函数。
 * @tparam T 链表中存储的值的类型。
 * @tparam Func 要应用的函数类型。
 * @param head 链表的头部。
 * @param func 要应用到每个元素的函数。
 */
template <typename T, typename Func>
void map_list(const unique_ptr<ListNode<T>>& head, const Func& func) {
  if (!head)
    return;
  func(head->value);
  map_list(head->next, func);
}

void linked_list_example() {
  std::vector<std::string> names{"Jacob", "Fabio", "Keith", "Chris", "Sean"};
  auto head = create_list(names);
  map_list(head, [](const std::string& name) { std::cout << name << "\n"; });
}


#include "autograder/utils.hpp"