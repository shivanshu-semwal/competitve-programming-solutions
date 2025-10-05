#include <bits/stdc++.h>
#include <climits>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    // vector<int> a(n * m, 0);
    int m1 = INT_MAX, m2 = INT_MAX, mm1 = INT_MIN, mm2 = INT_MIN;
    for (int i = 0; i < n * m; i++) {
        // cin >> a[i];
        int t;
        cin >> t;
        if (t > mm1) {
            mm2 = mm1;
            mm1 = t;
        } else if (t > mm2) {
            mm2 = t;
        }

        if (t < m1) {
            m2 = m1;
            m1 = t;
        } else if (t < m2) {
            m2 = t;
        }
    }

    if (n < m) {
        int t = n;
        n = m;
        m = t;
    }

    int no_max1 = (n - 1) * m;
    int no_max2 = m - 1;
    // cout << m1 << " " << m2 << " " << mm1 << " " << mm2 << endl;
    cout << (mm1 - m1) * no_max1 + no_max2 * max(mm2 - m1, mm1 - m2) << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}