#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void input(vector<int> &s, int &sum, const int &len) {
  for (int i = 0; i < len; i++) {
    cin >> s[i];
    sum += s[i];
  }
}

void search(const vector<int> &s, int len, int sum, int currsum, int currlen,
            int &maxn) {
  if (currsum * 2 > sum) {
    return;
  }
  if (currlen > len) {
    maxn = max(currsum, maxn);
    return;
  }
  search(s, len, sum, currsum, currlen + 1, maxn);
  search(s, len, sum, currsum + s[currlen - 1], currlen + 1, maxn);
}

int backpack(const vector<int> &a, int len, int sum) {
  vector<int> dp(sum+1, 0);
  for (int i = 0; i < len; i++) {
    for (int j = sum/2; j >= a[i]; j--) {
      dp[j] = max(dp[j], dp[j - a[i]] + a[i]);
    }
  }
  return dp[sum/2];
}


int main() {
  int s[5] = {0};
  cin >> s[1] >> s[2] >> s[3] >> s[4];
  vector<vector<int>> a(5, vector<int>(21));

  int sumtime = 0;

  for (int i = 1; i < 5; i++) {
    int sum = 0, currsum = 0, currlen = 1, maxn = 0;
    input(a[i], sum, s[i]);
    search(a[i], s[i], sum, currsum, currlen, maxn);
    //maxn = backpack(a[i], s[i], sum);
    sumtime += sum - maxn;
  }

  cout << sumtime << endl;
}