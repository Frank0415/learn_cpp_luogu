#include <iostream>

using namespace std;

void check(int row, int col, char **&table) {
  const int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
  const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      int sum = 0;
      if (table[i][j] == '*')
        continue;
      for (int k = 0; k < 8; k++) {
        if (i + dx[k] < 0 || i + dx[k] >= row || j + dy[k] < 0 ||
            j + dy[k] >= col) {
          continue;
        }
        if (table[i + dx[k]][j + dy[k]] == '*') {
          sum++;
        }
      }
      table[i][j] = sum + '0';
    }
  }
}

int main() {
  int row, col;
  cin >> row >> col;

  char **table = new char *[row];
  for (int i = 0; i < row; i++) {
    table[i] = new char[col];
  }
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      cin >> table[i][j];
    }
  }
  check(row, col, table);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      cout << table[i][j];
    }
    cout << endl;
  }
  for (int i = 0; i < row; i++) {
    delete[] table[i];
  }
  delete[] table;
}