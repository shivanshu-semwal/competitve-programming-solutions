#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        if (n > m) {
            cout << "0\n";
            continue;
        }
        for (ll i = 0; i < n; i++) {
            ll no = n ^ i;
            if (!(no >= 0 && no <= m)) {
                cout << i << "\n";
                break;
            }
        }
    }
    return 0;
}