#include <iostream>

using namespace std;

int stackop(int size, int stack) {
  int count = 0;
  if (size == 0) {
    return 1;
  }

  for (int i = 0; i <= stack; i++) {
    count += stackop(size - 1, stack + 1 - i);
  }
  return count;
}

int main() {
  int size, solu;
  cin >> size;
  solu = stackop(size, 0);
  cout << solu<<endl;
}