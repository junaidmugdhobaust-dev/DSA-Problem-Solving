#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> songs(n);
    for (int i = 0; i < n; i++) {
        cin >> songs[i];
    }

    set<int> st;
    int left = 0;
    int ans = 0;

    for (int right = 0; right < n; right++) {
        while (st.count(songs[right])) {
            st.erase(songs[left]);
            left++;
        }

        st.insert(songs[right]);
        ans = max(ans, right - left + 1);
    }

    cout << ans << endl;

    return 0;
}