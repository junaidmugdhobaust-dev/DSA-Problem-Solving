#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long l;
    cin >> n >> l;

    vector<long long> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    double ans = 0.0;

    ans = max(ans, (double)a[0]);

    ans = max(ans, (double)(l - a[n - 1]));

    for (int i = 0; i < n - 1; i++) {
        double gap = (a[i + 1] - a[i]) / 2.0;
        ans = max(ans, gap);
    }

    cout << ans << endl;

    return 0;
}