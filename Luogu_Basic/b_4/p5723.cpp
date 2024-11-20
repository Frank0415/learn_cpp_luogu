#include <cmath>
#include <iostream>

using namespace std;

bool isprime(int num) {
  if (num < 2)
    return false;
  for (int i = 2; i <= sqrt(num); i++) {
    if (num % i == 0)
      return false;
  }
  return true;
}

int main() {
  int count = 0, size, currPrime = 2;
  cin >> size;
  while (size > 0) {
    while (isprime(currPrime) == false) {
      currPrime++;
    }
    size = size - currPrime;
    if (size < 0) {
      cout << count << endl;
      return 0;
    }
    count++;
    cout << currPrime << endl;
    currPrime++;
  }
  cout << count << endl;
}