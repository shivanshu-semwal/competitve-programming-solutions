#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;
        ll ans;
        if (a == b) {
            ans = 0;
        } else if (b % 2 == 0 && b / 2 + 1 >= a) {
            ans = b % (b / 2 + 1);
        } else if (b / 2 + 1 >= a) {
            ans = b % (b / 2 + 1);
        } else {
            ans = b % a;
        }
        cout << ans << "\n";
    }
    return 0;
}