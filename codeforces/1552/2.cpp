#include <bits/stdc++.h>
#include <limits>
#define ll long long int

using namespace std;

bool compare(vector<ll> a, vector<ll> b) {
    int count = 0;
    for (int i = 0; i < 5; i++) {
        if (a[i] < b[i]) {
            count++;
        }
    }
    if (count >= 3) return true;
    return false;
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<vector<ll>> a;
        for (ll i = 0; i < n; i++) {
            vector<ll> temp(5);
            for (ll j = 0; j < 5; j++) {
                cin >> temp[j];
            }
            a.push_back(temp);
        }
        if (n == 1) {
            cout << "1\n";
            continue;
        }
        for (ll i = 0; i < n;) {
            ll j;
            for (j = i + 1; j < n; j++) {
                if (!compare(a[i], a[j])) {
                    i = j;
                    break;
                }
            }
            if (j == n) {
                bool flag = true;
                for (ll k = 0; k < i; k++) {
                    if (!compare(a[i], a[k])) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    cout << i + 1 << "\n";
                } else {
                    cout << "-1\n";
                }
                break;
            }
        }
    }
    return 0;
}
