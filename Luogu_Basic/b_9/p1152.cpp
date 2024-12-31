#include <cstring>
#include <iostream>

using namespace std;

int main() {
  int count, a, b;
  cin >> count;
  a = 0;
  b = 0;
  int *c = new int[count];
  bool *d = new bool[count];
  bool e = true;
  memset(c, -1, count * sizeof(int));
  memset(d, false, count * sizeof(bool));
  for (int i = 0; i < count; i++) {
    if (i == 0) {
      cin >> a;
    } else {
      b = a;
      cin >> a;
      c[i - 1] = abs(b - a);
    }
  }
  for (int i = 0; i < count - 1; i++) {
    if (c[i] < count&&c[i]!=-1) {
      d[c[i]] = true;
    }
  }
  for (int i = 1; i < count; i++) {
    if (d[i] == false)
      e = false;
  }
  if (e == true)
    cout << "Jolly"<<endl;
  else
    cout << "Not jolly"<<endl;

  delete[] c;
  delete[] d;
}