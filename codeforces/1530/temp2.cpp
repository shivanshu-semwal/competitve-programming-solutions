#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, s1 = 0, s2 = 0;
        cin >> n;
        vector<long long> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        sort(a.begin(), a.end(), greater<long long>());
        sort(b.begin(), b.end(), greater<long long>());

        for (int i = 0; i < n - n / 4; ++i) {
            s1 += a[i];
            s2 += b[i];
        }
        
        long long mx = 100;
        if (s1 >= s2)
            cout << 0 << endl;
        else {
            long long c = n;
            long long v = n - n / 4 - 1;
            long long r = n - n / 4;
            long long res = 0;
            long long test = n / 4;
            while (s1 < s2) {
                ++res;
                if ((res + n) % 4 == 0) {
                    if (v >= 0) {
                        s1 += 100;
                        s1 -= a[v--];
                    }
                } else {
                    if (r < n) s2 += b[r++];
                    s1 += 100;
                }
                if (v < 0 && r >= n && (res + n) % n == 4) break;
            }
            if (s1 < s2) {
                long long x = (s2 - s1 + 100 - 1) / 100;
                res += x + (x / 4);
            }
            cout << res << endl;
        }
    }
}