#include <algorithm>
#include <iostream>
using namespace std;

struct order {
  double time;
  int rank;
};

bool cmp(order a, order b) { return a.time < b.time; }

int main() {
  int num;
  order *time;
  cin >> num;
  time = new order[num];

  for (int i = 0; i < num; i++) {
    cin >> time[i].time;
    time[i].rank = i + 1;
  }
  sort(time, time + num, cmp);
  double sum = 0, avg = 0;

  for (int i = 0; i < num; i++) {
    sum += time[i].time * (num - i-1);
    cout<<time[i].rank ;
    if (i != num - 1)
      cout << " ";
    else
      cout << endl;
  }
  if (sum != 0)
      avg = sum / num;
  else
    avg = 0;
  printf("%.2f\n", avg);
  delete[] time;
}