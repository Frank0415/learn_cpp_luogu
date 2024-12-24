#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string add(string longint, string addint);

namespace longcal {
string add(string longint, string addint);
}

class CalLongint {
private:
  string longint;

public:
  void init(const string &longinit) { longint = longinit; }
  void print() { cout << longint << endl; }
  string add(string addint);
  string multiply(string mulint);
};

string CalLongint::add(string addint) {
  int a = longint.length(), b = addint.length();
  int len = max(a, b);
  int *lint = new int[a]();
  int *aint = new int[b]();
  int *solu = new int[len + 1]();
  for (int i = 0, j = a - 1; i < a; i++, j--)
    lint[i] = longint[j] - '0';
  for (int i = 0, j = b - 1; i < b; i++, j--)
    aint[i] = addint[j] - '0';

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

string CalLongint::multiply(string mulint) {
  int a = longint.length(), b = mulint.length();
  int len = max(a, b);
  int *lint = new int[a + 1]();
  int *aint = new int[b + 1]();
  int *solu = new int[a + b + 1]();
  string solution;

  for (int i = 0, j = a - 1; i < a; i++, j--)
    lint[i] = longint[j] - '0';
  for (int i = 0, j = b - 1; i < b; i++, j--)
    aint[i] = mulint[j] - '0';

  for (int i = 0; i < a; i++) {
    for (int j = 0; j < b; j++) {
      int mul = lint[i] * aint[j];
      string mulstr;
      mulstr.clear();
      mulstr = to_string(mul);
      for (int q = 0; q < i + j; q++)
        mulstr.append("0");
      solution = longcal::add(solution, mulstr);
      cout << solution << endl;
    }
  }

  delete[] lint;
  delete[] aint;
  delete[] solu;
  return solution;
}

string longcal::add(string longint, string addint) {
  int a = longint.length(), b = addint.length();
  int len = max(a, b);
  int *lint = new int[a]();
  int *aint = new int[b]();
  int *solu = new int[len + 1]();
  for (int i = 0, j = a - 1; i < a; i++, j--)
    lint[i] = longint[j] - '0';
  for (int i = 0, j = b - 1; i < b; i++, j--)
    aint[i] = addint[j] - '0';

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

int main() {
  CalLongint ans;
  ans.init("6751");
  string b = ans.add("20000");
  ans.multiply("22");
  cout << b;

  return 0;
}
