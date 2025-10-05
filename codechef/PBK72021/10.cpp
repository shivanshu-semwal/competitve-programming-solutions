#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int k = -1;
        int pos = (n + 1) / 2;
        bool dot = false;
        for (int i = 0; i < n; i++) {
            dot = true;
            for (int j = 1; j <= n; j++) {
                if (dot && j == pos) {
                    cout << ".";
                    pos += k;
                    if (pos == 1 || pos == n) k *= -1;
                    dot = false;
                } else {
                    cout << "#";
                }
            }
            cout << "\n";
        }
    }
    return 0;
}