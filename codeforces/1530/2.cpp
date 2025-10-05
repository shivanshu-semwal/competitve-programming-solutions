#include <bits/stdc++.h>
#define lli long long int

using namespace std;

int main() {
    lli t;
    cin >> t;
    while (t--) {
        lli h, w;
        cin >> h >> w;
        int a[h][w];
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                a[i][j] = 0;
            }
        }

        // top row fill with 101010101...
        for (int i = 0; i < w; i += 2) {
            a[0][i] = 1;
        }

        // fill the last row
        if (h > 2) {
            for (int i = 0; i < w; i += 2) {
                a[h - 1][i] = 1;
            }
        }

        // fill left column
        for (int i = 2; i < h - 2; i += 2) {
            a[i][0] = 1;
        }

        // fill right column
        if (w > 2) {
            for (int i = 2; i < h - 2; i += 2) {
                a[i][w - 1] = 1;
            }
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cout << a[i][j];
            }
            cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}