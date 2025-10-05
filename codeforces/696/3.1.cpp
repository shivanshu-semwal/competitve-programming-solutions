#include <bits/stdc++.h>
#define lli long long
#define test  \
    int t;    \
    cin >> t; \
    while (t--)

using namespace std;
void solve() {

    // 2 n size of the array
    int n;
    cin >> n;
    n *= 2;
    int a[n];


    map<int, int> m; // a map of if a element is present or not

    // input
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // sort
    sort(a, a + n);

    vector<pair<int, int>> v; // no which come together


    for (int i = 0; i < n - 1; i++) {
        m.clear(); // clear the map
        v.clear();
        for (int j = 0; j < n; j++)
            m[a[j]]++;
        int x = a[n - 1];
        v.push_back({a[n - 1], a[i]});
        m[a[i]]--;
        m[a[n - 1]]--;
        for (int j = n - 2; j >= 0; j--) {
            int l = x - a[j];
            if (m[a[j]]) {
                m[a[j]]--;
                if (m[l]) {
                    v.push_back({a[j], l});
                    m[l]--;
                    x = a[j];
                } else
                    break;
            }
        }
        if (v.size() == n / 2) { // if all numbers were removed
            cout << "YES\n";
            cout << a[n - 1] + a[i] << '\n';
            for (int i = 0; i < n / 2; i++)
                cout << v[i].first << " " << v[i].second << '\n';
            return;
        }
    }

    // if none of the numbers satisfied the cases
    cout << "NO\n";
}
int main() {
    // input
    test {
        // solve for each case
        solve();
    }
    return 0;
}