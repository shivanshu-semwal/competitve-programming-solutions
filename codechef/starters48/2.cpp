#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        n %= 2;
        m %= 2;

        if (n % 2 == 0 && m % 2 == 0)
            cout << "0\n";
        else {
            if (n % 2 == 0) {
                cout << n << "\n";
            } else if (m % 2 == 0) {
                cout << m << "\n";
            } else {
                cout << (n - 1 + m - 1 + 1) << endl;
            }
        }
    }
    return 0;
}