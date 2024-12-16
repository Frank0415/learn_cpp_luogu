#include <algorithm>
#include <iostream>

using namespace std;

long long int rec_stp(int levels, long long int a, long long int b) {
  //cout << a << b << endl;
  if (levels == 1) {
    return b;
  }
  return rec_stp(levels - 1, b, a + b);
}

int main() {
  int levels;
  cin >> levels;
  //cout << levels << endl;
  long long int a = 1, b = 1, c = 0;
  c = rec_stp(levels, a, b);
  cout << c << endl;
}