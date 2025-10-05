#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        bool r = true;
        bool b = true;
        bool g = true;
        bool flag = true;
        for (int i = 0; i < 6; i++) {
            char c = s[i];
            if (c == 'B' && b) { flag = false; break; }
            if (c == 'R' && r) { flag = false; break; }
            if (c == 'G' && g) { flag = false; break; }
            if (c == 'g') g = false;
            if (c == 'r') r = false;
            if (c == 'b') b = false;
        }

        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}