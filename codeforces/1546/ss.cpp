#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define scan(any) \
    for (auto &i : any) cin >> i;
#define print(any) \
    for (auto i : any) cout << i << " ";
#define endl '\n'
#define pb push_back
#define vll vector<ll>
#define vvll vector<vll>
#define f(i, x, y) for (i = x; i < y; i++)
#define INF LLONG_MAX
#define s(x) sort(x.begin(), x.end())
#define all(v) v.begin(), v.end()
#define p2(n, x) cout << fixed << setprecision(x) << n << endl;
#define pll pair<ll, ll>
#define mll map<ll, ll>
#define ff first
#define ss second
#define blt(x) __builtin_popcount(x)
#define pi 2 * asin(1.0)

void solve() {
    ll i, j, k, n;
    cin >> n;
    vector<ll> v(n);
    scan(v);

    map<ll, ll> m1, m2;

    f(i, 0, n) {
        if (i % 2) {
            m1[v[i]]++;
        } else {
            m2[v[i]]++;
        }
    }

    sort(v.begin(), v.end());
    
    f(i, 0, n) {
        if (i % 2) {
            if (m1[v[i]] <= 0) {
                cout << "NO\n";
                return;
            }
            m1[v[i]]--;
        } else {
            if (m2[v[i]] <= 0) {
                cout << "NO\n";
                return;
            }
            m2[v[i]]--;
        }
    }
    cout << "YES\n";
}

int main() {
// #ifndef ONLINE_JUDGE
//     freopen("E:/Programming/input.txt", "r", stdin);
//     freopen("E:/Programming/output.txt", "w", stdout);
// #endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}