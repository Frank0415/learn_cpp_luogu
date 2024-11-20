// P25 P1425

#include <iostream>
#include <stdio.h>

int main() {
  int a, b, c, d, hrs, min;
  std::cin >> a >> b >> c >> d;
  min = d - b;
  hrs = c - a;
  if (min < 0) {
    hrs -= 1;
    min += 60;
  }
  std::cout << hrs << " " << min << std::endl;
}