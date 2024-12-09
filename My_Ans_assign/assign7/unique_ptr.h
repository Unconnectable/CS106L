#pragma once

#include <cstddef>
#include <utility>

/**
 * @brief A smart pointer that owns an object and deletes it when it goes out of scope.
 * @tparam T The type of the object to manage.
 * @note This class is a simpler version of `std::unique_ptr`.
 */
template <typename T> 
class unique_ptr {
private:
  /* STUDENT TODO: What data must a unique_ptr keep track of? */
  T* ptr;
public:
  /**
   * @brief Constructs a new `unique_ptr` from the given pointer.
   * @param ptr The pointer to manage.
   * @note You should avoid using this constructor directly and instead use `make_unique()`.
   */
  unique_ptr(T* ptr) :ptr(ptr){
    /* STUDENT TODO: Implement the constructor */
    if(!ptr)
      throw std::runtime_error("Not implemented: unique_ptr(T* ptr)");
  }

  /**
   * @brief Constructs a new `unique_ptr` from `nullptr`.
   */
  unique_ptr(std::nullptr_t) :ptr(nullptr) {
    /* STUDENT TODO: Implement the nullptr constructor */
    if(ptr!=nullptr)
      throw std::runtime_error("Not implemented: unique_ptr(std::nullptr_t)");
  }

  /**
   * @brief Constructs an empty `unique_ptr`.
   * @note By default, a `unique_ptr` points to `nullptr`.
   */
  unique_ptr() : unique_ptr(nullptr) {}

  /**
   * @brief Dereferences a `unique_ptr` and returns a reference to the object.
   * @return A reference to the object.
   */
  T& operator*() {
    /* STUDENT TODO: Implement the dereference operator */
    return *ptr;
    //throw std::runtime_error("Not implemented: operator*()");
  }

  /**
   * @brief Dereferences a `unique_ptr` and returns a const reference to the object.
   * @return A const reference to the object.
   */
  const T& operator*() const {
    /* STUDENT TODO: Implement the dereference operator (const) */
    return *ptr;
    throw std::runtime_error("Not implemented: operator*() const");
  }

  /**
   * @brief Returns a pointer to the object managed by the `unique_ptr`.
   * @note This allows for accessing the members of the managed object through the `->` operator.
   * @return A pointer to the object.
   */
  T* operator->() {
    /* STUDENT TODO: Implement the arrow operator */
    return ptr;
    throw std::runtime_error("Not implemented: operator->()");
  }

  /**
   * @brief Returns a const pointer to the object managed by the `unique_ptr`.
   * @note This allows for accessing the members of the managed object through the `->` operator.
   * @return A const pointer to the object.
   */
  const T* operator->() const {
    /* STUDENT TODO: Implement the arrow operator */
    return ptr;
    throw std::runtime_error("Not implemented: operator->() const");
  }

  /**
   * @brief Returns whether or not the `unique_ptr` is non-null.
   * @note This allows us to use a `unique_ptr` inside an if-statement.
   * @return `true` if the `unique_ptr` is non-null, `false` otherwise.
   */
  operator bool() const {
    /* STUDENT TODO: Implement the boolean conversion operator */
    return ptr !=nullptr;
    throw std::runtime_error("Not implemented: operator bool() const");
  }

  /** STUDENT TODO: In the space below, do the following:
   * - Implement a destructor
   * - Delete the copy constructor
   * - Delete the copy assignment operator
   * - Implement the move constructor
   * - Implement the move assignment operator
   */
  ~unique_ptr(){
    delete ptr;
  } 
  unique_ptr(const unique_ptr& other) = delete;
  unique_ptr& operator=(const unique_ptr& other) = delete;

  unique_ptr(unique_ptr&& other){
    //unique_ptr<T> _ptr = std::move(ptr_other);
    //也就是说ptr_other的资源转移到了_ptr上
    //所以先转换资源 然后销毁不需要的ptr_other
    ptr = other.ptr;
    other.ptr = nullptr;
  }
  unique_ptr& operator=(unique_ptr&& other){
    //unique_ptr<int> other = std::make_unique<int>(10);  
    // other 拥有一个指向 10 的内存
    //unique_ptr<int> ptr_; 

    //这里假设=ptr_已经有资源 我们需要做的事情是吧other的资源转换到已经有(或者没有资源的)ptr上
    //因此 先delete ptr本来的资源 然后和move构造一样的事情 转移资源 销毁ohter的资源
    //ptr_ = std::move(a);  // 通过移动赋值将 a 的资源转移到 b
      if(this != &other){
        delete ptr;
      ptr = other.ptr;
      other.ptr = nullptr;
      }
    return *this;
  }
};

/**
 * @brief Creates a new unique_ptr for a type with the given arguments.
 * @example auto ptr = make_unique<int>(5);
 * @tparam T The type to create a unique_ptr for.
 * @tparam Args The types of the arguments to pass to the constructor of T.
 * @param args The arguments to pass to the constructor of T.
 */
template <typename T, typename... Args> unique_ptr<T> make_unique(Args&&... args) {
  return unique_ptr<T>(new T(std::forward<Args>(args)...));
}