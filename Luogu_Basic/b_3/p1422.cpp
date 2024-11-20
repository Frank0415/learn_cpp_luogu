#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

// better solution: scanf("%c-%c%c%c-%c%c%c%c%c-%c")

int main() {
  string a;
  int b;
  cin >> a;
  b = (a[0] - '0') * 1 + (a[1 + 1] - '0') * 2 + (a[2 + 1] - '0') * 3 +
      (a[3 + 1] - '0') * 4 + (a[4 + 2] - '0') * 5 + (a[5 + 2] - '0') * 6 +
      (a[6 + 2] - '0') * 7 + (a[7 + 2] - '0') * 8 + (a[8 + 2] - '0') * 9 ;
  b = b % 11;
  //cout << b << endl;
  if ((a[12] - '0') == b || a[12] == 'X' && b == 10)
  {
      cout << "Right" << endl;
      return 0;
  }
  else
      for (size_t i = 0; i < 12; i++)
      {
          cout << a[i];
      }
  if (b != 10)
    cout << b << endl;
  else
    cout << 'X' << endl;
  return 0;
}

