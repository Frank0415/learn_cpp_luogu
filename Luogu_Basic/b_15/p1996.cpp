#include <iostream>
#include <list>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  list<int> a(n);
  int num = 1;
  for (auto i = a.begin(); i != a.end(); i++) {
    *i = num++;
  }
  int counter = 1;
  list<int>::iterator it = a.begin();
  while (!a.empty()) {
    list<int>::iterator delit;
    if (++it == a.end())
      it = a.begin();
    counter++;
    if (counter == m) {
      counter = 1;
      delit = it;
      cout << *it << " ";
      it = a.erase(delit);
      if (it == a.end())
        it = a.begin();
    }
  }
}