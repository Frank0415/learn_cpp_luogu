/*#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class point {
public:
  double x, y;
  point(double x = 0, double y = 0);
  point operator+(const point &other);
  point operator-(const point &other);
  double dist(const point &other) const;
};

point::point(double xin, double yin) {
  this->x = xin;
  this->y = yin;
}

point point::operator+(const point &other) {
  return point(x + other.x, y + other.y);
}
point point::operator-(const point &other) {
  return point(x - other.x, y - other.y);
}

double point::dist(const point &other) const {
  return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
}

template <typename T> class queue {
private:
  T *arr;
  int capacity;
  int front;
  int rear;
  int count;

public:
  queue(int size);
  ~queue();
  void push(T a);
  T pop();
  T peek();
  bool isempty();
  bool isfull();
};

template <typename T> queue<T>::queue(int size) {
  arr = new T[size];
  capacity = size;
  front = 0;
  rear = -1;
  count = 0;
}

template <typename T> queue<T>::~queue() { delete[] arr; }

template <typename T> void queue<T>::push(T a) {
  if (!isfull()) {
    rear = (rear + 1) % capacity;
    arr[rear] = a;
    count++;
    return;
  } else
    cout << "Full !" << endl;
  return;
}

template <typename T> T queue<T>::pop() {
  if (!isempty()) {
    T item = *(arr + front);
    front = (front + 1) % capacity;
    count--;
    return item;
  } else
    cout << "Empty!" << endl;
  return T(); // Return default value of T
}

template <typename T> T queue<T>::peek() {
  if (!isempty()) {
    return arr[front];
  } else
    cout << "Empty!" << endl;
  return T(); // Return default value of T
}

template <typename T> bool queue<T>::isfull() { return (count == capacity); }

template <typename T> bool queue<T>::isempty() { return (count == 0); }

void dfs(double &maxx, vector<bool> &pb, const vector<point> &p, int count,
         double sum, point prev, int co) {
  if (co == 0) {
    maxx = min(maxx, sum);
    return;
  }
  if (sum > maxx)
    return;

  for (int i = 1; i <= count; i++) {
    if (pb[i] != true) {
      pb[i] = true;
      dfs(maxx, pb, p, count, sum + p[i].dist(prev), p[i], co - 1);
      pb[i] = false;
    }
  }
}

int main() {
  int size;
  cin >> size;
  vector<point> p(size + 1);
  p[0] = point(0, 0);
  for (int i = 1; i <= size; i++) {
    cin >> p[i].x >> p[i].y;
  }
  double maxx = 1e11;
  vector<bool> pb(size + 1, false);
  dfs(maxx, pb, p, size, 0, p[0], size);
  printf("%.2f\n", maxx);
}*/

#include <cmath>
#include <iostream>
#include <vector>
#include<limits>

using namespace std;

class point {
public:
    double x, y;
    point(double x = 0, double y = 0);
    point operator+(const point &other);
    point operator-(const point &other);
    double dist(const point &other) const;
};

point::point(double xin, double yin) {
    this->x = xin;
    this->y = yin;
}

point point::operator+(const point &other) {
    return point(x + other.x, y + other.y);
}
point point::operator-(const point &other) {
    return point(x - other.x, y - other.y);
}

double point::dist(const point &other) const {
    return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
}

template <typename T> class queue {
private:
    T *arr;
    int capacity;
    int front;
    int rear;
    int count;

public:
    queue(int size);
    ~queue();
    void push(T a);
    T pop();
    T peek();
    bool isempty();
    bool isfull();
};

template <typename T> queue<T>::queue(int size) {
    arr = new T[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}

template <typename T> queue<T>::~queue() { delete[] arr; }

template <typename T> void queue<T>::push(T a) {
    if (!isfull()) {
        rear = (rear + 1) % capacity;
        arr[rear] = a;
        count++;
        return;
    } else
        cout << "Full !" << endl;
    return;
}

template <typename T> T queue<T>::pop() {
    if (!isempty()) {
        T item = *(arr + front);
        front = (front + 1) % capacity;
        count--;
        return item;
    } else
        cout << "Empty!" << endl;
    return T(); // Return default value of T
}

template <typename T> T queue<T>::peek() {
    if (!isempty()) {
        return arr[front];
    } else
        cout << "Empty!" << endl;
    return T(); // Return default value of T
}

template <typename T> bool queue<T>::isfull() { return (count == capacity); }

template <typename T> bool queue<T>::isempty() { return (count == 0); }

void dfs(double &maxx, vector<bool> &visited, const vector<point> &p, int count, double sum, int last, int visitedCount) {
    if (visitedCount == count) { // All points visited
        maxx = min(maxx, sum);
        return;
    }

    for (int i = 1; i <= count; i++) {
        if (!visited[i]) { // If point `i` is not visited
            visited[i] = true;
            dfs(maxx, visited, p, count, sum + p[last].dist(p[i]), i, visitedCount + 1);
            visited[i] = false;
        }
    }
}

int main() {
    int size;
    cin >> size;
    vector<point> p(size + 1);
    p[0] = point(0, 0);
    for (int i = 1; i <= size; i++) {
        cin >> p[i].x >> p[i].y;
    }

    double maxx = 1e100;
    vector<bool> visited(size + 1, false);
    visited[0] = true;
    dfs(maxx, visited, p, size, 0, 0, 0);

    printf("%.2f\n", maxx);
}
