#include <iostream>

using namespace std;

void dfs(int *tree, int *winner, int level) {
  if (level >= (1 << tree[0])) {
    return;
  }
  dfs(tree, winner, level * 2);
  dfs(tree, winner, level * 2 + 1);
  int left = tree[2 * level];
  int right = tree[2 * level + 1];
  tree[level] = left > right ? left : right;
  winner[level] = left > right ? winner[2*level] : winner[2*level+1];
  return;
}

int main() {
  int a;
  cin >> a;
  int *tree = new int[1 << (a + 1)];
  int *winner = new int[1 << (a + 1)];
  tree[0] = a;
  for (int i = 0; i < (1 << a); i++)
  {
      cin >> tree[i + (1 << a)];
      winner[i + (1 << a)] = i + 1;
  }

  dfs(tree, winner, 1);
  cout << (tree[2] == tree[1]) ? winner[3] : winner[2] << '\n';
}