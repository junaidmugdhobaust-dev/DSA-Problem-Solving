#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, target;
    cin >> n >> target;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int sum = 0;

        for (int j = i; j < n; j++) {
            if (nums[j] == target) {
                sum = sum + 1;
            } else {
                sum = sum - 1;
            }

            if (sum > 0) {
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}