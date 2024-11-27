#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int main() {
  long long int size;
  cin >> size;
  long long int level = 0;
  while ((level + 1) * (level + 2) < 2 * size) {
    level++;
    // cout << level << endl;
  } // fix edge cases
  // level--;
  size = size - level * (level + 1) / 2;
  level += 2;
  if ((level-size)==4&&size==1)
  {
      cout << "1/4" << endl;
      return 0;
  }

  cout << level - size << "/" << size << endl;
}