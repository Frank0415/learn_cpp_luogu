#include <iostream>

using namespace std;

namespace sort {
void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
} // namespace sort

namespace bubblesort { // Const. O(n^2) complexity
void sort(int *list, int len) {
  for (int i = 0; i < len; i++) {
    int *smallest = list + i;
    bool changed = false;
    for (int j = i + 1; j < len; j++) {
      if (*smallest > *(list + j)) {
        smallest = list + j;
        changed = true;
      }
    }
    if (changed)
      sort::swap(smallest, list + i);
  }
  return;
}
} // namespace bubblesort

namespace quicksort { // Best&avg O(nlogn), worst O(n^2)
void sort(int *list, int len) {
  if (len <= 1) // trivial
  {
    return;
  }
  int *pivot = list + len - 1;
  int p = 0;
  for (int i = 0; i < len - 1; i++) {
    if (*(list + i) <= *pivot) {
      sort::swap(list + p, list + i);
      p++;
    }
  }
  sort::swap(list + p, pivot); // list+p is the first number bigger than pivot
  quicksort::sort(list, p);
  quicksort::sort(list + p + 1, len - p - 1);
  return;
}

} // namespace quicksort

namespace mymergesort { // Const. O(nlogn) complexity
void merge(int *list, int len1, int len2) {
  int *leftsize = new int[len1];
  int *rightsize = new int[len2];
  for (int i = 0; i < len1; i++) {
    leftsize[i] = list[i];
  }
  for (int i = 0; i < len2; i++) {
    rightsize[i] = list[i + len1];
  }

  int i = 0, j = 0, k = 0;

  while (i < len1 && j < len2) {
    if (leftsize[i] < rightsize[j]) {
      list[k] = leftsize[i];
      i++;
      k++;
    } else {
      list[k] = rightsize[j];
      j++;
      k++;
    }
  }
  while (i < len1) {
    list[k] = leftsize[i];
    k++;
    i++;
  }
  while (j < len2) {
    list[k] = rightsize[j];
    k++;
    j++;
  }
  delete[] leftsize;
  delete[] rightsize;
  return;
}

void sort(int *list, int len) {
  if (len <= 1) {
    return;
  }
  mymergesort::sort(list, len / 2 );
  mymergesort::sort(list + len / 2 , len - len / 2);
  mymergesort::merge(list, len / 2, len - len / 2);
  return;
}
} // namespace mymergesort

void print(int *list, size_t len) {
  for (size_t i = 0; i < len; i++)
    cout << *(list + i) << " ";
  cout << endl;
}

int main() {
  int list[] = {2, 45, 2, 4, 12, 5, 32, 24};
  auto len = sizeof(list) / sizeof(int);
  mymergesort::sort(list, len);
  print(list, len);
  return 0;
}