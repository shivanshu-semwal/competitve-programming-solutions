#include <bits/stdc++.h>

#define lli long long int

using namespace std;

bool finds(string s, string t, int i, int j, bool dir) {
    
    // return false;
    if (j >= t.size()) return true;
    if (i >= s.size()) return false;
    if (i < 0) return false;

    if (s[i] == t[j]) {
        if (dir) {
            bool forw = finds(s, t, i + 1, j + 1, true);
            if (forw) {
                return true;
            }
        }
        bool back = finds(s, t, i - 1, j + 1, false);
        return back;
    } else {
        return false;
    }
}

void solve(string s, string t) {
    // vector<int> a(28, 0);
    vector<int> b;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == t[0]) {
            b.push_back(i);
        }
    }
    if(b.empty()){
        cout << "NO\n";
        return;
    }
    for (int i : b) {
        // cout << "i: " << i << "\n";
        // cout << s << " " << t << " " << i << " " << 0 << "\n";
        bool isPresent = finds(s, t, i, 0, true);
        if (isPresent) {
            cout << "YES\n";
            return;
        }
    }
    // cout << endl;
    cout << "NO\n";
}

int main() {
    lli t;
    cin >> t;
    while (t--) {
        string s, t;
        cin >> s >> t;
        solve(s, t);
    }
    return 0;
}