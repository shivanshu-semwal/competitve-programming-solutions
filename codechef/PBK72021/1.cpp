#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            for(int j=0;j<i;j++){
                cout << "_";
            }
            for(int j=0;j<n-i;j++){
                char c = 'A' + j;
                cout << c;
            }
            cout << "\n";
        }
    }
    return 0;
}