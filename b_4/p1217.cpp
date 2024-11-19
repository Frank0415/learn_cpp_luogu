#include <cmath>
#include <cstdio>
#include <iostream>

//ugly solution, needs improvement, such as loop a to d from 0 to 9 and try to get if statements if the first number is 0 and store list of palindromes and sort()

using namespace std;

bool isPrime(int num) {
  if (num < 2)
    return false;
  int sq = ceil(sqrt(num)) + 1;
  for (size_t i = 2; i < sq; i++) {
    if (num % i == 0) {
      return false;
    }
  }
  return true;
}

void gen12(long int min, long int max) {
  if (min > 99)
    return;
  for (int i = min; i < 10; i++) {
    if (isPrime(i))
      cout << i << endl;
  }
  for (int i = 1; i < 10; i++) {
    int pali = i * 11;
    if (isPrime(pali)&& pali >= min)
      cout << pali << endl;
  }
  return;
}

void gen34(long int min, long int max) {
  if (min > 9999 || max < 100)
    return;
  for (int a = 1; a < 10; a = a + 2) {
    for (int b = 0; b < 10; b++) {
      int pali = a * 101 + b * 10;
      if (pali > max)
        return;
      if (isPrime(pali)&& pali >= min)
        cout << pali << endl;
    }
  }

  for (int a = 1; a < 10; a = a + 2) {
    for (int b = 0; b < 10; b++) {
      int pali = a * 1001 + b * 110;
      if (pali > max)
        return;
      if (isPrime(pali)&& pali >= min)
        cout << pali << endl;
    }
  }
}

void gen56(long int min, long int max) {
  if (min > 999999 || max < 10000)
    return;
  for (int a = 1; a < 10; a = a + 2) {
    for (int b = 0; b < 10; b++) {
      for (int c = 0; c < 10; c++) {
        int pali = a * 10001 + b * 1010 + c * 100;
        if (pali > max)
          return;
        if (isPrime(pali)&& pali >= min)
          cout << pali << endl;
      }
    }
  }
  for (int a = 1; a < 10; a = a + 2) {
    for (int b = 0; b < 10; b++) {
      for (int c = 0; c < 10; c++) {
        int pali = a * 100001 + b * 10010 + c * 1100;
        if (pali > max)
          return;
        if (isPrime(pali)&& pali >= min)
          cout << pali << endl;
      }
    }
  }
}

void gen78(long int min, long int max) {
  if (min > 99999999 || max < 1000000)
    return;
  for (int a = 1; a < 10; a = a + 2) {
    for (int b = 0; b < 10; b++) {
      for (int c = 0; c < 10; c++) {
        for (int d = 0; d < 10; d++) {
          long int pali = a * 1000001 + b * 100010 + c * 10100 + d * 1000;
          if (pali > max)
            return;
          if (isPrime(pali)&& pali >= min)
            cout << pali << endl;
        }
      }
    }
  }
  for (int a = 1; a < 10; a = a + 2) {
    for (int b = 0; b < 10; b++) {
      for (int c = 0; c < 10; c++) {
        for (int d = 0; d < 10; d++) {
          long int pali = a * 10000001 + b * 1000010 + c * 100100 + d * 11000;
          if (pali > max)
            return;
          if (isPrime(pali) && pali >= min)
            cout << pali << endl;
        }
      }
    }
  }
}

int main() {
  long int min, max;
  cin >> min >> max;
  gen12(min, max);
  gen34(min, max);
  gen56(min, max);
  gen78(min, max);
  return 0;
}