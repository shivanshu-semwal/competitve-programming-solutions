#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n, 0);
        vector<int> v(n + 1, 0);
        for (int i = 0; i < n; i++) cin >> a[i];

        int e = 0;
        for (int i = 0; i < n; i++) v[a[i]]++;
        for (int i = 0; i < n; i++)
            if (v[i] > 0) e = i;

        int z = 0, ans = 1;
        for (int i = 1; i <= e; i++) {
            if (v[i] == 0)
                z++;
            else if (v[i] == 1)
                continue;
            else {
                if (z >= v[i] - 1)
                    z -= v[i] - 1;
                else {
                    ans = max(ans, v[i] - z);
                    z = 0;
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}