#include <iostream>
#include <vector>

using namespace std;

void dfs(int row, int size, vector<bool> &cols, vector<bool> &d1, vector<bool> &d2, int &out, int &sum, vector<int> &positions) {
    if (row == size) {
        if (out > 0) {
            for (int i = 0; i < size; i++) {
                cout << positions[i] + 1 << (i < size - 1 ? ' ' : '\n');
            }
            out--;
        }
        sum++;
        return;
    }

    for (int col = 0; col < size; col++) {
        if (!cols[col] && !d1[row - col + size - 1] && !d2[row + col]) {
            cols[col] = d1[row - col + size - 1] = d2[row + col] = true;
            positions[row] = col;
            dfs(row + 1, size, cols, d1, d2, out, sum, positions);
            cols[col] = d1[row - col + size - 1] = d2[row + col] = false;
        }
    }
}

int main() {
    int size, sum = 0, out = 3;
    cin >> size;
    vector<bool> cols(size, false), d1(2 * size - 1, false), d2(2 * size - 1, false);
    vector<int> positions(size);
    dfs(0, size, cols, d1, d2, out, sum, positions);
    cout << sum << endl;
}
