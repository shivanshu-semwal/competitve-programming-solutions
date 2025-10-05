#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll a[n], b[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        for (int i = 0; i < n; i++) {
            a[i] = a[i] - b[i];
        }
        ll sum = 0;
        ll pos = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
            if (a[i] > 0) pos += a[i];
        }
        if (sum == 0) {
            cout << pos << "\n";
            for (int i = 0; i < n && pos != 0; i++) {
                if (a[i] > 0) {
                    for (int j = 0; j < n && a[i]; j++) {
                        if (a[j] < 0) {
                            cout << (i + 1) << " " << (j + 1) << "\n";
                            a[i] -= 1;
                            a[j] += 1;
                            j--;
                        }
                    }
                    pos--;
                }
            }
        } else {
            cout << "-1\n";
        }
    }
    return 0;
}