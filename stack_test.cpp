#include <iostream>
#include "stack.h"

int main() {
  Stack<int> stack;

  stack.push(10);
  stack.push(20);
  stack.push(30);

  std::cout << "Size of stack: " << stack.size() << std::endl;

  std::cout << "Is stack empty? " << (stack.empty() ? "Yes" : "No") << std::endl;

  std::cout << "Top element: " << stack.top() << std::endl;

  stack.pop();
  stack.pop();

  std::cout << "Size of stack after popping: " << stack.size()<< std::endl;

  if (!stack.empty()) {
    std::cout << "Top element of stack after popping: " << stack.top() << std::endl;
  } else {
    std::cout << "Stack is empty after popping " << std::endl;
  }

  try {
    stack.pop();
  } catch (const std::underflow_error& e) {
    std::cerr << "caught exception: "<<e.what() << std::endl;
  }
  return 0;
}