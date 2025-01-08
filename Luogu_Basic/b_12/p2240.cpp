#include <algorithm>
#include <iostream>

using namespace std;

struct pile {
  double mass;
  double value;
  double uvalue;
};

bool cmp(pile a, pile b) { return a.uvalue > b.uvalue; }

int main() {
  int bp = 0, count = 0;
  double value = 0;
  cin >> count >> bp;
  pile *p;
  p = new pile[count];

  for (int i = 0; i < count; i++) {
    cin >> p[i].mass >> p[i].value;
    p[i].uvalue = p[i].value / p[i].mass;
  }

  sort(p, (p + count), cmp);

  int k = 0;

  cout << "hhj";

  while (bp > 0) {
    if (bp <= p[k].mass) {
      bp = 0;
      value += bp * p[k].uvalue;
    } else {
      value += p[k].value;
      k++;
      bp -= p[k].mass;
    }
  }
  printf("%.2f\n", value);
  delete[] p;
}