#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        vector<vector<ll>> nobels(n);
        for (ll i = 0; i < m; i++) {
            ll a, b;
            cin >> a >> b;
            nobels[a].push_back(b);
            nobels[b].push_back(a);
        }
        ll q;
        cin >> q;
        for (ll i = 0; i < q; i++) {
            int no;
            cin >> no;
            if (no == 1) {
                ll a, b;
                cin >> a >> b;
                nobels[a].push_back(b);
                nobels[b].push_back(a);
            } else if (no == 2) {
                ll a, b;
                cin >> a >> b;
                
            } else {
            }
        }
    }
    return 0;
}