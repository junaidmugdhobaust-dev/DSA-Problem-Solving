#include <bits/stdc++.h>
using namespace std;

int countSwaps(vector<int> arr, vector<int> target) {
    int n = arr.size();
    int swaps = 0;

    unordered_map<int, int> pos;

    for (int i = 0; i < n; i++) {
        pos[arr[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] == target[i]) {
            continue;
        }

        int correctValue = target[i];
        int correctIndex = pos[correctValue];

        pos[arr[i]] = correctIndex;
        pos[correctValue] = i;

        swap(arr[i], arr[correctIndex]);
        swaps++;
    }

    return swaps;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> asc = arr;
    vector<int> desc = arr;

    sort(asc.begin(), asc.end());
    sort(desc.begin(), desc.end(), greater<int>());

    int ans1 = countSwaps(arr, asc);
    int ans2 = countSwaps(arr, desc);

    cout << min(ans1, ans2) << endl;

    return 0;
}