#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <utility>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

  void bubbleUp(size_t index);

  void bubbleDown(size_t index);

private:
  /// Add whatever helper functions and data members you need below
  size_t m_;
  PComparator comparator_;
  std::vector<T> data;


};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c):m_(m), comparator_(c) {}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap() {}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item) {
  data.push_back(item);
  bubbleUp(data.size() - 1);
}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const {
  return data.empty();
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const {
  return data.size();
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data[0];
}


// // We will start pop() for you to handle the case of 
// // calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");
  }
    data[0] = data.back();
    data.pop_back();
    bubbleDown(0);
}


template <typename T, typename PComparator>
void Heap<T, PComparator>::bubbleUp(size_t index) {
  while (index > 0) {
    size_t parent = (index - 1)/m_;
    if (comparator_(data[index], data[parent])) {
      std::swap(data[index], data[parent]);
      index = parent;
    } else {
      break;
    }
  }
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::bubbleDown(size_t index) {
  while (true) {
    size_t largest = index;
    for(size_t i = 1; i <= m_; ++i) {
      size_t child = m_ * index + i;
      if (child < data.size() && comparator_(data[child], data[largest])) {
        largest = child;
      }
    }
    if (largest != index) {
      std::swap(data[index], data[largest]);
      index = largest;
    } else {
      break;
    }
  }
}


#endif

