#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll a[n];
        ll b[n];
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
            b[i] = 0;
        }
        for (ll i = 0; i < n; i++) {
            bool swap = false;
            for (ll j = 0; j < n - i - 1; j++) {
                if (a[j] > a[j + 1]) {
                    //swap
                    swap = true;
                    ll temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;

                    //dir
                    temp = b[j + 1];
                    b[j + 1] = (b[j] == 1) ? 0 : 1;
                    b[j] = (temp == 1) ? 0 : 1;
                }
            }
            if (!swap) break;
        }
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (b[i]) flag = false;
        }
        if (flag) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}