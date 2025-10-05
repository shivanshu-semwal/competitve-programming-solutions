#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) cin >> v[i];

    for (int i = 1; i < n; i++) {
        v[i] = v[i] + ((i % 2 == 0) ? -v[0] : +v[0]);
        v[i] = v[i] % n;
        if (v[i] < 0) {
            v[i] = (v[i] + n) % n;
        }
        if (v[i] != i) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}