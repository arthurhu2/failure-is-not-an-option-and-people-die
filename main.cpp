// @author Graham Hemingway @copyright 2024 - All rights reserved
#include "strong_stack.h"
#include <iostream>

int main() {
  /* create multiple stacks */
  Stack<> stack1(1);

  std::cout << stack1.push(10) << std::endl;
  std::cout << stack1.push(100) << std::endl;
  std::cout << stack1.push(1000) << std::endl;
  std::cout << stack1.push(9) << std::endl;
  std::cout << stack1.push(14) << std::endl;
  std::cout << stack1.push(12) << std::endl;

  Stack<> stack2(5);
  stack2.push(1);
  stack2.push(2);
  stack2.push(3);
  stack2.push(4);
  stack2.push(5);
  stack2.push(6);
  std::cout << stack2 << std::endl;

  Stack<> stack3(stack2);
  std::cout << stack3 << std::endl;

  stack3 = stack1;
  std::cout << stack3 << std::endl;
  int value;
  stack3.pop(value);
  std::cout << value << std::endl;
  stack3.top(value);
  std::cout << value << std::endl;

  stack2.reverse();
  std::cout << stack2 << std::endl;

  auto evens = stack2.keepOddsReturnEvens();
  std::cout << stack2 << std::endl;
  std::cout << evens << std::endl;

  return 0;
}
