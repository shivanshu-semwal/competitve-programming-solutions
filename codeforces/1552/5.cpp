#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int mod = 998244353;

int main() {
    ll n;
    cin >> n;

    vector<pair<int, pair<int, bool>>> m;
    // unordered_map<int, pair<int, bool>> m;

    int N = 0;
    while (n--) {
        int x, y, s;
        cin >> x >> y >> s;
        N = x;
        m.push_back({x, {y, s}});
    }

    vector<int> dp(N + 2, 0);

    vector<int> sum;
    int s = 0;
    int j = 0;
    for (int i = 1; i < N + 2; i++) {
        if (j < m.size() && i == m[j].first) {
            if (m[j].second.second) {
                dp[i] = dp[i - 1] +
                        (m[j].first - m[j].second.first) +
                    ;
            } else {
            }

            sum.push_back(s);
        } else {
            dp[i] = (1 + dp[i - 1]) % mod;
        }
    }

    cout << dp[N + 1] % mod;
    return 0;
}