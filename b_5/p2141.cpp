#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

void sssort(int num[], int size) {
  for (int i = 0; i < size; i++) {
    int min = i;
    bool swap = false;
    for (int j = i; j < size; j++) {
      if (num[min] > num[j]) {
        min = j;
        swap = true;
      }
    }
    if (swap = true) {
      int temp = num[i];
      num[i] = num[min];
      num[min] = temp;
    }
  }
}

int main() {
  int count, num[101], output [101]={0};
  cin >> count;
  for (int i = 0; i < count; i++) {
    cin >> num[i];
  }
  sssort(num, count);
  int max = num[count - 1];
  for (int i = 0; i < count; i++) {
    for (int j = i + 1; j < count; j++) {
      int sum = num[i] + num[j];
      if (sum > max) {
        break;
      }

      for (int k = j + 1; k < count; k++) {
          if (num[k] == sum)
          {
              output[k] = 1;
          }
      }
    }
  }
  int out = 0;
  for (int i = 0; i < count; i++)
  {
      out += output[i];
  }

  cout << out << endl;
}