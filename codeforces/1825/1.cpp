#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    for (int i = s.length() - 1; i >= 0; i--) {
        bool f = true;
        for (int j = 0; j < (i + 1) / 2; j++) {
            if (s[j] != s[i - j]) {
                f = false;
                break;
            }
        }
        if (!f) {
            cout << i + 1 << "\n";
            return;
        }
    }
    cout << "-1\n";
}
int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}