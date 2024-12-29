#include <cstring>
#include <iostream>
#include <string>

using namespace std;

#define MAXN 1500

class longclass {
private:
  int *num;
  int len;

public:
  longclass(const string &num = "0");
  ~longclass();
  longclass(const longclass &other);
  longclass operator+(const longclass &a) const;
  longclass &operator=(const longclass &other);
  void print() const;
  void flat(const int &newlen);
};

longclass::longclass(const string &innum) {
  num = new int[MAXN]();
  len = innum.length();
  for (int i = 0; i < len; i++) {
    num[i] = innum[len - 1 - i] - '0';
  }
}

longclass::~longclass() { delete[] num; }

longclass::longclass(const longclass &other) {
  num = new int[MAXN];
  len = other.len;
  memcpy(num, other.num, sizeof(int) * MAXN);
}

longclass &longclass::operator=(const longclass &other) {
  if (this == &other)
    return *this;
  delete[] num;
  num = new int[MAXN];
  len = other.len;
  memcpy(num, other.num, sizeof(int) * MAXN);
  return *this;
}

longclass longclass::operator+(const longclass &a) const {
  longclass result("0");
  int lenmax = max(a.len, this->len);
  for (int i = 0; i < lenmax; i++) {
    result.num[i] = this->num[i] + a.num[i];
  }
  result.flat(len + 1);
  return result;
}

void longclass::print() const {
  for (int i = len; i > 0; i--) {
    cout << this->num[i - 1];
  }
  cout << endl;
}

void longclass::flat(const int &newlen) {
  this->len = newlen;
  for (int i = 0; i < newlen; i++) {
    this->num[i + 1] += this->num[i] / 10;
    this->num[i] = this->num[i] % 10;
  }
  while (this->len > 1 && this->num[this->len - 1] == 0) {
    this->len--;
  }
}

longclass rec_stp(int levels, longclass a, longclass b) {
  if (levels == 1) {
    return b;
  }
  return rec_stp(levels - 1, b, a + b);
}

int main() {
  int levels = 2;
  cin >> levels;
  longclass a("1"), b("1"), c;
  c = rec_stp(levels, a, b);
  c.print();
  return 0;
}

/*#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define MAXN 8000

class longclass {
private:
  int *longnum;
  int len;

public:
  longclass(const string &num = "0");
  ~longclass();
  void flatten(int len);
  longclass(const longclass &other);
  int &operator[](const int i);
  longclass &operator=(const longclass &other);
  longclass operator+(const longclass &a) const;
  longclass operator+(const int a) const;
  //longclass operator*(const longclass &a) const;
  longclass operator*(const int a) const;
  void print() const;
};

longclass::longclass(const string &num) {
  longnum = new int[MAXN];
  memset(this->longnum, 0 , sizeof(int) * MAXN);
  len = num.length();
  for (int i = 0; i < len; ++i) {
    longnum[i] = num[len - 1 - i] - '0';
  }
}

longclass::longclass(const longclass &other) {
  longnum = new int[MAXN];
  len = other.len;
  memcpy(longnum, other.longnum, sizeof(int) * MAXN);
}

longclass::~longclass() { delete[] longnum; }

int& longclass::operator[](const int i){
    return this->longnum[i];
}

longclass& longclass::operator=(const longclass &other) {
  if (this == &other) return *this;
  delete[] longnum;
  longnum = new int[MAXN];
  len = other.len;
  memcpy(longnum, other.longnum, sizeof(int) * MAXN);
  return *this;
}

void longclass::flatten(int l) {
  this->len = l;
  for (int i = 0; i < l; i++) {
    longnum[i + 1] += longnum[i] / 10;
    longnum[i] = longnum[i] % 10;
  }
  while (this->longnum[this->len] == 0) {
    //this->print();
    this->len--;
  }
  this->len++;
}

longclass longclass::operator+(const longclass &a) const {
  longclass result;
  int lenmax = max(a.len, this->len);
  for (int i = 0; i < lenmax; ++i) {
    result.longnum[i] = this->longnum[i] + a.longnum[i];
  }
  result.flatten(lenmax + 1);
  return result;
}

longclass longclass::operator*(const int a) const{
    longclass result;
    int lenint = sizeof(a) / sizeof(int);
    for (int i = 0; i < this->len; i++)
    {
        result[i] = a * this->longnum[i];
    }
    result.flatten(lenint + this->len);
    return result;
}

void longclass::print() const {
  for (int i = this->len; i > 0; i--) {
    cout << this->longnum[i-1] ;
  }
  cout << endl;
}

longclass rec_stp(int levels, longclass a, longclass b) {
  // cout << a << b << endl;
  if (levels == 1) {
    return b;
  }
  return rec_stp(levels - 1, b, a + b);
}

longclass longclass::operator+(int a) const { return *this; }

int main() {
  longclass a("1"), b("1"), c;
  int len;
  cin >> len;
  c=rec_stp(len, a, b);
  c.print();
}*/