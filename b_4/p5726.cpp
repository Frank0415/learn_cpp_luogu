#include <cmath>
#include <iostream>

using namespace std;

int main() {
  float min = 10, max = 0, sum = 0, len, cur;
  cin >> len;
  for (size_t i = 0; i < len; i++) {
    cin >> cur;
    if (cur > max)
      max = cur;
    if (cur < min)
      min = cur;
    sum = sum + cur;
    //cout << sum << endl;
  }
  float x = (sum - max - min) / (len - 2);
  printf("%.2f\n", x);
}