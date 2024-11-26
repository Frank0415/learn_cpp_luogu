#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

bool customSwap(string &a, string &b) { return (a + b > b + a); }

int main() {
  string s[21];
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  sort(s, s + n, customSwap);
  for (int i = 0; i < n; i++) {
    cout << s[i];
  }
  cout << endl;
}