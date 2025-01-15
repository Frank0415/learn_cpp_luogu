#include <iostream>

using namespace std;

class queue {
private:
  int *arr;
  int capacity;
  int front;
  int rear;
  int count;

public:
  queue(int size);
  ~queue();
  void push(int a);
  int pop();
  int peek();
  bool isempty();
  bool isfull();
};

queue::queue(int size) {
  arr = new int[size];
  capacity = size;
  front = 0;
  rear = -1;
  count = 0;
}

queue::~queue() { delete[] arr; }

void queue::push(int a) {
  if (!isfull()) {
    rear = (rear + 1) % capacity;
    arr[rear] = a;
    count++;
    return;
  } else
    cout << "Full !" << endl;
  return;
}

int queue::pop() {
  if (!isempty()) {
    int item = *(arr + front);
    front = (front + 1) % capacity;
    count--;
    return item;
  } else
    cout << "Empty!" << endl;
  return;
}

bool queue::isfull() { return (count == capacity); }

bool queue::isempty() { return (count == 0); }
