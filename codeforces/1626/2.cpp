#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        lli n = s.length();
        lli a, b, c, c2, i, first;
        bool flag = false;
        for (i = 0; i < n - 1; i++) {
            a = s[i] - '0';
            b = s[i + 1] - '0';
            c = a + b;
            // c2 = a * 10 + b;
            if (c >= 10) {
                first = i;
                flag = true;
            }
        }

        if (flag) {
            a = s[first] - '0';
            b = s[first + 1] - '0';
            c = a + b;
            cout << s.substr(0, first);
            cout << c;
            if (first + 2 < n) cout << s.substr(first + 2, n);
        } else {
            a = s[0] - '0';
            b = s[1] - '0';
            c = a + b;
            cout << c;
            if (2 < n) cout << s.substr(2, n);
        }
        cout << "\n";
    }
    return 0;
}