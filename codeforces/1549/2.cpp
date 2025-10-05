#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        string aa, bb;

        cin >> aa;
        cin >> bb;

        vector<ll> a(n);
        vector<ll> b(n);

        for (ll i = 0; i < n; i++) {
            a[i] = aa[i] - '0';
        }

        for (ll i = 0; i < n; i++) {
            b[i] = bb[i] - '0';
        }

        // for (ll i = 0; i < n; i++) {
        //     cout  << a[i] << " ";
        // }
        // cout << endl;

        // for (ll i = 0; i < n; i++) {
        //     cout  << b[i] << " ";
        // }
        // cout << endl;


        ll total = 0;

        for (ll i = 0; i < n; i++) {
            if (b[i] == 1) {
                if (a[i] == 0) {
                    total++;
                    a[i] = -1; // pawn reached
                } else if (i > 0 && a[i - 1] == 1) {
                    total++;
                    a[i - 1] = -1; // pawn reached
                } else if (i < n - 1 && a[i + 1] == 1) {
                    total++;
                    a[i + 1] = -1;
                }
            }
        }

        cout << total << "\n";
    }
    return 0;
}