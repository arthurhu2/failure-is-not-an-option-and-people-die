// @author Graham Hemingway @copyright 2024 - All rights reserved
#ifndef STRONGSTACK_H
#define STRONGSTACK_H

#include <cstdint>
#include <iostream>
#include <memory>

template <typename T = int> class Stack {
public:
  /**
   * Primary constructor
   * @param count
   */
  explicit Stack(uint32_t count = 10)
      : stackTop(0), size(count), stack(new T[size]) {}

  /**
   * Copy constructor
   * @param rhs
   */
  Stack(const Stack &rhs)
      : stackTop(rhs.stackTop), size(rhs.size), stack(new T[rhs.size]) {
    for (uint32_t i = 0; i < rhs.stackTop; ++i) {
      stack[i] = rhs.stack[i];
    }
  }

  // Default destructor
  ~Stack() = default;

  /**
   * Assignment operator
   * @param rhs
   * @return
   */
  Stack &operator=(const Stack &rhs) {
    if (this != &rhs) {
      Stack<T> tmp(rhs);
      std::swap(size, tmp.size);
      std::swap(stackTop, tmp.stackTop);
      std::swap(stack, tmp.stack);
    }
    return *this;
  }

  /**
   * Push a value onto the stack - grow if necessary
   * @param item
   * @return - capacity of the stack
   */
  uint32_t push(const T &item) {
    if (isFull()) {
      uint32_t newSize = size * 2;
      std::unique_ptr<T[]> newBuffer = std::make_unique<T[]>(newSize);
      for (uint32_t i = 0; i < stackTop; ++i)
        newBuffer[i] = stack[i];
      newBuffer[stackTop] = item;
      std::swap(stack, newBuffer);
      size = newSize;
    } else {
      stack[stackTop] = item;
    }
    ++stackTop;
    return size;
  }

  void pop(T &item) {
    if (isEmpty())
      throw std::underflow_error("Stack is empty");
    item = stack[--stackTop];
  }

  uint32_t top(T &item) {
    item = stack[stackTop - 1];
    return stackTop;
  }

  /**
   * Check if stack is empty
   * @return true if empty - false if not
   */
  bool isEmpty() const noexcept { return stackTop == 0; }

  /**
   * Check if stack is at capacity
   * @return true if completely full - false if not
   */
  bool isFull() const noexcept { return stackTop == size; }

  /**
   * In-place reversal of the order within the stack
   * - This is very not exception safe - can you make it so?
   * @return stack itself
   */
  Stack &reverse() {
    // Swap (i) with (stackTop - i - 1)
//    const auto limit = stackTop / 2;
//    for (uint32_t i = 0; i < limit; ++i) {
//      std::swap(stack[i], stack[stackTop - i - 1]);
//    }
    auto newBuffer = std::makeunique<T[]>(size);
    for (auto i = 0; i < stackTop; ++i) {
      newBuffer[i] = stack[stackTop - 1 - i];
    }
    std::swap(newBuffer, stack);
    return *this;
  }

  /**
   * Keep all odd indexed values in this stack,
   * return a new stack with the even-indexed value
   * @return stack with even-indexed values
   */
  Stack keepOddsReturnEvens() { return Stack<T>(); }

  // Friendship for printing
  template <typename R>
  friend std::ostream &operator<<(std::ostream &, const Stack<R> &rhs) noexcept;

private:
  uint32_t stackTop, size;
  std::unique_ptr<T[]> stack;
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const Stack<T> &rhs) noexcept {
  os << "[ ";
  for (uint32_t i = 0; i < rhs.stackTop; ++i)
    os << rhs.stack[i] << " ";
  os << "]";
  return os;
}

#endif
