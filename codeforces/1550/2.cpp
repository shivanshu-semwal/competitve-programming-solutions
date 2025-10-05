#include <bits/stdc++.h>
#define lli long long int
using namespace std;

lli count_uniq(string s) {
    lli count = 1;
    for (lli i = 1; i < s.length(); i++) {
        if (s[i] != s[i - 1]) count++;
    }
    return count;
}

lli get_count(lli i) {
    if (i == 1)
        return 1;
    else {
        i = i - (i % 2);
        i = i / 2 + 1;
        return i;
    }
}

int main() {
    lli t;
    cin >> t;
    while (t--) {
        lli a, b, n;
        cin >> n >> a >> b;
        string s;
        cin >> s;
        lli ans;
        if (a >= 0 && b >= 0) {
            ans = n * (a + b);
        } else if (a <= 0 && b >= 0) {
            ans = n * (a + b);
        } else if (a >= 0 && b <= 0) {
            lli temp = count_uniq(s);
            ans = n * a + get_count(temp) * b;
        } else if (a <= 0 && b <= 0) {
            lli temp = count_uniq(s);
            ans = n * a + get_count(temp) * b;
        }
        cout << ans << "\n";
    }
    return 0;
}