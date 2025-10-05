#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long int n;
        cin >> n;
        const int a = 2020, b = 2021;
        if (n < b) {
            cout << "NO\n";
            continue;
        }
        bool flag = false;
        for (int i = 0; i <= n / b; i++) {
            if ((n - i * b) % a == 0) {
                flag = true;
                break;
            }
        }
        if (flag) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}