#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class point {
public:
  int x, y;
  point(int x_val = 0, int y_val = 0) {
    this->x = x_val;
    this->y = y_val;
  }
  point operator+(point addon);
  point operator-(point delto);
};

point point::operator+(point addon) {
  return point(this->x + addon.x, this->y + addon.y);
}

point point::operator-(point delto) {
  return point(this->x + delto.x, this->y + delto.y);
}

bool check(const vector<vector<int>> &board, int n, int m, const point &p) {
  if (p.x > n || p.x < 1 || p.y > m || p.y < 1)
    return false;
  if (board[p.x][p.y] != -1)
    return false;
  else
    return true;
}

void totrue(vector<vector<int>> &board, point horse, int curr) {
  board[horse.x][horse.y] = curr;
  return;
}

int main() {
  int n, m;
  point horse;
  cin >> n >> m >> horse.x >> horse.y;

  vector<vector<int>> board((n + 1), vector<int>(m + 1, -1));

  point jump[8] = {point(-2, -1), point(-1, -2), point(2, -1), point(1, -2),
                   point(1, 2),   point(2, 1),   point(-2, 1), point(-1, 2)};
  queue<point> q;
  q.push(horse);
  totrue(board, horse, 0);
  while (!q.empty()) {
    for (int i = 0; i < 8; i++) {
      point p = q.front() + jump[i];
      if (check(board, n, m, p)) {
          q.push(p);
          totrue(board, p, board[q.front().x][q.front().y] + 1);
      }
    }
    q.pop();
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
        printf("%-5d", board[i][j]);
    }
    cout << '\n';
  }
}