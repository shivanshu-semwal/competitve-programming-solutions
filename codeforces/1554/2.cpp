#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        vector<ll> v(n);
        for (ll i = 0; i < n; i++) {
            cin >> v[i];
        }
        vector<ll> sliding;
        for (ll i = 0; i < n-1; i++) {
            ll ans = (i+1) * (i+2) - k * (v[i] | v[i+1]);
            sliding.push_back(ans);
        }

        // for(ll i: sliding){
        //     cout << i << " ";
        // }
        // cout << endl;
        
        ll ans = *max_element(sliding.begin(), sliding.end());
        cout << ans << "\n";
    }
    return 0;
}