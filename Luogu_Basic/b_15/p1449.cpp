#include <cmath>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define SIZE 100

using namespace std;

template <typename T> class stack {
private:
  T *data;
  int capacity;
  int size;

public:
  stack(size_t c = SIZE, int s = 0);
  ~stack();
  void push(T in);
  T peek();
  T pop();
  void resize();
};

template <typename T> stack<T>::stack(size_t c, int s) {
  this->data = new T[c];
  this->capacity = c;
  this->size = s;
}

template <typename T> stack<T>::~stack() { delete[] data; }

template <typename T> void stack<T>::push(T in) {
  if (size + 1 == capacity)
    resize();
  data[size] = in;
  size++;
  return;
}

template <typename T> T stack<T>::peek() { return data[size - 1]; }

template <typename T> T stack<T>::pop() {
  size--;
  return data[size];
}

template <typename T> void stack<T>::resize() {
  this->capacity = this->capacity == 0 ? 1 : (this->capacity) * 2;
  T *newdata = new T[capacity];
  for (int i = 0; i < size; i++) {
    newdata[i] = data[i];
  }
  delete[] data;
  this->data = newdata;
}

int main() {
  string a;
  stack<int> nums;
  getline(cin, a);
  int i = 0;
  int p = 0;
  int q = 0;
  while (a[i] != '@') {
    if (a[i] == '.') {
      while (p < i) {
        q += (a[p]-'0') * pow(10, (i - p-1));
        p++;
      }
      i++;
      p = i;
      nums.push(q);
      q = 0;
    }
    else if (a[i] == '+' || a[i] == '-' || a[i] == '/' || a[i] == '*')
    {
        int opa, opb;
        opa = nums.pop();
        opb = nums.pop();
        switch (a[i])
        {
        case '+':
            nums.push(opb + opa);
            break;
        case '-':
            nums.push(opb - opa);
            break;
        case '*':
            nums.push(opb * opa);
            break;
        case '/':
            nums.push(opb / opa);
            break;
        }
        i++;
        p = i;
    }
    else
        i++;
  }
  cout << nums.peek() << endl;
}