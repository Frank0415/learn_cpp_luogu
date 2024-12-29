#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

void decompose(int &a, vector<int> &list) {
  if (a <= 0)
    return;
  int pown = 0;
  while (pow(2, pown) <= a) {
    pown++;
  }
  pown--;
  a -= pow(2, pown);
  list.push_back(pown);
  decompose(a, list);
}

void print(int num) {
  vector<int> a;
  decompose(num, a);
  for (size_t i = 0; i < a.size(); i++) {
    cout << "2";
    if (a[i] == 1) {
      ;
    } else if (a[i] == 0) {
      cout << "(0)";
    } else if (a[i] == 2) {
      cout << "(2)";
    } else {
      cout << "(";
      print(a[i]);
      cout << ")";
    }
    if (i != a.size() - 1) {
      cout << '+';
    } else {
      //cout << endl;
    }
  }
}

int main() {
  int input;
  cin >> input;
  print(input);
  cout << endl;
}