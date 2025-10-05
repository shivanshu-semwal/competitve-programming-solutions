#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main() {
    ll t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<char> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        vector<char> v1(v);
        sort(v.begin(), v.end());
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] != v1[i]) count++;
        }
        cout << count << "\n";
    }
    return 0;
}