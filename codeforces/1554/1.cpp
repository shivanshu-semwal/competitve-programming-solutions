#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> v(n);
        for (ll i = 0; i < n; i++) {
            cin >> v[i];
        }
        vector<ll> max_v(n);
        vector<ll> min_v(n);

        ll j, max, min;
        for (ll i = 0; i <= n - 2; i++) {
            max = v[i];
            min = v[i];
            for (j = 1; j < 2; j++) {
                if (v[i + j] > max)
                    max = v[i + j];
            }
            for (j = 1; j < 2; j++) {
                if (v[i + j] < min)
                    min = v[i + j];
            }
            max_v.push_back(max);
            min_v.push_back(min);
        }

        ll maxp = max_v[0] * min_v[0];
        for (ll i = 1; i < max_v.size(); i++) {
            ll pro = max_v[i]  * min_v[i];
            if(maxp < pro){
                maxp = pro;
            }
        }
        cout << maxp << "\n";
    }
    return 0;
}