#include <iostream>
#include "heap.h"
#include <string>

int main() {
  // std::cout << "Testing min heap with integers:\n";
  // Heap<int> minHeap;
  // minHeap.push(5);
  // minHeap.push(10);
  // minHeap.push(3);
  // minHeap.push(8);
  // minHeap.push(1);

  // std::cout << "Top element of the min heap: " << minHeap.top() << std::endl;

  // std::cout << "Popping elements from the min heap: ";
  // while (!minHeap.empty()){
  //   std::cout << minHeap.top() << " ";
  //   minHeap.pop();
  // }
  // std::cout << std::endl;


  auto stringcomparator = [](const std::string& lhs, const std::string& rhs) {
    return lhs > rhs;
  };
  Heap<std::string, decltype(stringcomparator)> maxHeap(2, stringcomparator);


  std::cout << "\nTesting max heap with strings:\n";
  maxHeap.push("apple"); 
  maxHeap.push("banana"); 
  maxHeap.push("orange"); 
  maxHeap.push("grape"); 
  maxHeap.push("pear"); 

  std::cout << "Top element of the max heap: " << maxHeap.top() << std::endl;

  while (!maxHeap.empty()) {
    std::cout << maxHeap.top() << " ";
    maxHeap.pop();
  }
  std::cout << std::endl;

return 0;
}


// int main() {
//   Heap<int> minHeap;

//   minHeap.push(5);
//   minHeap.push(3);
//   minHeap.push(8);
//   minHeap.push(2);
//   minHeap.push(7);

//   std::cout << "Elements in the heap after push operations: " << std::endl;
//   while (!minHeap.empty()) {
//     std::cout << minHeap.top() << " ";
//     minHeap.pop();
//   }
//   std::cout <<std::endl;
//   return 0;
// }