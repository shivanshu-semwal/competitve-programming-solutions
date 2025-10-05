#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<ll> sums(n + 1, -1e18);

    sums[0] = 0;

    /* maximum array sum for all lengths */
    sums[0] = 0;
    for (int i = 0; i < n; i++) {
        ll cur = 0;
        for (int j = i; j < n; j++) {
            cur += a[j];
            sums[j - i + 1] = max(sums[j - i + 1], cur);
        }
    }

    vector<ll> ans(n + 1, -1e18);

    for (int take = 0; take <= n; take++) {
        for (int i = 0; i <= n; i++) {
            ll res = sums[i] + x * min(take, i);
            ans[take] = max(ans[take], res);
        }
    }

    for (auto it : ans) cout << it << ' ';
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}