#include <iostream>
#include <cstring>

using namespace std;

long long int w(long long a, long long b, long long c,
                long long int mem[25][25][25], bool vis[25][25][25]) {
  if (a <= 0 || b <= 0 || c <= 0)
    return 1;
  if (a > 20 || b > 20 || c > 20)
    return w(20, 20, 20, mem, vis);
  if (vis[a][b][c]) {
    return mem[a][b][c];
  }
  if (a < b && b < c) {
    mem[a][b][c] = w(a, b, c - 1, mem, vis) + w(a, b - 1, c - 1, mem, vis) -
                   w(a, b - 1, c, mem, vis);
  } else {
    mem[a][b][c] = w(a - 1, b, c, mem, vis) + w(a - 1, b - 1, c, mem, vis) +
                   w(a - 1, b, c - 1, mem, vis) -
                   w(a - 1, b - 1, c - 1, mem, vis);
  }
  vis[a][b][c] = true;
  return mem[a][b][c];
}

int main() {
  long long int a, b, c;

  long long int mem[25][25][25];
  bool vis[25][25][25];
  memset(vis, false, sizeof(vis));
  memset(mem, 0, sizeof(mem));
  while (scanf("%lld%lld%lld", &a, &b, &c))
  {
      if (a == -1 && b == -1 && c == -1)
          return 0;
      else
          printf("w(%lld, %lld, %lld) = ", a, b, c);
      printf("%lld\n", w(a, b, c, mem, vis));
  }
}