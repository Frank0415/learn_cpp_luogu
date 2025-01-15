#include <iostream>
#include <vector>

#define MAX 202

using namespace std;

class queue {
private:
  int *arr;
  int capacity;
  int front;
  int rear;
  int count;

public:
  queue(int size = MAX);
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

int queue::peek() { return *(arr + front); }

int queue::pop() {
  if (!isempty()) {
    int item = *(arr + front);
    front = (front + 1) % capacity;
    count--;
    return item;
  } else
    cout << "Empty!" << endl;
  return -1;
}

bool queue::isfull() { return (count == capacity); }

bool queue::isempty() { return (count == 0); }

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  vector<int> k(n + 1);
  vector<int> l(n + 1, -1);

  for (int i = 1; i <= n; i++)
    cin >> k[i];

  l[a] = 0;
  queue q;
  q.push(a);

  while (!q.isempty() && l[b] == -1) {
    int pos = q.peek();
    if (pos + k[pos] > 0 && pos + k[pos] <= n && l[pos + k[pos]] == -1) {
      q.push(pos + k[pos]);
      l[pos + k[pos]] = l[pos] + 1;
    }
    if (pos - k[pos] > 0 && pos - k[pos] <= n && l[pos - k[pos]] == -1) {
      q.push(pos - k[pos]);
      l[pos - k[pos]] = l[pos] + 1;
    }
    q.pop();
  }
  cout << l[b] << '\n';
}