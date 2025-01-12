#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int count, sum = 0, temp;
  cin >> count;
  vector<int> a(count);
  vector<int> b(count);
  int aa = 0, bb = 0;
  for (int i = 0; i < count; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end(), [](int x, int y) { return x < y; });
  int len = -1;
  for (int i = 1; i < count; i++)
  {
      if ((b[bb] < a[aa] && bb <= len) || aa>=count)
          temp = b[bb++];
      else
          temp = a[aa++];
      if ((b[bb] < a[aa] && bb <= len) || aa >= count)
          temp += b[bb++];
      else
          temp += a[aa++];
      b[++len] = temp;
      sum += temp;
  }
  cout << sum << endl;
}