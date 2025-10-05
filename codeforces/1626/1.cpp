#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        vector<int> count(26, 0);
        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;
        }

        string ans = "";
        for (int i = 0; i < 26; i++) {
            if (count[i] == 2) {
                ans = ans + (char)(i + 'a');
                ans = ans + (char)(i + 'a');
            } else if (count[i] == 1) {
                ans = ans + (char)(i + 'a');
            }
        }
        cout << ans << "\n";
    }

    return 0;
}