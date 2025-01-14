#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canCutEnoughWood(const vector<int>& trees, int H, int M) {
    long long totalWood = 0;
    for (int height : trees) {
        if (height > H) {
            totalWood += height - H;
        }
    }
    return totalWood >= M;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> trees(N);
    for (int i = 0; i < N; ++i) {
        cin >> trees[i];
    }

    int low = 0, high = *max_element(trees.begin(), trees.end());
    int result = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canCutEnoughWood(trees, mid, M)) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << result << endl;
    return 0;
}