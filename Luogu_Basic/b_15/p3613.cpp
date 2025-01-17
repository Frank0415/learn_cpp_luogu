#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n, q;
    cin >> n >> q;

    vector<vector<int>> a(n+1);

    int op,i, j, k;

    for (int p = 0; p < q; p++)
    {
        cin >> op;
        if (op ==1)
        {
            cin >> i >> j >> k;
            if (a[i].size()<j+1)
            {
                a[i].resize(j + 1);
            }
            a[i][j] = k;
        }
        else {
            cin >> i >> j;
            cout << a[i][j] << endl;
        }
    }
    return 0;
}