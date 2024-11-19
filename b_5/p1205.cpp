#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isthesame(int n, const vector<vector<char>>& a, const vector<vector<char>>& b) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] != b[i][j]) {
                return false;
            }
        }
    }
    return true;
}

vector<vector<char>> t1(int n, const vector<vector<char>>& init) { // 90deg
    vector<vector<char>> temp(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[i][j] = init[n - j - 1][i];
        }
    }
    return temp;
}

vector<vector<char>> t2(int n, const vector<vector<char>>& init) { // 180deg
    return t1(n, t1(n, init));
}

vector<vector<char>> t3(int n, const vector<vector<char>>& init) { // 270deg
    return t1(n, t2(n, init));
}

vector<vector<char>> reflect(int n, const vector<vector<char>>& init) { // Reflect horizontally
    vector<vector<char>> temp(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[i][j] = init[i][n - j - 1];
        }
    }
    return temp;
}

bool work1(int n, const vector<vector<char>>& init, const vector<vector<char>>& trans) {
    return isthesame(n, t1(n, init), trans);
}

bool work2(int n, const vector<vector<char>>& init, const vector<vector<char>>& trans) {
    return isthesame(n, t2(n, init), trans);
}

bool work3(int n, const vector<vector<char>>& init, const vector<vector<char>>& trans) {
    return isthesame(n, t3(n, init), trans);
}

bool work4(int n, const vector<vector<char>>& init, const vector<vector<char>>& trans) {
    return isthesame(n, reflect(n, init), trans);
}

bool work5(int n, const vector<vector<char>>& init, const vector<vector<char>>& trans) {
    vector<vector<char>> reflected = reflect(n, init);
    return work1(n, reflected, trans) || work2(n, reflected, trans) || work3(n, reflected, trans);
}

bool work6(int n, const vector<vector<char>>& init, const vector<vector<char>>& trans) {
    return isthesame(n, init, trans);
}

void work(int n, const vector<vector<char>>& init, const vector<vector<char>>& trans) {
    if (work1(n, init, trans)) {
        cout << 1 << endl;
        return;
    }
    if (work2(n, init, trans)) {
        cout << 2 << endl;
        return;
    }
    if (work3(n, init, trans)) {
        cout << 3 << endl;
        return;
    }
    if (work4(n, init, trans)) {
        cout << 4 << endl;
        return;
    }
    if (work5(n, init, trans)) {
        cout << 5 << endl;
        return;
    }
    if (work6(n, init, trans)) {
        cout << 6 << endl;
        return;
    }
    cout << 7 << endl;
}

int main() {
    int n;
    cin >> n;
    vector<vector<char>> init(n, vector<char>(n));
    vector<vector<char>> trans(n, vector<char>(n));

    // Read the input for init matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> init[i][j];
        }
    }

    // Read the input for trans matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> trans[i][j];
        }
    }

    work(n, init, trans);

    return 0;
}