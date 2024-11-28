#include <iostream>

using namespace std;

/*int main() {
  int a, b;
  cin >> a >> b;
  int sq = (a < b) ? a : b;
  long long int sumsq = 0;
  for (int i = 0; i < sq; i++) {
    sumsq += (a - i) * (b - i);
  }
  cout << sumsq << " ";
  long long int sum = 0;
  for (int i = 0; i < a; i++)
  {
    for (int j = 0; j < b; j++)
    {
        sum += (a - i) * (b - j);
    }
  }
  sum -= sumsq;
  cout << sum << endl;
}*/

long long n, m, rec, sqr;
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++)     // 循环，从n-0到n-(n-1)
    for (int j = 0; j < m; j++) { // 循环，从m-0到m-(m-1)
      if (i == j)
        sqr += (n - i) * (m - j); // 如果i==j，说明是正方形
      else
        rec += (n - i) * (m - j); // 如果不等说明是矩形
    }
  cout << sqr << " " << rec << endl; // 输出
  return 0;
}