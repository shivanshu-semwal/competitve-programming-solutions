// https://codeforces.com/contest/1542/problem/B

#include <bits/stdc++.h>

#define lli long long
#define ll long long

using namespace std;

void solve() {
    ll n, a, b;
    cin >> n >> a >> b;
    if (b == 1) {
        cout << "YES\n";
        return;
    }
    if (a == 1) {
        if (n % b == 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        return;
    }

    for (ll pp = 1; pp <= n; pp *= a) {
        if ((n - pp) % b == 0) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}
int main() {
    lli t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}