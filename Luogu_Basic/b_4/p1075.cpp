#include <cmath>
#include <cstdio>
#include <iostream>

int main() {
  long long int a;
  std::cin >> a;
  for (long long int i = 2; i < sqrt(a); i++) {
    if (a % i == 0) {
      std::cout << a / i << std::endl;
      return 0;
    }
  }
  return 0;
}