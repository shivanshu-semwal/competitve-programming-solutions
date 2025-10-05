#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n == 3) {
            cout << "3 2 1\n"
                 << "1 3 2\n"
                 << "3 1 2\n";
            continue;
        }
        int x = n;

        // 4 3 2 1
        // 3 2 1 4
        // 2 1 4 3
        // 1 4 3 2

        for (int i = n; i >= 1; i--) {
            cout << i << " ";
        }
        cout << "\n";

        for (int k = 1; k < n; k++) {
            for (int i = n - k; i >= 1; i--) cout << i << " ";
            for (int i = n; i > n - k; i--) cout << i << " ";
            cout << "\n";
        }
    }
    return 0;
}