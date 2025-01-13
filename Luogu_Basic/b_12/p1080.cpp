#include <algorithm>
#include <iostream>
#include <vector>

struct person {
  long long int left;
  long long int right;
  long long int value;
};

using namespace std;

int main() {
  long long int count, max = 0;
  cin >> count;
  vector<person> a(count + 1);

  for (long long int i = 0; i < count + 1; i++) {
    cin >> a[i].left >> a[i].right;
  }

  sort(a.begin() + 1, a.end(),
       [](person c, person b) { return c.left * c.right < b.left * b.right; });

  for (long long int i = 1; i < count; i++) {
    long long int value = a[0].left;
    for (long long int j = 1; j < i; j++) {
      value *= a[j].left;
    }

    if (value > max)
      max = value;
  }
  cout << max << endl;
  return 0;
}