#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

namespace longcal {
string add(const string &longint, const string &addint);
void copy(int *dest, const string &src, int len);
}

class CalLongint {
private:
  string longint;

public:
  void init(const string &longinit) { longint = longinit; }
  void print() { cout << longint << endl; }
  string add(const string &addint);
  string multiply(const string &mulint);
};

string CalLongint::add(const string &addint) {
  int a = longint.length(), b = addint.length();
  int len = max(a, b);
  int *lint = new int[a]();
  int *aint = new int[b]();
  int *solu = new int[len + 1]();
  longcal::copy(lint, longint, a);
  longcal::copy(aint, addint, b);

  for (int i = 0; i < len; i++) {
    int sum = (lint[i] + aint[i] + solu[i]);
    solu[i + 1] += sum / 10;
    solu[i] = sum % 10;
  }
  if (solu[len]) {
    len++;
  }
  string solution;
  solution.clear();
  for (int i = len - 1; i >= 0; i--) {
    solution.push_back(solu[i] + '0');
  }
  delete[] lint;
  delete[] aint;
  delete[] solu;
  return solution;
}

string CalLongint::multiply(const string &mulint) {
  int a = longint.length(), b = mulint.length();
  int *lint = new int[a + 1]();
  int *aint = new int[b + 1]();
  int *solu = new int[a + b + 1]();
  string solution;

  longcal::copy(lint, longint, a);
  longcal::copy(aint, mulint, b);

  for (int i = 0; i < a; i++) {
    for (int j = 0; j < b; j++) {
      int mul = lint[i] * aint[j];
      string mulstr;
      mulstr.clear();
      mulstr = to_string(mul);
      for (int q = 0; q < i + j; q++)
        mulstr.append("0");
      solution = longcal::add(solution, mulstr);
    }
  }
  cout << solution << endl;
  delete[] lint;
  delete[] aint;
  delete[] solu;
  return solution;
}

string longcal::add(const string &longint, const string &addint) {
  int a = longint.length(), b = addint.length();
  int len = max(a, b);
  int *lint = new int[a]();
  int *aint = new int[b]();
  int *solu = new int[len + 1]();

  longcal::copy(lint, longint, a);
  longcal::copy(aint, addint, b);

  for (int i = 0; i < len; i++) {
    int sum = (lint[i] + aint[i] + solu[i]);
    solu[i + 1] += sum / 10;
    solu[i] = sum % 10;
  }
  if (solu[len]) {
    len++;
  }
  string solution;
  solution.clear();
  for (int i = len - 1; i >= 0; i--) {
    solution.push_back(solu[i] + '0');
  }
  delete[] lint;
  delete[] aint;
  delete[] solu;
  return solution;
}

void longcal::copy(int* dest, const string &src, int len) {
  for (int i = 0, j = len - 1; i < len; i++, j--)
    dest[i] = src[j] - '0';
}

int main() {
  CalLongint ans;
  ans.init("6751");
  string b = ans.add("20000");
  ans.multiply("22");
  cout << b << endl;
  return 0;
}
