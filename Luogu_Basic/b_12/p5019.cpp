#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int len;
  cin >> len;
  int sum = 0;
  vector<int> a(len);
  for (int i = 0; i < len; i++) {
    cin >> a[i];
  }
  sum = a[0];
  for (int i = 1; i < len; i++)
  {
    if (a[i]>a[i-1])
    {
        sum += a[i] - a[i - 1];
    }
  }
  cout << sum << endl;
  return 0;
}