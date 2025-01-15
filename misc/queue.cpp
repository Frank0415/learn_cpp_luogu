#include <iostream>

using namespace std;

template <typename T>
class queue {
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

template <typename T>
queue<T>::queue(int size) {
    arr = new T[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}

template <typename T>
queue<T>::~queue() { delete[] arr; }

template <typename T>
void queue<T>::push(T a) {
    if (!isfull()) {
        rear = (rear + 1) % capacity;
        arr[rear] = a;
        count++;
        return;
    } else
        cout << "Full !" << endl;
    return;
}

template <typename T>
T queue<T>::pop() {
    if (!isempty()) {
        T item = *(arr + front);
        front = (front + 1) % capacity;
        count--;
        return item;
    } else
        cout << "Empty!" << endl;
    return T(); // Return default value of T
}

template <typename T>
T queue<T>::peek() {
    if (!isempty()) {
        return arr[front];
    } else
        cout << "Empty!" << endl;
    return T(); // Return default value of T
}

template <typename T>
bool queue<T>::isfull() { return (count == capacity); }

template <typename T>
bool queue<T>::isempty() { return (count == 0); }
