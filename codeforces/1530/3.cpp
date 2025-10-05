#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void print_vec(vector<int> v) {
    for (auto i : v) {
        cout << i << " ";
    }
    cout << "\n";
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<int> a;
        vector<int> b;
        vector<int> aa;
        vector<int> bb;
        for (ll i = 0; i < n; i++) {
            ll temp;
            cin >> temp;
            a.push_back(temp);
        }
        for (ll i = 0; i < n; i++) {
            ll temp;
            cin >> temp;
            b.push_back(temp);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        // sum array
        aa.push_back(0);
        bb.push_back(0);
        for (ll i = 1; i <= n; i++) {
            aa.push_back(aa[i - 1] + a[i - 1]);
            bb.push_back(bb[i - 1] + b[i - 1]);
        }

        // cout << "a: ";
        // print_vec(a);
        // cout << "b: ";
        // print_vec(b);
        // cout << "aa: ";
        // print_vec(aa);
        // cout << "bb: ";
        // print_vec(bb);

        ll nn = n - (ll)(n / 4);
        ll ascore = aa[n] - aa[n - nn];
        ll bscore = bb[n] - bb[n - nn];
        // cout << "nn: " << nn << "\n";
        // cout << "ascore: " << ascore << "\n";
        // cout << "bscore: " << bscore << "\n";
        if (ascore >= bscore) {
            cout << "0\n";
        } else {
            ll i;
            for (i = 1;; i++) {
                ll nnn = n + i;
                nn = nnn - (ll)(nnn / 4);
                // cout << "nn: " << nn << "\n";

                if (n < nn) {
                    bscore = bb[n];
                } else {
                    bscore = bb[n] - bb[n - nn];
                }
                // bscore = bb[n] - bb[n - nn];

                nn -= i;
                ascore = aa[n] - aa[n - nn] + 100 * i;

                // cout << "ascore: " << ascore << "\n";
                // cout << "bscore: " << bscore << "\n";
                // cout << "i: " << i << "\n";
                if (ascore >= bscore) {
                    cout << i << "\n";
                    break;
                }
            }
            // cout << i << "\n";
        }
    }
    return 0;
}