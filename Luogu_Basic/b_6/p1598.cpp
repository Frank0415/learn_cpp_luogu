#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

void countnum(string line, int *count) {
  for (size_t i = 0; i < line.length(); i++) {
    if ('A' <= line[i] && line[i] <= 'Z') {
      count[line[i] - 'A']++;
    }
  }
}

int main() {
  string line[4] = {"\0"};
  int count[27] = {0};
  for (int i = 0; i < 4; i++) {
    getline(cin, line[i]);
  }
  for (int i = 0; i < 4; i++) {
    countnum(line[i], count);
  }
  int max_count = 0;
  for (int i = 0; i < 26; i++) {
    if (count[i] > max_count) {
      max_count = count[i];
    }
  }
  for (int i = 0; i < max_count; i++) {
    for (int j = 0; j < 26; j++) {
      if (i + count[j] >= max_count)
        cout << "*";
      else
        cout << " ";
      if (j < 25) {
        cout << " ";
      }
    }
    cout << endl;
  }
  for (int i = 0; i < 26; i++) {
    cout << char('A' + i);
    if (i < 25) {
      cout << " ";
    }
  }
  cout << endl;

  return 0;
}
