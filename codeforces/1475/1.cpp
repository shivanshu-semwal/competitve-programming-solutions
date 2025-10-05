#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long int n;
        cin >> n;
        bool flag = false;
        if (n % 2 == 0) {
            for (long long int i = 2; i * i <= n; i++) {
                if (n % i == 0) {
                    if (i % 2 == 0) {
                        n /= i;
                    } else {
                        flag = true;
                        break;
                    }
                }
            }
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