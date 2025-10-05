#include <bits/stdc++.h>

using namespace std;

inline bool isPowerOfTwo(long long int x) { return x && (!(x & (x - 1))); }

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long int n;
        cin >> n;
        bool flag = false;
        if (n % 2 == 0) {
            // while (n % 2 == 0) {
            //     n /= 2;
            // }
            // if (n == 1) {
            //     flag = false;
            // } else {
            //     true;
            // }
            if (isPowerOfTwo(n))
                flag = false;
            else
                flag = true;
        } else {
            flag = true;
        }

        if (flag) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}