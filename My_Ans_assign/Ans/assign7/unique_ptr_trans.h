#pragma once

#include <cstddef>
#include <utility>

/**
 * @brief 一个智能指针，拥有一个对象，并在作用域结束时删除该对象。
 * @tparam T 要管理的对象的类型。
 * @note 该类是 `std::unique_ptr` 的简化版本。
 */
template <typename T> class unique_ptr {
private:
  /* STUDENT TODO: unique_ptr 需要跟踪哪些数据？ */

public:
  /**
   * @brief 从给定的指针构造一个新的 `unique_ptr`。
   * @param ptr 要管理的指针。
   * @note 你应该避免直接使用此构造函数，而应使用 `make_unique()`。
   */
  unique_ptr(T* ptr) {
    /* STUDENT TODO: 实现构造函数 */
    throw std::runtime_error("Not implemented: unique_ptr(T* ptr)");
  }

  /**
   * @brief 从 `nullptr` 构造一个新的 `unique_ptr`。
   */
  unique_ptr(std::nullptr_t) {
    /* STUDENT TODO: 实现 nullptr 构造函数 */
    throw std::runtime_error("Not implemented: unique_ptr(std::nullptr_t)");
  }

  /**
   * @brief 构造一个空的 `unique_ptr`。
   * @note 默认情况下，`unique_ptr` 指向 `nullptr`。
   */
  unique_ptr() : unique_ptr(nullptr) {}

  /**
   * @brief 解引用 `unique_ptr` 并返回对象的引用。
   * @return 对象的引用。
   */
  T& operator*() {
    /* STUDENT TODO: 实现解引用操作符 */
    throw std::runtime_error("Not implemented: operator*()");
  }

  /**
   * @brief 解引用 `unique_ptr` 并返回对象的常量引用。
   * @return 对象的常量引用。
   */
  const T& operator*() const {
    /* STUDENT TODO: 实现解引用操作符（常量） */
    throw std::runtime_error("Not implemented: operator*() const");
  }

  /**
   * @brief 返回 `unique_ptr` 所管理的对象的指针。
   * @note 这使得通过 `->` 操作符访问管理对象的成员成为可能。
   * @return 对象的指针。
   */
  T* operator->() {
    /* STUDENT TODO: 实现箭头操作符 */
    throw std::runtime_error("Not implemented: operator->()");
  }

  /**
   * @brief 返回 `unique_ptr` 所管理的对象的常量指针。
   * @note 这使得通过 `->` 操作符访问管理对象的成员成为可能。
   * @return 对象的常量指针。
   */
  const T* operator->() const {
    /* STUDENT TODO: 实现箭头操作符 */
    throw std::runtime_error("Not implemented: operator->() const");
  }

  /**
   * @brief 返回 `unique_ptr` 是否非空。
   * @note 这使得可以在 if 语句中使用 `unique_ptr`。
   * @return 如果 `unique_ptr` 非空则返回 `true`，否则返回 `false`。
   */
  operator bool() const {
    /* STUDENT TODO: 实现布尔转换操作符 */
    throw std::runtime_error("Not implemented: operator bool() const");
  }

  /** STUDENT TODO: 在下面的空间中完成以下任务：
   * - 实现析构函数
   * - 删除拷贝构造函数
   * - 删除拷贝赋值操作符
   * - 实现移动构造函数
   * - 实现移动赋值操作符
   */
};

/**
 * @brief 为给定类型和参数创建一个新的 `unique_ptr`。
 * @example auto ptr = make_unique<int>(5);
 * @tparam T 要为其创建 `unique_ptr` 的类型。
 * @tparam Args 传递给 T 构造函数的参数类型。
 * @param args 传递给 T 构造函数的参数。
 */
template <typename T, typename... Args> unique_ptr<T> make_unique(Args&&... args) {
  return unique_ptr<T>(new T(std::forward<Args>(args)...));
}
