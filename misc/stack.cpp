#include <iostream>

using namespace std;

template <typename T> class stack {
private:
  T *data;
  size_t capacity;
  int size;

public:
  stack();
  ~stack();
  void push(T in);
  T pop();
  T peek();
};
template <typename T> stack<T>::stack() : data(nullptr), capacity(0), size(0) {}

template <typename T> stack<T>::~stack() { delete[] data; }

template <typename T> void stack<T>::push(T in) {
  if (size == capacity) {
    capacity == 0 ? 1 : capacity *= 2;
    T *newData = new T[capacity];
    for (int i = 0; i < size; ++i) {
      newData[i] = data[i];
    }
    delete[] data;
    data = newData;
  }
  data[size++] = in;
}

template <typename T> T stack<T>::pop() {
  if (size == 0) {
    throw out_of_range("Stack is empty");
  }
  return data[--size];
}

template <typename T> T stack<T>::peek() {
  if (size == 0) {
    throw out_of_range("Stack is empty");
  }
  return data[size - 1];
}