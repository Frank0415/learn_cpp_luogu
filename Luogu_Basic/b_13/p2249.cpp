#include <iostream>

using namespace std;

int search(int *nums, int len, int curr);

int main() {
    int num = 0, query = 0;
    cin >> num >> query;
    int curr;
    int *nums = new int[num];
    for (int i = 0; i < num; i++) {
        cin >> nums[i];
    }
    for (int i = 0; i < query; i++) {
        cin >> curr;
        cout << search(nums, num, curr);
        if (i != query - 1) {
            cout << ' ';
        } else {
            cout << endl;
        }
    }
    delete[] nums;
    return 0;
}

int search(int *nums, int len, int curr) {
    int l = 0, r = len - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] == curr) {
            while (mid > 0 && nums[mid - 1] == curr) {
                mid--;
            }
            return mid + 1;
        } else if (nums[mid] < curr) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1;
}
