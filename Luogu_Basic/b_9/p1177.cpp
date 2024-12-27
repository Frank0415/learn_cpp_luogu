#include <iostream>

using namespace std;

void sort(int *start, int *end);
void swap(int *a, int *b);
void mergesort(int *start, int *end);
void merge(int *start, int *mid, int *end);

int main() {
  int size=0;
  cin >> size;
  int list[size + 1];
  for (int i = 0; i < size; i++) {
    cin >> list[i];
  }
  mergesort(list, list + size - 1);
  for (int i = 0; i < size - 1; i++) {
    cout << list[i] << " ";
  }
  cout << list[size - 1] << endl;
  return 0;
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void sort(int *start, int *end) {
  if (start >= end) {
    return;
  }
  int size = end - start + 1;
  int p1 = -1;
  for (int i = 0; i < size - 1; i++) {
    if (*(start + i) < *end) {
      p1++;
      swap(start + p1, start + i);
    }
  }
  swap(end, start + p1 + 1);
  sort(start + p1 + 2, end);
  sort(start, start + p1);
} // best& median case nlogn, but data in the problem will get n^2 complexity

void mergesort(int *start, int *end) {
  if (start < end) {
    int *mid = start + (end - start) / 2;
    mergesort(start, mid);
    mergesort(mid + 1, end);
    merge(start, mid, end);
  }
}//constant nlogn, but space optimization?

void merge(int *start, int *mid, int *end) {
  int leftSize = mid - start + 1;
  int rightSize = end - mid;
  int left[leftSize], right[rightSize];

  for (int i = 0; i < leftSize; i++)
    left[i] = start[i];
  for (int i = 0; i < rightSize; i++)
    right[i] = mid[i + 1];

  int i = 0, j = 0, k = 0;
  while (i < leftSize && j < rightSize) {
    if (left[i] <= right[j]) {
      start[k] = left[i];
      i++;
    } else {
      start[k] = right[j];
      j++;
    }
    k++;
  }

  while (i < leftSize) {
    start[k] = left[i];
    i++;
    k++;
  }

  while (j < rightSize) {
    start[k] = right[j];
    j++;
    k++;
  }
}
